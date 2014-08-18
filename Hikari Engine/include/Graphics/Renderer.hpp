#ifndef __HIKARI_GRAPHICS_RENDERERHPP__
#define __HIKARI_GRAPHICS_RENDERERHPP__

#include <d3d11.h>
#include <d3d10.h>
#include <dxgi.h>
#include "Assets/Textures/Texture2D.hpp"

namespace Hikari
{
	class Renderer
	{
		public:
			Renderer( void );
			~Renderer( void );

			int Init( ID3D11Device *pDevice, unsigned int width, unsigned int height );
			void Render( ID3D11DeviceContext *pDeviceContext, IDXGISwapChain *pSwapChain );

		private:
			D3D11_VIEWPORT *m_pViewports;
			Assets::Textures::Texture2D *m_pTextures;
			ID3D11RenderTargetView **m_pRenderTargetViews;
			unsigned int m_RenderTargetCount;
			// render targety
	};
}

#endif