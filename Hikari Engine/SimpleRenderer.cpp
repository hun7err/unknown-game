#include "SimpleRenderer.hpp"
#include <DirectXPackedVector.h>
#include <DirectXColors.h>
#include "SimplePass.hpp"

// test start

struct Vertex
{
	FLOAT X, Y, Z;
	DirectX::XMFLOAT4 Color;
};
// test end

void Hikari::SimpleRenderer::setup(unsigned int width, unsigned int height)
{
	// test start
	triangleShader = new D3D11ShaderProgram();	// ok
	triangleShader->setup(L"triangle_shader.hlsl");
	triangleShader->d3d11system(m_pD3D11System);	// ok
	triangleShader->entryPointNames("VShader", "PShader");	// ok

	triangleShader->compile();	// ok

	Vertex OurVertices[] = 
	{
		{0.0f, 0.5f, 0.0f, DirectX::XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f)},
		{0.45f, -0.5f, 0.0f, DirectX::XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f)},
		{-0.45f, -0.5f, 0.0f, DirectX::XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f)}
	};
	// vertex buffer i inne tego typu wrzuciæ w Object
	D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
	};
	ID3D11InputLayout *pLayout;

	m_pD3D11System->deviceContext()->VSSetShader(triangleShader->vertexShader(), 0, 0);
	m_pD3D11System->deviceContext()->PSSetShader(triangleShader->pixelShader(), 0, 0);

	m_pD3D11System->device()->CreateInputLayout(ied, 2, triangleShader->vertexShaderBlob()->GetBufferPointer(), triangleShader->vertexShaderBlob()->GetBufferSize(), &pLayout);

	m_pD3D11System->deviceContext()->IASetInputLayout(pLayout);

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));

	bd.Usage = D3D11_USAGE_DYNAMIC;                // write access access by CPU and GPU
	bd.ByteWidth = sizeof(Vertex) * 3;             // size is the VERTEX struct * 3
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;       // use as a vertex buffer
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;    // allow CPU to write in buffer

	m_pD3D11System->device()->CreateBuffer(&bd, NULL, &pVBuffer);

	D3D11_MAPPED_SUBRESOURCE ms;
	m_pD3D11System->deviceContext()->Map(pVBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &ms);
	memcpy(ms.pData, OurVertices, sizeof(OurVertices));
	m_pD3D11System->deviceContext()->Unmap(pVBuffer, NULL);

	// test_end

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

	m_pD3D11System->swapChain()->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBufferTexture);
	m_pD3D11System->device()->CreateRenderTargetView(pBackBufferTexture, NULL, &pBackBuffer);
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

	// test start
	triangleShader->cleanup();
	delete triangleShader;
	// test end
}

void Hikari::SimpleRenderer::render(void)
{
	Hikari::RenderPass* lastRenderPass = NULL;

	for(std::vector<RenderPass*>::iterator currentPass = m_RenderPasses.begin(); currentPass != m_RenderPasses.end(); ++currentPass)
	{
		std::vector<ID3D11RenderTargetView*> renderTargetViews = (*currentPass)->renderTargetViews();	// pobierz kontener RenderTargetView* odpowiadaj¹cy celom
		std::vector<D3D11_VIEWPORT> viewports = (*currentPass)->viewports();
		m_pD3D11System->deviceContext()->OMSetRenderTargets(renderTargetViews.size(), &renderTargetViews[0], NULL);	// ustaw cele pobrane wczeœniej (w przypadku > 1 celu automatycznie wykonane zostanie MTR -> Multi-Target Rendering)
		m_pD3D11System->deviceContext()->RSSetViewports(viewports.size(), &viewports[0]);	// ustaw viewport
	
		for(std::vector<ID3D11RenderTargetView*>::iterator currentTarget = renderTargetViews.begin(); currentTarget != renderTargetViews.end(); ++currentTarget)
		{
			// clearColor wywaliæ do renderTarget?

			m_pD3D11System->deviceContext()->ClearRenderTargetView(*currentTarget, (*currentPass)->clearColor());	// wyczyœæ cele
		}
		(*currentPass)->run(lastRenderPass);	// uruchom przejœcie renderera

		// test start
		UINT stride = sizeof(Vertex);
		UINT offset = 0;
		m_pD3D11System->deviceContext()->IASetVertexBuffers(0, 1, &pVBuffer, &stride, &offset);
		m_pD3D11System->deviceContext()->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		// test end

		lastRenderPass = *currentPass;	// przeka¿ wynik do nastêpnego etapu (przejœcia)
		// wyrysuj co trzeba

		// test start
		m_pD3D11System->deviceContext()->Draw(3, 0);
		// test end
	}
	m_pD3D11System->swapChain()->Present(0, 0);
}
