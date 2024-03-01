#include "NebulaEngine.h"

#include "Application.h"
#include "Debug/Logger.h"
#include "Platform/FileSystem.h"

#include <GLFW/glfw3.h>

namespace Nebula
{

    bool NebulaEngine::Initialize(int ArgC, char* ArgV[])
    {

        NEBULA_LOG(ELogSeverity::Neutral, "Initializing Engine...")

        FileSystem::m_ExecutablePath = ArgV[0];

        NEBULA_LOG(ELogSeverity::Neutral, "Initializing glfw.")
        if(!glfwInit())
        {
            const char* InitError;
            glfwGetError(&InitError);

            NEBULA_LOG(ELogSeverity::Error, "Failed to initialize glfw: {}", InitError)
        	return false;
        }

        return true;

    }

    void NebulaEngine::Update()
    {

        m_GameDeltaTime += m_EngineDeltaTime;
        const auto FrameStart = static_cast<float>(glfwGetTime());

        glfwPollEvents();

        if (m_GameDeltaTime >= 1.0f / m_FPS)
        {
            if (m_Application)
            {
                m_Application->Update(m_GameDeltaTime);
                m_Application->Render(m_GameDeltaTime);

                m_GameRunTime += m_GameDeltaTime;
            }

            m_GameDeltaTime = 0.0f;
        }

        const auto FrameEnd = static_cast<float>(glfwGetTime());
        m_EngineDeltaTime = FrameEnd - FrameStart;

    }

    void NebulaEngine::Shutdown()
    {
        NEBULA_LOG(ELogSeverity::Neutral, "Engine shutting down...")
        Logger::ExportLog();
    }

    bool NebulaEngine::IsRunning()
    {
        return m_Application && m_Application->IsRunning();
    }

    NebulaEngine* GEngine = new NebulaEngine();
}
