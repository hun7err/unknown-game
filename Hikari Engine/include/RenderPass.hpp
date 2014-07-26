#ifndef __RENDER_PASS_HPP__
#define __RENDER_PASS_HPP__

#include <vector>
#include <list>
#include <d3d11.h>
#include <DirectXPackedVector.h>

namespace Hikari
{
	/**
		\class	RenderPass
		\brief	(DEVEL! mo�e ulec du�ym zmianom) Pojedyncze przejscie renderera, metoda run() uruchamia proces renderingu
	*/
	class RenderPass
	{
		public:
			virtual void run(RenderPass* pRenderTargets /** wska�nik na list� cel�w (do ��czenia wielu etap�w)*/) = 0; //< uruchamia proces renderingu, zwraca *this aby robi� ci�g wywo�a�

			/** Pobiera list� cel�w */
			std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> > * renderTargets(void);
			std::vector<ID3D11RenderTargetView*> renderTargetViews(void);
			std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> renderTarget(unsigned int index);
			/** Ustawia aktualn� list� cel�w */
			void renderTargets(std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> > * pRenderTargets /** wska�nik na now� list� cel�w */);
			/** Dodaje pojedynczy cel */
			void addRenderTarget(ID3D11Texture2D* pTexture /** tekstura */, ID3D11RenderTargetView* pRenderTarget /** render target utworzony z tekstury */, D3D11_VIEWPORT renderTargetViewport);
			/** Usuwa pojedynczy element z listy cel�w */
			void removeRenderTarget(unsigned int index /** Indeks elementu, kt�ry ma zosta� usuni�ty */);
			D3D11_VIEWPORT viewport(unsigned int index);
			std::vector<D3D11_VIEWPORT> viewports(void);

			// wyprowadzi� kiedy� clearColor do renderTarget�w, �eby nie by�y per pass a per RT
			DirectX::XMVECTORF32 clearColor(void);
			void clearColor(DirectX::XMVECTORF32 *newClearColor);

			RenderPass();
			/** Wirtualny destruktor m.in. zwalniajacy liste celow */
			virtual ~RenderPass();

		protected:
			DirectX::XMVECTORF32 m_ClearColor;
			std::vector<std::pair<ID3D11RenderTargetView*, ID3D11Texture2D*> > * m_pRenderTargets;
			std::vector<D3D11_VIEWPORT> * m_pRenderTargetViewports;
	};
}

#endif // __RENDER_PASS_HPP__