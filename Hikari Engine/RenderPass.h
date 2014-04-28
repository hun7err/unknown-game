#ifndef __RENDER_PASS_H__
#define __RENDER_PASS_H__

#include <d3d11.h>
#include <vector>
#include <list>

namespace Hikari {
	/**
		\class	RenderPass
		\brief	(DEVEL! mo¿e ulec du¿ym zmianom) Pojedyncze przejscie renderera, metoda run() uruchamia proces renderingu
	*/
	class RenderPass {
		public:
			virtual RenderPass& run(std::list<RenderPass*> *renderTargets /** \brief wskaŸnik na listê celów (do ³¹czenia wielu etapów)*/); //< uruchamia proces renderingu, zwraca *this aby robiæ ci¹g wywo³añ

			/** \brief	Pobiera listê celów */
			std::vector<ID3D11RenderTargetView*> * getRenderTargets();
			/** \brief	Ustawia aktualn¹ listê celów */
			RenderPass& setRenderTargets(std::vector<ID3D11RenderTargetView*> * pRenderTargets /** \brief wskaŸnik na now¹ listê celów */);
			/** \brief	Dodaje pojedynczy cel */
			RenderPass& addRenderTarget(ID3D11RenderTargetView* pRenderTarget /** \brief element do dodania */);
			/** \brief	Usuwa pojedynczy element z listy celów */
			RenderPass& removeRenderTarget(unsigned int index /** \brief Indeks elementu, który ma zostaæ usuniêty */);


			RenderPass();
			/** \brief	Wirtualny destruktor m.in. zwalniajacy liste celow */
			virtual ~RenderPass();
		protected:
			std::vector<ID3D11RenderTargetView*> * m_pRenderTargets;
	};
}

#endif // __RENDER_PASS_H__