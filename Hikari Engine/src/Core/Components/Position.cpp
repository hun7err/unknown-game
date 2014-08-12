#include "../../../include/Core/Components/Position.hpp"

Hikari::Components::Position::Position(float x, float y, float z) : Component("Position")
{
	m_Value.SetX( x );
	m_Value.SetY( y );
	m_Value.SetZ( z );
}

void Hikari::Components::Position::SetValue( const Hikari::Vector2D& newValue)
{
	m_Value.SetX( newValue.GetX() );
	m_Value.SetY( newValue.GetY() );
	m_Value.SetZ( 0.0f );
}
