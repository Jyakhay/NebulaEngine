#include "Core/NebulaEngine.h"

#include "Core/Application.h"

int main(int argc, char* argv[])
{
	Nebula::GEngine->Initialize(argc, argv);

	Nebula::GEngine->CreateApplication<Nebula::Application>("Hello", 640, 480, 0);
	Nebula::Window* Test = Nebula::Window::CreateWindow("TestWindow", 640, 480, 0);

	while(Nebula::GEngine->IsRunning())
	{
		Nebula::GEngine->Update();
	}

	Nebula::GEngine->Shutdown();

}
