#ifndef __HIKARI_GRAPHICS_RENDERERHPP__
#define __HIKARI_GRAPHICS_RENDERERHPP__

#include <d3d11.h>
#include <d3d10.h>
#include <dxgi.h>
#include "../Assets/Textures/Texture2D.hpp"
#include "../../Core/Scene/Scene.hpp"

namespace Hikari
{
	class Renderer
	{
		public:
			Renderer( void );
			virtual ~Renderer( void );

			virtual int Init( ID3D11Device *pDevice, unsigned int width, unsigned int height ) = 0;
			virtual void Render( ID3D11DeviceContext *pDeviceContext, IDXGISwapChain *pSwapChain, Scene *pScene ) = 0;

	};
}

#endif