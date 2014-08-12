#include "../../../../include/Core/Messaging/Messages/KeyMessage.hpp"

Hikari::Messages::KeyMessage::KeyMessage( short int eventType ) : Message(eventType)
{
}

Hikari::Messages::KeyMessage::KeyMessage( short int eventType, int keyCode ) : Message(eventType), m_KeyCode(keyCode)
{
}

int Hikari::Messages::KeyMessage::GetKeyCode( void ) const
{
	return m_KeyCode;
}

void Hikari::Messages::KeyMessage::SetKeyCode( int keyCode )
{
	m_KeyCode = keyCode;
}

Hikari::Messages::KeyPressMessage::KeyPressMessage( void ) : KeyMessage( Hikari::Events::KeyEvent::Press )
{
}

Hikari::Messages::KeyPressMessage::KeyPressMessage( int keyCode ) : KeyMessage( Hikari::Events::KeyEvent::Press, keyCode )
{
}

Hikari::Messages::KeyReleaseMessage::KeyReleaseMessage( void ) : KeyMessage( Hikari::Events::KeyEvent::Release )
{
}

Hikari::Messages::KeyReleaseMessage::KeyReleaseMessage( int keyCode ) : KeyMessage( Hikari::Events::KeyEvent::Release, keyCode )
{
}
