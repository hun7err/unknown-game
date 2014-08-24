#ifndef __HIKARI_GRAPHICS_SHADERS_PIXELSHADERHPP__
#define __HIKARI_GRAPHICS_SHADERS_PIXELSHADERHPP__

#include "Shader.hpp"

namespace Hikari
{
	namespace Shaders
	{
		class PixelShader : public Shader
		{
			public:
				PixelShader( void );
				PixelShader( const std::wstring& filename );

				ErrorCode Compile( ID3D11Device *pDevice );

				ID3D11PixelShader *GetShaderPointer( void );

			private:
				ID3D11PixelShader *m_pPixelShader;
		};
	}
}

#endif