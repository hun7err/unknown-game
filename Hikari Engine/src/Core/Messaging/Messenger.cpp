#include "../../../include/Core/Messaging/Messenger.hpp"

const char* Hikari::Exceptions::EventNotSupportedByMessengerException::what( void ) const
{
	return "Listener subscription failed because of wrong event type passed to Messenger's AddSubscriber() method; this event is not supported by that Messenger";
}

const char* Hikari::Exceptions::NoSpaceLeftInMessengerException::what( void ) const
{
	return "Listener subscription failed because there is no space left in the Messenger";
}

Hikari::Messenger::Messenger( short int postedEvent ) : Component("Messenger")
{
	m_PostedEvents.push_back(postedEvent);
}

Hikari::Messenger::Messenger( const short int postedEvents[] ) : Component("Messenger")
{
	unsigned int size = sizeof(postedEvents);
	m_PostedEvents.resize(size/sizeof(short int));
	memcpy(&m_PostedEvents[0], postedEvents, size);
}

void Hikari::Messenger::Notify( Hikari::Message* msg )
{
	m_ListenersMutex.lock();
	for( auto listener = m_Listeners.begin(); listener != m_Listeners.end(); ++listener )
	{
		if( msg->GetID() == (*listener).first && (*listener).second != nullptr )
		{
			(*listener).second(msg);
		}
	}
	m_ListenersMutex.unlock();

	delete msg;
}

unsigned int Hikari::Messenger::AddListener( short int eventType, std::function<void(Message*)> callback )
{
	if(m_Listeners.size() == 256)
	{
		throw Exceptions::NoSpaceLeftInMessengerException();
	}

	for(auto currentEvent = m_PostedEvents.begin(); currentEvent != m_PostedEvents.end(); ++currentEvent)
	{
		if( *currentEvent == eventType )
		{
			unsigned int key;

			if(m_FreeSlots.empty())
			{
				m_ListenersMutex.lock();
				key = m_Listeners.size();
				m_Listeners.push_back(std::make_pair(eventType, callback));
			}
			else
			{
				key = m_FreeSlots.back();
				m_FreeSlots.pop_back();
				
				m_ListenersMutex.lock();
				m_Listeners.push_back(std::make_pair(eventType, callback));
			}
			
			m_ListenersMutex.unlock();
			
			return key;
		}
	}

	throw Exceptions::EventNotSupportedByMessengerException();
}

void Hikari::Messenger::RemoveListener( unsigned int key )
{
	m_ListenersMutex.lock();
	
	if(key < m_Listeners.size())
	{
		m_FreeSlots.push_back(key);
		m_Listeners[key].second = nullptr;
		
		return;
	}

	m_ListenersMutex.unlock();
}
