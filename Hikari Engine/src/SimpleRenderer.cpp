#include "../include/SimpleRenderer.hpp"
#include "../include/SimplePass.hpp"
#include "../include/Managers/ObjectManager.hpp"
#include "../include/Engine.hpp"

#include <DirectXPackedVector.h>
#include <DirectXColors.h>

void Hikari::SimpleRenderer::setup(unsigned int width, unsigned int height)
{
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Height = (float)height;
	viewport.Width = (float)width;

	SimplePass* backbufferPass = new SimplePass();
	addRenderPass(backbufferPass);

	ID3D11Texture2D *pBackBufferTexture;
	ID3D11RenderTargetView *pBackBuffer;

	Hikari::Engine::d3dsystem()->swapChain()->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBufferTexture);
	Hikari::Engine::d3dsystem()->device()->CreateRenderTargetView(pBackBufferTexture, NULL, &pBackBuffer);
	pBackBufferTexture->Release();
	backbufferPass->addRenderTarget(pBackBufferTexture, pBackBuffer, viewport);
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
	Hikari::RenderPass* lastRenderPass = NULL;

	for(std::vector<RenderPass*>::iterator currentPass = m_RenderPasses.begin(); currentPass != m_RenderPasses.end(); ++currentPass)
	{
		std::vector<ID3D11RenderTargetView*> renderTargetViews = (*currentPass)->renderTargetViews();	// pobierz kontener RenderTargetView* odpowiadaj¹cy celom
		std::vector<D3D11_VIEWPORT> viewports = (*currentPass)->viewports();
		Hikari::Engine::d3dsystem()->deviceContext()->OMSetRenderTargets(renderTargetViews.size(), &renderTargetViews[0], NULL);	// ustaw cele pobrane wczeœniej (w przypadku > 1 celu automatycznie wykonane zostanie MTR -> Multi-Target Rendering)
		Hikari::Engine::d3dsystem()->deviceContext()->RSSetViewports(viewports.size(), &viewports[0]);	// ustaw viewport
	
		for(std::vector<ID3D11RenderTargetView*>::iterator currentTarget = renderTargetViews.begin(); currentTarget != renderTargetViews.end(); ++currentTarget)
		{
			Hikari::Engine::d3dsystem()->deviceContext()->ClearRenderTargetView(*currentTarget, (*currentPass)->clearColor());	// wyczyœæ cele
		}

		// tutaj by³o Hikari::ObjectManager::root()->draw();

		// breakpoint --v
		(*currentPass)->run(lastRenderPass);	// uruchom przejœcie renderera... ale co tu w³aœciwie powinno siê dziaæ? czy tu nie powinno byæ to draw() ?

		/*
		// test start
		UINT stride = sizeof(Vertex);
		UINT offset = 0;
		Hikari::Engine::d3dsystem()->deviceContext()->IASetVertexBuffers(0, 1, &pVBuffer, &stride, &offset);
		Hikari::Engine::d3dsystem()->deviceContext()->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		// test end
		*/
		lastRenderPass = *currentPass;	// przeka¿ wynik do nastêpnego etapu (przejœcia)
		// wyrysuj co trzeba

		// test start
		//Hikari::Engine::d3dsystem()->deviceContext()->Draw(3, 0);
		// test end
	}
	Hikari::Engine::d3dsystem()->swapChain()->Present(0, 0);
}
