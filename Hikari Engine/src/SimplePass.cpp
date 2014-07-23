#include "../include/SimplePass.hpp"
#include "../include/Managers/ObjectManager.hpp"

void Hikari::SimplePass::run(Hikari::RenderPass* pRenderTargets)
{
	Hikari::ObjectManager::root()->draw();
}

Hikari::SimplePass::~SimplePass()
{
	{
		for(std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> >::iterator currentTarget = m_pRenderTargets->begin(); currentTarget != m_pRenderTargets->end(); ++currentTarget)
		{
			(*currentTarget).first->Release();
		}
	}
}
