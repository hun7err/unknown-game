#include "../../../include/Graphics/Renderers/Renderer.hpp"

Hikari::Renderer::Renderer( void )
{
}

Hikari::Renderer::~Renderer( void )
{
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
