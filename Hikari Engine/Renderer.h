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
			/** \brief	Metoda wirtualna odpowiadaj¹ca za odpalenie kolejnych passów renderera */
			virtual bool render() = 0;

		protected:
			std::vector<RenderPass*> m_RenderPasses;
	};
}

#endif // __RENDERER_H__