#include "../../include/Core/Engine.hpp"
#include "../../include/Windowing/WindowingSystem.hpp"
#include "../../include/Graphics/GraphicsSystem.hpp"

#include "../../include/Graphics/Assets/Geometry/Triangle.hpp"

int WINAPI WinMain( HINSTANCE InstanceHandle, HINSTANCE PreviousInstanceHandle, LPSTR lpCmdLine, int nCmdShow )
{
	Hikari::Engine *pEngine = new Hikari::Engine();
	pEngine->Initialize( InstanceHandle, nCmdShow, lpCmdLine );

	Hikari::WindowingSystem *pWindowingSystem = new Hikari::WindowingSystem();
	Hikari::GraphicsSystem *pGraphicsSystem = new Hikari::GraphicsSystem();

	Hikari::Geometry::Triangle *pTriangleGeometry = new Hikari::Geometry::Triangle(
			"triangle",
			Hikari::Vector3( 0.0f, 0.5f, 1.0f ),
			Hikari::Vector3( 0.55f, -0.5f, 1.0f ),
			Hikari::Vector3( -0.55f, -0.5f, 1.0f )
		);

	Hikari::Object *pTriangle = new Hikari::Object( "triangle" );
	pTriangle->AddComponent( pTriangleGeometry );

	pEngine->GetWorld()->GetActiveScene()->Add( pTriangle );

	pEngine->Add(pWindowingSystem);
	pEngine->Add(pGraphicsSystem);

	pEngine->MainLoop();

	delete pWindowingSystem;
	delete pGraphicsSystem;
	delete pEngine;

	return 0;
}
