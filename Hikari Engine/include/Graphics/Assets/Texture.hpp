#ifndef __HIKARI_GRAPHICS_ASSETS_TEXTURE_HPP__
#define __HIKARI_GRAPHICS_ASSETS_TEXTURE_HPP__

#include "Asset.hpp"
#include "../../Helpers/ECS/Component.hpp"
#include <string>
#include <d3d11.h>

namespace Hikari
{
	namespace Assets
	{
		class Texture : public Component, public Asset
		{
			public:
				Texture( void );
				Texture( const std::string& AssetID );
				virtual ~Texture( void );
				
				ID3D11ShaderResourceView *GetShaderResourceView( void );
				void SetShaderResourceView( ID3D11ShaderResourceView *pShaderResourceView );
					
			protected:
				ID3D11ShaderResourceView *m_pShaderResourceView;
		};
	}
}

#endif