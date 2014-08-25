#include "../../../include/Core/Components/Position.hpp"

Hikari::Components::Position::Position(float x, float y, float z) : Component("Position")
{
	m_Value.SetX( x );
	m_Value.SetY( y );
	m_Value.SetZ( z );
}

void Hikari::Components::Position::SetValue( const Hikari::Vector2& newValue)
{
	m_Value.SetX( newValue.GetU() );
	m_Value.SetY( newValue.GetV() );
	m_Value.SetZ( 0.0f );
}
