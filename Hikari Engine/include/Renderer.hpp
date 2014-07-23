#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <vector>
#include "RenderPass.hpp"
#include "D3D11System.hpp"

namespace Hikari
{
	/**
		\class	Renderer
		\brief	Klasa odpowiadaj¹ca za wygenerowanie obrazu
	*/
	class Renderer
	{
		public:
			/** \brief	Metoda wirtualna odpowiadaj¹ca za odpalenie kolejnych passów renderera */
			virtual void setup(unsigned int width, unsigned int height) = 0;
			virtual void cleanup(void) = 0;
			virtual void render(void) = 0;
			
		protected:
			std::vector<RenderPass*> m_RenderPasses;

			void addRenderPass(RenderPass* pass)
			{
				m_RenderPasses.push_back(pass);
			}
	};
}

#endif // __RENDERER_HPP__