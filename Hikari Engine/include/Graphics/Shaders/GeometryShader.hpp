#ifndef __HIKARI_GRAPHICS_SHADERS_GEOMETRYSHADERHPP__
#define __HIKARI_GRAPHICS_SHADERS_GEOMETRYSHADERHPP__

#include "Shader.hpp"

namespace Hikari
{
	namespace Shaders
	{
		class GeometryShader : public Shader
		{
			public:
				GeometryShader( void );
				GeometryShader( const std::wstring& filename );

				ErrorCode Compile( ID3D11Device *pDevice );

				ID3D11GeometryShader *GetShaderPointer( void );

			private:
				ID3D11GeometryShader *m_pGeometryShader;
		};
	}
}

#endif