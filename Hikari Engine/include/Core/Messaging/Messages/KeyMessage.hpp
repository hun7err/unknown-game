#ifndef __KEYMESSAGEHPP__
#define __KEYMESSAGEHPP__

#include "../../../Core/Messaging/Message.hpp"
#include "../../../Core/Messaging/Events/KeyEvent.hpp"

namespace Hikari
{
	namespace Messages
	{
		class KeyMessage : public Message
		{
			public:
				KeyMessage( short int eventType );
				KeyMessage( short int eventType, int keyCode );

				int GetKeyCode( void ) const;
				void SetKeyCode( int keyCode );

			private:
				int m_KeyCode;
		};

		class KeyPressMessage : public KeyMessage
		{
			public:
				KeyPressMessage( void );
				KeyPressMessage( int keyCode );
		};

		class KeyReleaseMessage : public KeyMessage
		{
			public:
				KeyReleaseMessage( void );
				KeyReleaseMessage( int keyCode );
		};
	}
}

#endif