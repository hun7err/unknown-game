#ifndef __HIKARI_GRAPHICS_SHADERS_VERTEXSHADERHPP__
#define __HIKARI_GRAPHICS_SHADERS_VERTEXSHADERHPP__

#include "Shader.hpp"

namespace Hikari
{
	namespace Shaders
	{
		class VertexShader : public Shader
		{
			public:
				VertexShader( void );
				VertexShader( const std::wstring& filename );

				ErrorCode Compile( ID3D11Device *pDevice );

				ID3D11VertexShader *GetShaderPointer( void );

			private:
				ID3D11VertexShader *m_pVertexShader;
		};
	}
}

#endif