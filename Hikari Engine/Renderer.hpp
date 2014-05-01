#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <vector>
#include "RenderPass.hpp"

namespace Hikari {
	/**
		\class	Renderer
		\brief	Klasa odpowiadaj�ca za wygenerowanie obrazu
	*/
	class Renderer {
		public:
			/** \brief	Metoda wirtualna odpowiadaj�ca za odpalenie kolejnych pass�w renderera */
			virtual bool render() = 0;

		protected:
			std::vector<RenderPass*> m_RenderPasses;
	};
}

#endif // __RENDERER_HPP__