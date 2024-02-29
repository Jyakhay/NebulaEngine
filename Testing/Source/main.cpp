#include "Core/NebulaEngine.h"

int main(int argc, char* argv[])
{
	Nebula::GEngine->Initialize();

	while(Nebula::GEngine->IsRunning())
	{
		Nebula::GEngine->Update();
	}

	Nebula::GEngine->Shutdown();

}
