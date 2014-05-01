#include "Window.hpp"

Hikari::Window& Hikari::Window::setPosition(int x, int y)
{
	m_PosX = x;
	m_PosY = y;

	return *this;
}

Hikari::Window& Hikari::Window::setPosition(Hikari::Vector2D& point)
{
	m_PosX = point.x();
	m_PosY = point.y();

	return *this;
}

Hikari::Vector2D Hikari::Window::getPosition()
{
	return Vector2D(m_PosX, m_PosY);
}

std::string Hikari::Window::getTitle(void)
{
	return m_Title;
}

Hikari::Window& Hikari::Window::setTitle(const char* title)
{
	m_Title = std::string(title);

	return *this;
}

Hikari::Window& Hikari::Window::setTitle(std::string title)
{
	m_Title = title;

	return *this;
}

Hikari::Window& Hikari::Window::setSize(unsigned int width, unsigned int height)
{
	m_Width = width;
	m_Height = height;
}
