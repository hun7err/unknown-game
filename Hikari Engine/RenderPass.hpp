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

			/** \brief	Pobiera list� cel�w */
			std::vector<ID3D11RenderTargetView*> * getRenderTargets();
			/** \brief	Ustawia aktualn� list� cel�w */
			RenderPass& setRenderTargets(std::vector<ID3D11RenderTargetView*> * pRenderTargets /** \brief wska�nik na now� list� cel�w */);
			/** \brief	Dodaje pojedynczy cel */
			RenderPass& addRenderTarget(ID3D11RenderTargetView* pRenderTarget /** \brief element do dodania */);
			/** \brief	Usuwa pojedynczy element z listy cel�w */
			RenderPass& removeRenderTarget(unsigned int index /** \brief Indeks elementu, kt�ry ma zosta� usuni�ty */);


			RenderPass();
			/** \brief	Wirtualny destruktor m.in. zwalniajacy liste celow */
			virtual ~RenderPass();
		protected:
			std::vector<ID3D11RenderTargetView*> * m_pRenderTargets;
	};
}

#endif // __RENDER_PASS_H__