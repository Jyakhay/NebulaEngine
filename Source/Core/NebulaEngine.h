#pragma once

namespace Nebula
{
    class NebulaEngine
    {

    public:

        void Initialize();
        void Update();
        void Shutdown();

        bool IsRunning() const { return true; }

    private:


    };

    extern NebulaEngine* GEngine;
}