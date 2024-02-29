#pragma once

#include <string>

namespace Nebula
{

    class Application;

    class NebulaEngine
    {

    public:

        //TODO - Store and Retrieve ArgC and ArgV elsewhere.
        void Initialize(int ArgC, char* ArgV[]);
        void Update();
        void Shutdown();

        template<typename T>
        T* CreateApplication(const std::string& WindowTitle, int Width, int Height, int Flags /* Change to WindowFlag int typedef */)
        {

            //  The input type is not derived from Nebula::Application.
            static_assert(std::is_base_of<Application, T>::value, "T must be a derived class of Nebula::Application.");

            T* NewApplication = new T();
            m_Application = NewApplication;

            return NewApplication;
        }

        Application* GetApplication() const
        {
            return m_Application;
        }

        bool IsRunning();

    private:

        Application* m_Application = nullptr;

    };

    extern NebulaEngine* GEngine;
}