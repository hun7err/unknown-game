#include "../../include/Graphics/Renderer.hpp"

Hikari::Renderer::Renderer( void )
{
	m_RenderTargetCount = 1;

	m_pRenderTargetViews = new ID3D11RenderTargetView*  [ m_RenderTargetCount ];
	m_pViewports = new D3D11_VIEWPORT  [ m_RenderTargetCount ];
	m_pTextures = new Assets::Textures::Texture2D  [ m_RenderTargetCount ];

	m_pTextures[0].Asset::SetID("BackBuffer");
}

Hikari::Renderer::~Renderer( void )
{
	delete [] m_pRenderTargetViews;
	m_pRenderTargetViews = nullptr;
	delete [] m_pTextures;
	m_pTextures = nullptr;
	delete [] m_pViewports;
	m_pViewports = nullptr;
}

int Hikari::Renderer::Init( ID3D11Device *pDevice, unsigned int width, unsigned int height )
{
	m_pTextures[0].Create( pDevice, width, height );
	
	ZeroMemory(m_pViewports, sizeof(D3D11_VIEWPORT));
	m_pViewports[0].TopLeftX = 0;
	m_pViewports[0].TopLeftY = 0;
	m_pViewports[0].Height = (float)height;
	m_pViewports[0].Width = (float)width;

	m_pRenderTargetViews[0] = m_pTextures[0].GetRenderTargetView();

	return 0;
}

void Hikari::Renderer::Render( ID3D11DeviceContext *pDeviceContext, IDXGISwapChain *pSwapChain )
{
	pDeviceContext->OMSetRenderTargets( m_RenderTargetCount, m_pRenderTargetViews, nullptr );
	pDeviceContext->RSSetViewports( m_RenderTargetCount, m_pViewports );

	for( unsigned int currentRenderTarget = 0; currentRenderTarget < m_RenderTargetCount; ++currentRenderTarget )
	{
		pDeviceContext->ClearRenderTargetView( m_pRenderTargetViews[ currentRenderTarget ], m_pTextures[ currentRenderTarget ].GetClearColor() );
	}

	// tutaj draw() obiektów, czyli draw() na root node

	pSwapChain->Present( 0, 0 );
}
