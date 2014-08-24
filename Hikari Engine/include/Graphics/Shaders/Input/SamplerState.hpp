#ifndef __HIKARI_GRAPHICS_SHADERS_INPUT_SAMPLERSTATEHPP__
#define __HIKARI_GRAPHICS_SHADERS_INPUT_SAMPLERSTATEHPP__

#include "../../../Helpers/ECS/Component.hpp"
#include "../../../Core/ErrorCode.hpp"
#include <d3d11.h>

namespace Hikari
{
	namespace Shaders
	{
		namespace Input
		{
			class SamplerState : public Component
			{
				public:
					SamplerState( void );

					ErrorCode Create( ID3D11Device *pDevice );

					ID3D11SamplerState *GetSamplerStatePointer( void );
					const D3D11_SAMPLER_DESC& GetSamplerDescription( void ) const;
					void SetSamplerDescription( const D3D11_SAMPLER_DESC& SamplerDescription );

				private:
					D3D11_SAMPLER_DESC m_SamplerDescription;
					ID3D11SamplerState *m_pSamplerState;
			};
		}
	}
}

#endif