#ifndef __SIMPLE_PASS_HPP__
#define __SIMPLE_PASS_HPP__

#include "RenderPass.hpp"

namespace Hikari {
	class SimplePass : public RenderPass {
		public:
			SimplePass(D3D11_VIEWPORT viewport) : RenderPass(viewport) {}

			void run(std::list<RenderPass*> *renderTargets)
			{
				// placeholder
			}

			~SimplePass()
			{
				for(std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> >::iterator currentTarget = m_pRenderTargets->begin(); currentTarget != m_pRenderTargets->end(); ++currentTarget)
				{
					(*currentTarget).first->Release();
				}
			}
	};
}

#endif // __SIMPLE_PASS_HPP__