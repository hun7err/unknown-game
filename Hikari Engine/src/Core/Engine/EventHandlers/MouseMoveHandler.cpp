#include "../../../../include/Core/Engine/EventHandlers/MouseMoveHandler.hpp"

Hikari::EventHandlers::MouseMoveHandler::MouseMoveHandler()
{
	m_HandledEvent = Hikari::Event::MouseMove;
	m_x = m_y = -1;
	m_dx = m_dy = 0;
	m_eventHandlerFunction = nullptr;
}

void Hikari::EventHandlers::MouseMoveHandler::handlerFunction(std::function<void(int,int)> newHandlerFunction)
{
	m_eventHandlerFunction = newHandlerFunction;
}

void Hikari::EventHandlers::MouseMoveHandler::x(int x)
{
	if(m_x != -1)
	{
		m_dx = x - m_x;
	}
	m_x = x;
}

void Hikari::EventHandlers::MouseMoveHandler::y(int y)
{
	if(m_y != -1)
	{
		m_dy = y - m_y;
	}
	m_y = y;
}

void Hikari::EventHandlers::MouseMoveHandler::process(void)
{
	m_eventHandlerFunction(m_dx, m_dy);
}

void Hikari::EventHandlers::MouseMoveHandler::cursorPosition(int x, int y)
{
	if(m_x != -1 || m_y != -1)
	{
		m_dx = x - m_x;
		m_dy = y - m_y;
		m_x = x;
		m_y = y;
	}
}
