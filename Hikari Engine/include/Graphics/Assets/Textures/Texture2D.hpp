#ifndef __HIkARI_GRAPHICS_ASSETS_TEXTURES_TEXTURE2DHPP__
#define __HIKARI_GRAPHICS_ASSETS_TEXTURES_TEXTURE2DHPP__

#include "../../../Graphics/Assets/Texture.hpp"
#include <DirectXPackedVector.h>
#include <IL/il.h>
#include <string>

namespace Hikari
{
	namespace Assets
	{
		namespace Textures
		{
			class Texture2D : public Texture
			{
				public:
					Texture2D( void );
					Texture2D( const std::string& AssetID );
					~Texture2D( void );

					ErrorCode Create( ID3D11Device *pDevice, int width, int height, D3D11_SUBRESOURCE_DATA *pInitialData = nullptr );
					ErrorCode Create( ID3D11Device *pDevice, D3D11_TEXTURE2D_DESC *pDescription, D3D11_SUBRESOURCE_DATA* pInitialData = nullptr, D3D11_RENDER_TARGET_VIEW_DESC *pRenderTargetViewDescription = nullptr, D3D11_SHADER_RESOURCE_VIEW_DESC *pShaderResourceViewDescription = nullptr );

					ErrorCode Load( const std::string& filename );

					void SetDevicePointer( ID3D11Device *pDevice );

					ID3D11Texture2D *GetTexturePointer( void );
					ID3D11RenderTargetView *GetRenderTargetView( void );
					const DirectX::XMVECTORF32& GetClearColor( void ) const;
					void SetClearColor( const DirectX::XMVECTORF32& newClearColor );

					int GetWidth( void ) const;
					int GetHeight( void ) const;

				private:
					ID3D11Device *m_pDevice;
					ID3D11Texture2D *m_pTexture;
					ID3D11RenderTargetView *m_pRenderTargetView;
					ILuint m_ilImageName;	// na pewno potrzebne?
					DirectX::XMVECTORF32 m_ClearColor;
			};
		}
	}
}

#endif