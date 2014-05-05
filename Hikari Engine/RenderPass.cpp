#include "RenderPass.hpp"
#include "Exception.hpp"

Hikari::RenderPass::RenderPass(D3D11_VIEWPORT viewport)
{
	m_renderTargetViewport = viewport;

	m_pRenderTargets = new std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> > ();
}

Hikari::RenderPass::~RenderPass()
{
	delete m_pRenderTargets;
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

D3D11_VIEWPORT Hikari::RenderPass::renderTargetViewport(unsigned int index)
{
	if(m_pRenderTargetViewports == NULL)
	{
		throw new Exception("m_pRenderTargetViewports is not initialized in RenderPass::renderTargetViewport(unsigned int)", "NullPointerException");
	}

	if(index >= m_pRenderTargetViewports->size())
	{
		throw new Exception("Invalid element index in RenderPass::renderTargetViewport(unsigned int)", "InvalidElementAccessException");
	}

	return m_pRenderTargetViewports->at(index);
}

std::vector<ID3D11RenderTargetView*> Hikari::RenderPass::getRenderTargetViews(void)
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

void Hikari::RenderPass::addRenderTarget(ID3D11Texture2D* pTexture, ID3D11RenderTargetView* pRenderTarget)
{
	if(pRenderTarget == NULL)
	{
		throw new Exception("Nieprawidlowy wskaznik do celu w addRenderTarget", "InvalidPointerException");
	}

	if(m_pRenderTargets == NULL)
	{
		throw new Exception("Nieprawidlowy wskaznik do kontenera celow w addRenderTarget", "InvalidPointerException");
	}

	m_pRenderTargets->push_back(std::make_pair(pRenderTarget, pTexture));
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

D3D11_VIEWPORT Hikari::RenderPass::viewport(void)
{
	return m_renderTargetViewport;
}

void Hikari::RenderPass::viewport(D3D11_VIEWPORT viewport)
{
	m_renderTargetViewport = viewport;
}
