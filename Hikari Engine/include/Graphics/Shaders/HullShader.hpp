#ifndef __HIKARI_GRAPHICS_SHADERS_HULLSHADERHPP__
#define __HIKARI_GRAPHICS_SHADERS_HULLSHADERHPP__

#include "Shader.hpp"

namespace Hikari
{
	namespace Shaders
	{
		class HullShader : public Shader
		{
			public:
				HullShader( void );
				HullShader( const std::wstring& filename );

				ErrorCode Compile( ID3D11Device *pDevice );

				ID3D11HullShader *GetShaderPointer( void );

			private:
				ID3D11HullShader *m_pHullShader;
		};
	}
}

#endif