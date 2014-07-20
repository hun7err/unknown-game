#include "RenderPass.hpp"
#include "Exception.hpp"
#include <DirectXColors.h>

Hikari::RenderPass::RenderPass()
{
	m_ClearColor = DirectX::Colors::Black;
	m_pRenderTargets = new std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> > ();
	m_pRenderTargetViewports = new std::vector<D3D11_VIEWPORT> ();
}

Hikari::RenderPass::~RenderPass()
{
	delete m_pRenderTargets;
	m_pRenderTargets = NULL;
	delete m_pRenderTargetViewports;
	m_pRenderTargetViewports = NULL;
}

void Hikari::RenderPass::run(Hikari::RenderPass* pRenderTargets)
{
}

std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> > * Hikari::RenderPass::renderTargets(void)
{
	return m_pRenderTargets;
}

std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> Hikari::RenderPass::renderTarget(unsigned int index)
{
	if(m_pRenderTargets == NULL)
	{
		throw new Exception("m_pRenderTargets is not initialized in RenderPass::renderTarget(unsigned int)", "NullPointerException");
	}

	if(index >= m_pRenderTargets->size())
	{
		throw new Exception("Nieprawidlowy indeks elementu w renderTarget", "InvalidElementAccessException");
	}

	return m_pRenderTargets->at(index);

	/*for(std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> >::iterator currentTarget = m_pRenderTargets->begin(); currentTarget != m_pRenderTargets->end(); ++currentTarget)
	{
		if(currentTarget == m_pRenderTargets->begin() + index)
		{
			return *currentTarget;
		}
	}*/

	//return std::make_pair<ID3D11RenderTargetView*, ID3D11Texture2D*>(NULL, NULL);
}

std::vector<ID3D11RenderTargetView*> Hikari::RenderPass::renderTargetViews(void)
{
	if(m_pRenderTargets == NULL)
	{
		throw new Exception("m_pRenderTargets is not initialized in RenderPass::getRenderTargetViews(void)", "NullPointerException");
	}

	std::vector<ID3D11RenderTargetView*> renderTargetViews;

	for(auto currentRenderTarget = m_pRenderTargets->begin(); currentRenderTarget != m_pRenderTargets->end(); ++currentRenderTarget)
	{
		renderTargetViews.push_back((*currentRenderTarget).first);
	}

	return renderTargetViews;
}

void Hikari::RenderPass::renderTargets(std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> > * pRenderTargets)
{
	if(pRenderTargets == NULL)
	{
		throw new Exception("Nieprawidlowy wskaznik do listy celow w setRenderTarget", "InvalidPointerException");
	}

	m_pRenderTargets = pRenderTargets;
}

void Hikari::RenderPass::addRenderTarget(ID3D11Texture2D* pTexture, ID3D11RenderTargetView* pRenderTarget, D3D11_VIEWPORT renderTargetViewport)
{
	if(pRenderTarget == NULL)
	{
		throw new Exception("Nieprawidlowy wskaznik do celu w addRenderTarget", "InvalidPointerException");
	}

	if(m_pRenderTargets == NULL)
	{
		throw new Exception("Nieprawidlowy wskaznik do kontenera celow w addRenderTarget", "InvalidPointerException");
	}

	if(m_pRenderTargetViewports == NULL)
	{
		throw new Exception("m_pRenderTargetViewports is not set in RenderPass::addRenderTarget(ID3D11Texture2D*,ID3D11RenderTargetView*,D3D11_VIEWPORT)", "NullPointerException");
	}

	m_pRenderTargets->push_back(std::make_pair(pRenderTarget, pTexture));
	m_pRenderTargetViewports->push_back(renderTargetViewport);
}

void Hikari::RenderPass::removeRenderTarget(unsigned int index)
{
	if(m_pRenderTargets == NULL)
	{
		throw new Exception("Nieprawidlowy wskaznik do kontenera celow w addRenderTarget", "InvalidPointerException");
	}

	if(index >= m_pRenderTargets->size())
	{
		throw new Exception("Nieprawidlowy indeks elementu w removeRenderTarget", "InvalidElementAccessException");
	}

	m_pRenderTargets->erase(m_pRenderTargets->begin() + index);
}

D3D11_VIEWPORT Hikari::RenderPass::viewport(unsigned int index)
{
	if(m_pRenderTargetViewports == NULL)
	{
		throw new Exception("m_pRenderTargetViewports is not set in RenderPass::viewport(unsigned int)", "NullPointerException");
	}

	if(index > m_pRenderTargetViewports->size())
	{
		throw new Exception("Invalid element of m_pRenderTargetViewports accessed in RenderPass::viewport(unsigned int)", "InvalidElementAccessException");
	}

	return m_pRenderTargetViewports->at(index);
}

std::vector<D3D11_VIEWPORT> Hikari::RenderPass::viewports(void)
{
	if(m_pRenderTargetViewports == NULL)
	{
		throw new Exception("m_pRenderTargetViewports is not set in RenderPass::viewports(void)", "NullPointerException");
	}

	return *m_pRenderTargetViewports;
}

DirectX::XMVECTORF32 Hikari::RenderPass::clearColor(void)
{
	return m_ClearColor;
}

void Hikari::RenderPass::clearColor(DirectX::XMVECTORF32 *newClearColor)
{
	m_ClearColor = *newClearColor;
}
