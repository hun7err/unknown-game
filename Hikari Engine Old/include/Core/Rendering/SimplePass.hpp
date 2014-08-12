#ifndef __SIMPLE_PASS_HPP__
#define __SIMPLE_PASS_HPP__

#include "../../Core/Rendering/RenderPass.hpp"

namespace Hikari
{
	class SimplePass : public RenderPass
	{
		public:
			SimplePass() : RenderPass() {}

			void run(RenderPass* pRenderTargets);

			~SimplePass();
	};
}

#endif // __SIMPLE_PASS_HPP__