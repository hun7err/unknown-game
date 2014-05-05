#ifndef __RENDER_PASS_HPP__
#define __RENDER_PASS_HPP__

#include <vector>
#include <list>
#include <d3d11.h>

namespace Hikari {
	/**
		\class	RenderPass
		\brief	(DEVEL! mo¿e ulec du¿ym zmianom) Pojedyncze przejscie renderera, metoda run() uruchamia proces renderingu
	*/
	class RenderPass {
		public:
			virtual void run(RenderPass* pRenderTargets /** \brief wskaŸnik na listê celów (do ³¹czenia wielu etapów)*/); //< uruchamia proces renderingu, zwraca *this aby robiæ ci¹g wywo³añ

			/** \brief	Pobiera listê celów */
			std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> > * renderTargets(void);
			std::vector<ID3D11RenderTargetView*> getRenderTargetViews(void);
			std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> renderTarget(unsigned int index);
			/** \brief	Ustawia aktualn¹ listê celów */
			void renderTargets(std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> > * pRenderTargets /** \brief wskaŸnik na now¹ listê celów */);
			/** \brief	Dodaje pojedynczy cel */
			void addRenderTarget(ID3D11Texture2D* pTexture /** \brief tekstura */, ID3D11RenderTargetView* pRenderTarget /** \brief render target utworzony z tekstury */);
			/** \brief	Usuwa pojedynczy element z listy celów */
			void removeRenderTarget(unsigned int index /** \brief Indeks elementu, który ma zostaæ usuniêty */);
			D3D11_VIEWPORT viewport(void);
			void viewport(D3D11_VIEWPORT viewport);

			RenderPass(D3D11_VIEWPORT viewport);
			/** \brief	Wirtualny destruktor m.in. zwalniajacy liste celow */
			virtual ~RenderPass();

		protected:
			std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> > * m_pRenderTargets;
			D3D11_VIEWPORT m_renderTargetViewport;
	};
}

#endif // __RENDER_PASS_HPP__