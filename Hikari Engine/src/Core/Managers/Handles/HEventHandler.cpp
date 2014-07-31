#include "../../../../include/Core/Managers/Handles/HEventHandler.hpp"

Hikari::HEventHandler::HEventHandler(Hikari::Event handledEvent, int key) : Handle(key), m_handledEvent(handledEvent)
{
}

Hikari::EventHandler* Hikari::HEventHandler::operator->(void) const
{
	return nullptr;
}

bool Hikari::HEventHandler::isValid(void)
{
	return true;
}

Hikari::Event Hikari::HEventHandler::handledEvent(void)
{
	return m_handledEvent;
}
