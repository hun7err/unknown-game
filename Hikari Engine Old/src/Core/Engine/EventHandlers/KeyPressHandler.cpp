#include "../../../../include/Core/Engine/EventHandlers/KeyPressHandler.hpp"

Hikari::EventHandlers::KeyPressHandler::KeyPressHandler()
{
	m_HandledEvent = Hikari::Event::KeyPress;
	m_eventHandlerFunction = nullptr;
}

void Hikari::EventHandlers::KeyPressHandler::keyCode(int keyCode)
{
	m_KeyCode = keyCode;
}

void Hikari::EventHandlers::KeyPressHandler::handlerFunction(std::function<void(int)> newHandler)
{
	m_eventHandlerFunction = newHandler;
}

void Hikari::EventHandlers::KeyPressHandler::process(void)
{
	m_eventHandlerFunction(m_KeyCode);
}
