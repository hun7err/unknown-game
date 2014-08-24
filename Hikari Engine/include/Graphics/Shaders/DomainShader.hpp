#ifndef __HIKARI_GRAPHICS_SHADERS_DOMAINSHADERHPP__
#define __HIKARI_GRAPHICS_SHADERS_DOMAINSHADERHPP__

#include "Shader.hpp"

namespace Hikari
{
	namespace Shaders
	{
		class DomainShader : public Shader
		{
			public:
				DomainShader( void );
				DomainShader( const std::wstring& filename );

				ErrorCode Compile( ID3D11Device *pDevice );

				ID3D11DomainShader *GetShaderPointer( void );

			private:
				ID3D11DomainShader *m_pDomainShader;
		};
	}
}

#endif