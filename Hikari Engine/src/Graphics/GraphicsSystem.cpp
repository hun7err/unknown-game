#include "../../include/Graphics/GraphicsSystem.hpp"
#include "../../include/Windowing/WindowingSystem.hpp"
#include "../../include/Core/Components/Size.hpp"

Hikari::GraphicsSystem::GraphicsSystem( void ) : System("Graphics")
{
	m_pD3D11SubSystem = nullptr;
}

Hikari::GraphicsSystem::~GraphicsSystem( void )
{
	m_pD3D11SubSystem->GetSwapChain()->SetFullscreenState(false, nullptr);
	delete m_pD3D11SubSystem;
}

void Hikari::GraphicsSystem::Init( Hikari::Engine *pEngine )
{
	m_pEngine = pEngine;
	WindowingSystem *pWindowingSystem = ( WindowingSystem* )( pEngine->GetSystem("Windowing") );
	Components::Size *pWindowSize = (Components::Size*)pWindowingSystem->GetMainWindow()->GetComponent("Size");

	m_pD3D11SubSystem = new Direct3D11SubSystem( );
	m_pD3D11SubSystem->SetWindowHandle( pWindowingSystem->GetMainWindowHandle() );
	m_pD3D11SubSystem->SetResolution( pWindowSize->GetValue() );
	m_pD3D11SubSystem->SetFullscreen( false );	// tak wstêpnie.

	m_pD3D11SubSystem->Init();
}

void Hikari::GraphicsSystem::Update( float dt )
{
}
