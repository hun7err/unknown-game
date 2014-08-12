#include "../../../include/Core/Messaging/Message.hpp"

Hikari::Message::Message( void ) : m_ID(-1)
{
}

Hikari::Message::Message( short int ID ) : m_ID(ID)
{
}

short int Hikari::Message::GetID( void ) const
{
	return m_ID;
}

void Hikari::Message::SetID( short int newID )
{
	if(newID >= 0)
	{
		m_ID = newID;
	}
}
