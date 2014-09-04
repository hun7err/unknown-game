#include "../../include/Graphics/GraphicsSystem.hpp"
#include "../../include/Windowing/WindowingSystem.hpp"
#include "../../include/Core/Components/Size.hpp"
#include "../../include/Graphics/Renderers/BasicRenderer.hpp"

Hikari::GraphicsSystem::GraphicsSystem( void ) : System("Graphics")
{
	m_pD3D11SubSystem = nullptr;
	m_pRenderer = nullptr;
}

Hikari::GraphicsSystem::~GraphicsSystem( void )
{
	m_pD3D11SubSystem->GetSwapChain()->SetFullscreenState(false, nullptr);
	delete m_pD3D11SubSystem;
	m_pD3D11SubSystem = nullptr;
	delete m_pRenderer;
	m_pRenderer = nullptr;
}

void Hikari::GraphicsSystem::Init( Hikari::Engine *pEngine )
{
	m_pEngine = pEngine;
	WindowingSystem *pWindowingSystem = ( WindowingSystem* )( pEngine->GetSystem("Windowing") );
	Hikari::Window *pWindow = pWindowingSystem->GetMainWindow();

	m_pD3D11SubSystem = new Direct3D11SubSystem( );
	m_pD3D11SubSystem->SetWindowHandle( pWindowingSystem->GetMainWindowHandle() );
	m_pD3D11SubSystem->SetResolution( pWindow->GetSize() );
	m_pD3D11SubSystem->SetFullscreen( false );	// tak wstêpnie.

	m_pD3D11SubSystem->Init();

	m_pRenderer = new BasicRenderer();
	m_pRenderer->Init( m_pD3D11SubSystem->GetDevice(), (unsigned int)pWindow->GetSize().GetU(), (unsigned int)pWindow->GetSize().GetV() );
}

void Hikari::GraphicsSystem::Update( float dt )
{
	m_pRenderer->Render( m_pD3D11SubSystem->GetDeviceContext(), m_pD3D11SubSystem->GetSwapChain() );
}
