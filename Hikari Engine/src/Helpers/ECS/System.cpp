#include "../../../include/Helpers/ECS/System.hpp"

Hikari::System::System( const std::string& ID ) : m_ID(ID)
{
}

Hikari::System::System( void )
{
}

Hikari::System::~System( void )
{
}

const std::string& Hikari::System::GetID( void ) const
{
	return m_ID;
}

void Hikari::System::SetID( const std::string& ID )
{
	m_ID = ID;
}
