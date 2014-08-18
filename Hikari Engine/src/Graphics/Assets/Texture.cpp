#include "../../../include/Graphics/Assets/Texture.hpp"

Hikari::Assets::Texture::Texture( void ) : Asset("NoName"), Component()
{
}

Hikari::Assets::Texture::Texture( const std::string& AssetID ) : Asset(AssetID), Component()
{
}

Hikari::Assets::Texture::~Texture( void )
{
}

ID3D11ShaderResourceView *Hikari::Assets::Texture::GetShaderResourceView( void )
{
	return m_pShaderResourceView;
}

void Hikari::Assets::Texture::SetShaderResourceView( ID3D11ShaderResourceView *pShaderResourceView )
{
	m_pShaderResourceView = pShaderResourceView;
}
