#ifndef __HIKARI_CORE_ENGINE_EVENTHANDLERS_EVENTHANDLERHPP__
#define __HIKARI_CORE_ENGINE_EVENTHANDLERS_EVENTHANDLERHPP__

#include "../../../Core/Engine/Events/Events.hpp"

namespace Hikari
{
	class EventHandler
	{
		public:
			virtual void process() = 0;
			Hikari::Event handledEvent(void);

		protected:
			Hikari::Event m_HandledEvent;
	};
}

#endif