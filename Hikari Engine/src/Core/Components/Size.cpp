#include "../../../include/Core/Components/Size.hpp"

Hikari::Components::Size::Size( float width, float height, float depth ) : Component("Size")
{
	 m_Value.SetX( width );
	 m_Value.SetY( height );
	 m_Value.SetZ( depth );
}

void Hikari::Components::Size::SetValue( const Hikari::Vector2& newValue)
{
	m_Value.SetX( newValue.GetU() );
	m_Value.SetY( newValue.GetV() );
	m_Value.SetZ( 0.0f );
}

void Hikari::Components::Size::SetValue( float width, float height, float depth )
{
	m_Value.SetX( width );
	m_Value.SetY( height );
	m_Value.SetZ( depth );
}
