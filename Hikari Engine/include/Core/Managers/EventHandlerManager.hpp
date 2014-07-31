#ifndef __HIKARI_CORE_MANAGERS_EVENTHANDLERMANAGER_HPP__
#define __HIKARI_CORE_MANAGERS_EVENTHANDLERMANAGER_HPP__

#include "../../Core/Managers/Handles/HEventHandler.hpp"
#include "../../Core/Engine/EventHandlers/EventHandler.hpp"
#include "../../Core/Engine/Events/Events.hpp"

#include <utility>
#include <vector>
#include <mutex>

namespace Hikari
{
	class EventHandlerManager
	{
		public:
			EventHandlerManager();
			~EventHandlerManager();

			HEventHandler add(EventHandler *pEventHandler);
			void remove(HEventHandler hEventHandler);

			std::vector<Hikari::EventHandler*>* eventHandlers(Hikari::Event desiredEvent);
			std::vector<std::vector<Hikari::EventHandler*> >* eventHandlers(void);

		private:
			std::vector<
					std::vector<
						Hikari::EventHandler*
					>
			> m_Items;

			std::vector<
				std::vector<
					unsigned int
				>
			> m_FreeSlots;

			std::mutex *m_pPerEventMutexes;	// nie mo¿e byæ wektor, bo mutex nie pozwala na kopiowanie (operator= odwo³uje siê do prywatnego pola)
			std::mutex *m_pFreeSlotsMutexes;
	};
}

#endif