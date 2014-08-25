#include "../../../include/Core/Math/Vector2.hpp"

Hikari::Vector2::Vector2( float u, float v )
{
	m_Value.x = u;
	m_Value.y = v;
}

std::string Hikari::Vector2::ToString( void )
{
	std::string vector( "(" + 
						std::to_string(m_Value.x) +
						"," +
						std::to_string(m_Value.y) +
						")" );

	return vector;
}

float Hikari::Vector2::GetU( void ) const
{
	return m_Value.x;
}

float Hikari::Vector2::GetV( void ) const
{
	return m_Value.y;
}

void Hikari::Vector2::SetU( float u )
{
	m_Value.x = u;
}

void Hikari::Vector2::SetV( float v )
{
	m_Value.y = v;
}
