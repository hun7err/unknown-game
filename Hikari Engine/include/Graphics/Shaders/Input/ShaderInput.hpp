#ifndef __HIKARI_GRAPHICS_SHADERS_INPUT_SHADERINPUTHPP__
#define __HIKARI_GRAPHICS_SHADERS_INPUT_SHADERINPUTHPP__

#include "../../../Helpers/ECS/Entity.hpp"
#include "../../../Core/ErrorCode.hpp"
#include <vector>
#include <map>
#include <d3d11.h>

namespace Hikari
{
	namespace Shaders
	{
		class ShaderInput : public Entity
		{
			public:
				ShaderInput( void );

				ErrorCode CreateInputLayout( ID3D11Device *pDevice, ID3D10Blob *pShaderBlob );
				ID3D11InputLayout *GetInputLayout( void );

				void AddComponent( Component *pComponent );
				bool RemoveComponent( const std::string& componentID );

				ID3D11SamplerState** GetSamplers( void );
				unsigned int GetSamplerCount( void ) const;

			protected:
				std::vector<D3D11_INPUT_ELEMENT_DESC> m_InputElementsDescriptions;
				ID3D11InputLayout *m_pInputLayout;

				std::vector< ID3D11SamplerState* > m_Samplers;
				std::map< std::string, unsigned int > m_ComponentPositions;
		};
	}
}

#endif