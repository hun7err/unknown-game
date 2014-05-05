#include "SimpleRenderer.hpp"
#include "SimplePass.hpp"
#include "Color.hpp"

void Hikari::SimpleRenderer::setup(unsigned int width, unsigned int height)
{
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Height = height;
	viewport.Width = width;

	SimplePass* backbufferPass = new SimplePass(viewport);
	ID3D11Texture2D *pBackBufferTexture;
	ID3D11RenderTargetView *pBackBuffer;

	m_pD3D11System->swapChain()->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBufferTexture);
	m_pD3D11System->device()->CreateRenderTargetView(pBackBufferTexture, NULL, &pBackBuffer);
	pBackBufferTexture->Release();
	backbufferPass->addRenderTarget(pBackBufferTexture, pBackBuffer);
}

void Hikari::SimpleRenderer::cleanup(void)
{
	for(auto currentPass = m_RenderPasses.begin(); currentPass != m_RenderPasses.end(); ++currentPass)
	{
		delete (*currentPass);
		(*currentPass) = NULL;
	}
}

void Hikari::SimpleRenderer::render(void)
{
	// jeszcze (tylko) viewport + kompilacja
	Hikari::RenderPass* lastRenderPass = NULL;
	static Hikari::Color clearColor(0.0f, 0.2f, 0.4f, 1.0f);

	for(std::vector<RenderPass*>::iterator currentPass = m_RenderPasses.begin(); currentPass != m_RenderPasses.end(); ++currentPass)
	{
		std::vector<ID3D11RenderTargetView*> renderTargetViews = (*currentPass)->getRenderTargetViews();	// pobierz kontener RenderTargetView* odpowiadaj¹cy celom
		m_pD3D11System->deviceContext()->OMSetRenderTargets(renderTargetViews.size(), &renderTargetViews[0], NULL);	// ustaw cele pobrane wczeœniej (w przypadku > 1 celu automatycznie wykonane zostanie MTR -> Multi-Target Rendering)
		m_pD3D11System->deviceContext()->RSSetViewports(1, (*currentPass)->viewport());
		
		for(std::vector<ID3D11RenderTargetView*>::iterator currentTarget = renderTargetViews.begin(); currentTarget != renderTargetViews.end(); ++currentTarget)
		{
			m_pD3D11System->deviceContext()->ClearRenderTargetView(renderTargetViews[currentTarget], clearColor.components());	// wyczyœæ cele
		}
		(*currentPass)->run(lastRenderPass);	// uruchom przejœcie renderera

		lastRenderPass = *currentPass;	// przeka¿ wynik do nastêpnego etapu (przejœcia)
		// wyrysuj co trzeba
	}

	m_pD3D11System->swapChain()->Present(0, 0);
}
