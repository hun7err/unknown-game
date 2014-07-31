#include "../../../include/Core/Managers/EventHandlerManager.hpp"

Hikari::EventHandlerManager::EventHandlerManager()
{
	int itemCount = (int)Event::EVENTS_ITEM_COUNT;
	m_Items.resize(itemCount);
	m_pPerEventMutexes = new std::mutex[itemCount];
	m_pFreeSlotsMutexes = new std::mutex[itemCount];
}

Hikari::EventHandlerManager::~EventHandlerManager()
{
	delete [] m_pFreeSlotsMutexes;
	m_pFreeSlotsMutexes = nullptr;
	delete [] m_pPerEventMutexes;
	m_pPerEventMutexes = nullptr;
}

Hikari::HEventHandler Hikari::EventHandlerManager::add(Hikari::EventHandler* pEventHandler)
{
	int slot,
		myEvent = (int)(pEventHandler->handledEvent());
	m_pFreeSlotsMutexes[myEvent].lock();
	if(m_FreeSlots.empty())
	{
		m_pFreeSlotsMutexes[myEvent].unlock();

		m_pPerEventMutexes[myEvent].lock();
		slot = m_Items[myEvent].size();
		m_Items[myEvent].push_back(pEventHandler);
		m_pPerEventMutexes[myEvent].unlock();
	}
	else
	{
		slot = m_FreeSlots[(int)pEventHandler->handledEvent()].back();
		m_FreeSlots.pop_back();
		m_pFreeSlotsMutexes[myEvent].unlock();

		m_pPerEventMutexes[myEvent].lock();
		m_Items[(int)pEventHandler->handledEvent()][slot] = pEventHandler;
		m_pPerEventMutexes[myEvent].unlock();
	}

	return HEventHandler(pEventHandler->handledEvent(), slot);
}

void Hikari::EventHandlerManager::remove(Hikari::HEventHandler hEventHandler)
{
	int myEvent = (int)(hEventHandler.handledEvent()),
		key = hEventHandler.key();

	m_pPerEventMutexes[myEvent].lock();
	m_Items[myEvent][key] = nullptr;

	m_pFreeSlotsMutexes[myEvent].lock();
	m_FreeSlots[myEvent].push_back(key);
	m_pFreeSlotsMutexes[myEvent].unlock();

	m_pPerEventMutexes[myEvent].unlock();
}

std::vector<Hikari::EventHandler*>* Hikari::EventHandlerManager::eventHandlers(Hikari::Event desiredEvent)
{
	int myEvent = (int)desiredEvent;

	return &(m_Items[myEvent]);
}

std::vector<std::vector<Hikari::EventHandler*> >* Hikari::EventHandlerManager::eventHandlers(void)
{
	return &m_Items;
}
