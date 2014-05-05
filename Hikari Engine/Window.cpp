#include "Window.hpp"

Hikari::Window::~Window()
{
}

void Hikari::Window::position(int x, int y)
{
	m_PosX = x;
	m_PosY = y;
}

void Hikari::Window::position(Hikari::Vector2D& point)
{
	m_PosX = point.x();
	m_PosY = point.y();
}

Hikari::Vector2D Hikari::Window::position()
{
	return Vector2D(m_PosX, m_PosY);
}

std::string Hikari::Window::title(void)
{
	return m_Title;
}

void Hikari::Window::title(const char* title)
{
	m_Title = std::string(title);
}

void Hikari::Window::title(std::string title)
{
	m_Title = title;
}

void Hikari::Window::size(unsigned int width, unsigned int height)
{
	m_Width = width;
	m_Height = height;
}

Hikari::Vector2D Hikari::Window::size(void)
{
	return Vector2D(m_Width, m_Height);
}

void Hikari::Window::fullscreen(bool fullscreen)
{
	m_Fullscreen = fullscreen;
}

bool Hikari::Window::fullscreen(void)
{
	return m_Fullscreen;
}
