#ifndef __HIKARI_GRAPHICS_RENDERERS_BASICRENDERERHPP__
#define __HIKARI_GRAPHICS_RENDERERS_BASICRENDERERHPP__

#include "Renderer.hpp"
#include "../../Core/Cameras/Camera.hpp"
#include <DirectXMath.h>

namespace Hikari
{
	class BasicRenderer : public Renderer
	{
		public:
			BasicRenderer( void );
			~BasicRenderer( void );

			int Init( ID3D11Device *pDevice, unsigned int width, unsigned int height );

			void Render( ID3D11DeviceContext *pDeviceContext, IDXGISwapChain *pSwapChain, Scene *pScene );

		private:
			void Draw( ID3D11DeviceContext *pDeviceContext, const std::vector< Node >& nodes, DirectX::XMMATRIX& transformation );
			void Draw( ID3D11DeviceContext *pDeviceContext, const Object& object, const DirectX::XMMATRIX& transformation );

			D3D11_VIEWPORT *m_pViewports;
			Assets::Textures::Texture2D *m_pTextures;
			ID3D11RenderTargetView **m_pRenderTargetViews;
			unsigned int m_RenderTargetCount;
			Camera *m_pActiveCamera;
	};
}

#endif