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

			void d3d11system(D3D11System* pD3D11System)
			{
				// walidacja!
				m_pD3D11System = pD3D11System;
			}

			D3D11System* d3d11system(void)
			{
				// walidacja!
				return m_pD3D11System;
			}

		protected:
			std::vector<RenderPass*> m_RenderPasses;
			D3D11System* m_pD3D11System;

			void addRenderPass(RenderPass* pass)
			{
				m_RenderPasses.push_back(pass);
			}
	};
}

#endif // __RENDERER_HPP__