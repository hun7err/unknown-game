#include "../../../include/Helpers/Math/Vector2D.hpp"

Hikari::Vector2D::Vector2D() : m_x(0), m_y(0)
{
}

Hikari::Vector2D::Vector2D(float x, float y): m_x(x), m_y(y)
{
}

float Hikari::Vector2D::GetX(void) const
{
	 return m_x;
}

float Hikari::Vector2D::GetY(void) const
{
	 return m_y;
}

void Hikari::Vector2D::SetX(float x)
{
	m_x = x;
}

void Hikari::Vector2D::SetY(float y)
{
	m_y = y;
}