#ifndef __HIKARI_GRAPHICS_SHADERS_COMPUTESHADERHPP__
#define __HIKARI_GRAPHICS_SHADERS_COMPUTESHADERHPP__

#include "Shader.hpp"

namespace Hikari
{
	namespace Shaders
	{
		class ComputeShader : public Shader
		{
			public:
				ComputeShader( void );
				ComputeShader( const std::wstring& filename );

				ErrorCode Compile( ID3D11Device *pDevice );

				ID3D11ComputeShader *GetShaderPointer( void );

			private:
				ID3D11ComputeShader *m_pComputeShader;
		};
	}
}

#endif