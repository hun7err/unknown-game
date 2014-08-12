#include "../../include/Core/Engine.hpp"
#include "../../include/Windowing/WindowingSystem.hpp"
#include "../../include/Graphics/GraphicsSystem.hpp"

int WINAPI WinMain( HINSTANCE InstanceHandle, HINSTANCE PreviousInstanceHandle, LPSTR lpCmdLine, int nCmdShow )
{
	Hikari::Engine *pEngine = new Hikari::Engine();
	pEngine->Initialize( InstanceHandle, nCmdShow, lpCmdLine );

	Hikari::WindowingSystem *pWindowingSystem = new Hikari::WindowingSystem();
	Hikari::GraphicsSystem *pGraphicsSystem = new Hikari::GraphicsSystem();

	pEngine->Add(pWindowingSystem);
	pEngine->Add(pGraphicsSystem);

	pEngine->MainLoop();

	delete pWindowingSystem;
	delete pGraphicsSystem;
	delete pEngine;

	return 0;
}
