#ifndef __HIKARI_CORE_MANAGERS_HANDLES_HEVENTHANDLERHPP__
#define __HIKARI_CORE_MANAGERS_HANDLES_HEVENTHANDLERHPP__

#include "../../../Core/Managers/Handles/Handle.hpp"
#include "../../../Core/Engine/Events/Events.hpp"
#include "../../../Core/Engine/EventHandlers/EventHandler.hpp"

namespace Hikari
{
	class HEventHandler : public Hikari::Handle<Hikari::EventHandler>
	{
		public:
			HEventHandler(Hikari::Event handledEvent, int key = -1);
			Hikari::EventHandler* operator->(void) const;
			bool isValid(void);
			Hikari::Event handledEvent(void);

		private:
			Hikari::Event m_handledEvent;
	};
}

#endif