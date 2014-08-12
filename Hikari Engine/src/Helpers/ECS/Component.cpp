#include "../../../include/Helpers/ECS/Component.hpp"

Hikari::Component::Component( void )
{
}

Hikari::Component::Component( std::string ID ) : m_ID(ID)
{
}

Hikari::Component::~Component( )
{
}

const std::string& Hikari::Component::GetID( void ) const
{
	return m_ID;
}

void Hikari::Component::SetID( const std::string& newID )
{
	m_ID = newID;
}
