#ifndef __LISTENERHPP__
#define __LISTENERHPP__

#include "../../Helpers/ECS/Component.hpp"
#include "../../Core/Messaging/Messenger.hpp"
#include "../../Core/Messaging/Message.hpp"
#include <functional>
#include <vector>

namespace Hikari
{
	class Listener : public Component
	{
		public:
			Listener( void );

			void Subscribe( Messenger *pMessenger, short int eventType, std::function<void(Message*)> callback );
			void Unsubscribe( Messenger *pMessenger );
			void Unsubscribe( Messenger *pMessenger, short int eventType );

		private:
			std::vector< std::pair<short int, unsigned int> > m_MessengerKeys; // <event, klucz>
	};
}

#endif