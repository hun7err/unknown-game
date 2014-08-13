#ifndef __MESSENGERHPP__
#define __MESSENGERHPP__

#include "../../Helpers/ECS/Component.hpp"
#include "../../Core/Messaging/Message.hpp"
#include <functional>
#include <mutex>
#include <vector>

#define EVENT_NOT_SUPPORTED_BY_MESSENGER -1
#define NO_SPACE_IN_MESSENGER -2

namespace Hikari
{
	class Messenger : public Component
	{
		public:
			Messenger( short int postedEvent );
			Messenger( const short int postedEvents[] );

			void Notify( Message* msg );
			int AddListener( short int eventType, std::function<void(Message*)> callback );
			void RemoveListener( unsigned int key );

		private:
			std::vector<short int> m_PostedEvents;

			std::vector< std::pair<short int, std::function< void(Message*)> > > m_Listeners;
			std::vector< unsigned char > m_FreeSlots;
			std::mutex m_ListenersMutex;
	};
}

#endif