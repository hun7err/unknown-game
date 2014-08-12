#include "../../../include/Core/Messaging/Listener.hpp"

Hikari::Listener::Listener( void ) : Component("Listener")
{
}

void Hikari::Listener::Subscribe( Hikari::Messenger *pMessenger, short int eventType, std::function<void(Message*)> callback )
{
	unsigned int key = pMessenger->AddListener( eventType, callback );
	m_MessengerKeys.push_back(std::make_pair(eventType, key));
}

void Hikari::Listener::Unsubscribe( Hikari::Messenger *pMessenger )
{
	for( auto eventKeyPair = m_MessengerKeys.begin(); eventKeyPair != m_MessengerKeys.end(); ++eventKeyPair )
	{
		pMessenger->RemoveListener( (*eventKeyPair).second );	// tylko klucz
	}
}

void Hikari::Listener::Unsubscribe( Hikari::Messenger *pMessenger, short int eventType )
{
	// pary <first: eventType, second: MessengerKey>
	for( auto eventKeyPair = m_MessengerKeys.begin(); eventKeyPair != m_MessengerKeys.end(); ++eventKeyPair )
	{
		if( (*eventKeyPair).first == eventType )
		{
			pMessenger->RemoveListener( (*eventKeyPair).second );
		}
	}
}
