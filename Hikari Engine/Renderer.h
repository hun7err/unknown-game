#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <vector>
#include "RenderPass.h"

namespace Hikari {
	/**
		\class	Renderer
		\brief	Klasa odpowiadaj¹ca za wygenerowanie obrazu
	*/
	class Renderer {
		public:
			virtual void render() = 0;

		protected:
			std::vector<RenderPass*> m_RenderPasses;
	};
}

#endif // __RENDERER_H__