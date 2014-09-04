#include "../../../include/Graphics/Assets/Material.hpp"
#include "../../../include/Graphics/Assets/Texture.hpp"

Hikari::Assets::Material::Material( void ) : Asset( ), Entity( ), Component( "Material" )
{
}

Hikari::Assets::Material::Material( const std::string& AssetID ) : Asset( AssetID ), Entity( ), Component( "Material" )
{
}

Hikari::ErrorCode Hikari::Assets::Material::Load( const std::string& filename )
{
	return ErrorCode::NOT_IMPLEMENTED_YET;
}

void Hikari::Assets::Material::AddComponent( Component *pComponent )
{
	m_Components.push_back( pComponent );

	if( pComponent->GetID().find( "Texture" ) != std::string::npos )
	{
		Assets::Texture *pTexture = ( Assets::Texture* ) pComponent;

		unsigned int key = m_ShaderResources.size( );
		m_ShaderResources.push_back( pTexture->GetShaderResourceView( ) );

		m_ComponentPositions.insert( std::make_pair( pComponent->GetID( ), key ) );
	}
}

bool Hikari::Assets::Material::RemoveComponent( const std::string& componentID )
{
	auto element = m_ComponentPositions.find( componentID );
	unsigned int key = element->second;

	m_ShaderResources.erase( m_ShaderResources.begin( ) + key );

	for( element = m_ComponentPositions.begin(); element != m_ComponentPositions.end(); ++element )
	{
		if( element->second > key )
		{
			element->second--;
		}
	}

	m_ComponentPositions.erase( element );

	for( auto component = m_Components.begin(); component != m_Components.end(); ++component )
	{
		if( ( *component )->GetID( ) == componentID )
		{
			m_Components.erase( component );

			return true;
		}
	}

	return false;
}

ID3D11ShaderResourceView** Hikari::Assets::Material::GetShaderResources( void )
{
	if( m_ShaderResources.empty() )
	{
		return nullptr;
	}
	else
	{
		return &(m_ShaderResources[0]);
	}
}

unsigned int Hikari::Assets::Material::GetShaderResourceCount( void ) const
{
	return m_ShaderResources.size();
}
