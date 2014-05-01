#include "RenderPass.hpp"
#include "Exception.hpp"

Hikari::RenderPass::RenderPass()
{
	m_pRenderTargets = new std::vector<ID3D11RenderTargetView*> ();
}

Hikari::RenderPass::~RenderPass()
{
	delete m_pRenderTargets;
}

std::vector<ID3D11RenderTargetView*> * Hikari::RenderPass::getRenderTargets(void)
{
	return m_pRenderTargets;
}

Hikari::RenderPass& Hikari::RenderPass::setRenderTargets(std::vector<ID3D11RenderTargetView*> * pRenderTargets)
{
	if(pRenderTargets == NULL)
	{
		throw new Exception("Nieprawidlowy wskaznik do listy celow w setRenderTarget", "InvalidPointerException");
	}

	m_pRenderTargets = pRenderTargets;

	return *this;
}

Hikari::RenderPass& Hikari::RenderPass::addRenderTarget(ID3D11RenderTargetView* pRenderTarget)
{
	if(pRenderTarget == NULL)
	{
		throw new Exception("Nieprawidlowy wskaznik do celu w addRenderTarget", "InvalidPointerException");
	}

	if(m_pRenderTargets == NULL)
	{
		throw new Exception("Nieprawidlowy wskaznik do kontenera celow w addRenderTarget", "InvalidPointerException");
	}

	m_pRenderTargets->push_back(pRenderTarget);
}

Hikari::RenderPass& Hikari::RenderPass::removeRenderTarget(unsigned int index)
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
