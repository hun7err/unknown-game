#include "../../../include/Graphics/Assets/Asset.hpp"

Hikari::Asset::Asset( void )
{
}

Hikari::Asset::Asset( const std::string& ID ) : m_ID(ID)
{
}

Hikari::Asset::~Asset()
{
}

const std::string& Hikari::Asset::GetID( void ) const
{
	return m_ID;
}

void Hikari::Asset::SetID( const std::string& newID )
{
	m_ID = newID;
}
