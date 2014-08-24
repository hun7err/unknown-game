#include "../../../include/Core/Components/Vector4.hpp"

Hikari::Components::Vector4::Vector4( float x, float y, float z, float w ) : Component( )
{
	m_Vector.value = DirectX::XMVectorSet( x, y, z, w );
}

Hikari::Components::Vector4::Vector4( const std::string& ID, float x, float y, float z, float w ) : Component( ID )
{
	m_Vector.value = DirectX::XMVectorSet( x, y, z, w );
}

void Hikari::Components::Vector4::SetValue( float x, float y, float z, float w )
{
	m_Vector.value = DirectX::XMVectorSet( x, y, z, w );
}

void Hikari::Components::Vector4::SetValue( const DirectX::XMVECTOR& newValue )
{
	m_Vector.value = newValue;
}

const DirectX::XMVECTOR& Hikari::Components::Vector4::GetValue( void ) const
{
	return m_Vector.value;
}

float Hikari::Components::Vector4::GetX( void ) const
{
	return DirectX::XMVectorGetX( m_Vector.value );
}

float Hikari::Components::Vector4::GetY( void ) const
{
	return DirectX::XMVectorGetY( m_Vector.value );
}

float Hikari::Components::Vector4::GetZ( void ) const
{
	return DirectX::XMVectorGetZ( m_Vector.value );
}

float Hikari::Components::Vector4::GetW( void ) const
{
	return DirectX::XMVectorGetW( m_Vector.value );
}

void Hikari::Components::Vector4::SetX( float x )
{
	m_Vector.value = DirectX::XMVectorSetX( m_Vector.value, x );
}

void Hikari::Components::Vector4::SetY( float y )
{
	m_Vector.value = DirectX::XMVectorSetX( m_Vector.value, y );
}

void Hikari::Components::Vector4::SetZ( float z )
{
	m_Vector.value = DirectX::XMVectorSetX( m_Vector.value, z );
}

void Hikari::Components::Vector4::SetW( float w )
{
	m_Vector.value = DirectX::XMVectorSetW( m_Vector.value, w );
}
