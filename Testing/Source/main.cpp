#include "Core/NebulaEngine.h"

#include "Core/Application.h"
#include "Graphics/Renderer.h"
#include "Math/Vector.h"

int main(int argc, char* argv[])
{
	if (Nebula::GEngine->Initialize(argc, argv))
	{
		Nebula::GEngine->CreateApplication<Nebula::Application>("Hello", 640, 480, 0);

		while (Nebula::GEngine->IsRunning())
		{
			Nebula::GEngine->Update();
		}
	}

	Nebula::GEngine->Shutdown();

}
