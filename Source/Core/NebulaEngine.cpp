#include "NebulaEngine.h"

#include "Application.h"
#include "Debug/Logger.h"
#include "Platform/FileSystem.h"

namespace Nebula
{

    void NebulaEngine::Initialize(int ArgC, char* ArgV[])
    {

        NEBULA_LOG(ELogSeverity::Neutral, "Initializing Engine...")

        FileSystem::m_ExecutablePath = ArgV[0];

    }

    void NebulaEngine::Update()
    {

        // Setup FPS limiting and DeltaTime

        if(m_Application)
        {
            m_Application->Update(0.0f);
        }

    }

    void NebulaEngine::Shutdown()
    {
        Logger::ExportLog();
    }

    bool NebulaEngine::IsRunning()
    {
        return m_Application && m_Application->IsRunning();
    }

    NebulaEngine* GEngine = new NebulaEngine();
}
