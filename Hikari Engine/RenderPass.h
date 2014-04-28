#ifndef __RENDER_PASS_H__
#define __RENDER_PASS_H__

#include <d3d11.h>
#include <vector>
#include <list>

namespace Hikari {
	/**
		\class	RenderPass
		\brief	(DEVEL! mo�e ulec du�ym zmianom) Pojedyncze przejscie renderera, metoda run() uruchamia proces renderingu
	*/
	class RenderPass {
		public:
			virtual RenderPass& run(std::list<RenderPass*> *renderTargets /** \brief wska�nik na list� cel�w (do ��czenia wielu etap�w)*/); //< uruchamia proces renderingu, zwraca *this aby robi� ci�g wywo�a�

			std::vector<ID3D11RenderTargetView*> * getRenderTargets();	//< pobiera list� cel�w
			RenderPass& setRenderTargets(std::vector<ID3D11RenderTargetView*> * pRenderTargets);	//< ustawia now� list� cel�w
			RenderPass& addRenderTarget(ID3D11RenderTargetView* pRenderTarget);	//< dodaje pojedynczy cel
			RenderPass& removeRenderTarget(unsigned int index); //< Usuwa pojedynczy element z listy cel�w

			RenderPass();
			virtual ~RenderPass();
		protected:
			std::vector<ID3D11RenderTargetView*> * m_pRenderTargets;
	};
}

#endif // __RENDER_PASS_H__