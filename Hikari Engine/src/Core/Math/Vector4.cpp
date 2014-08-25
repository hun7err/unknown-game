#include "../../../include/Core/Math/Vector4.hpp"

Hikari::Vector4::Vector4( float x, float y, float z, float w )
{
	m_Value.f[0] = x;
	m_Value.f[1] = y;
	m_Value.f[2] = z;
	m_Value.f[3] = w;
}

Hikari::Vector4::Vector4( const Vector3& vector, float w )
{
	m_Value.f[0] = vector.GetValue().x;
	m_Value.f[1] = vector.GetValue().y;
	m_Value.f[2] = vector.GetValue().z;
	m_Value.f[3] = w;
}

const DirectX::XMVECTORF32& Hikari::Vector4::GetValue( void ) const
{
	return m_Value;
}

std::string Hikari::Vector4::ToString( void ) const
{
	std::string vector( "(" + 
						std::to_string(m_Value.f[0]) +
						"," +
						std::to_string(m_Value.f[1]) +
						"," +
						std::to_string(m_Value.f[2]) +
						"," +
						std::to_string(m_Value.f[3]) +
						")" );

	return vector;
}

Hikari::Vector4& Hikari::Vector4::operator=( const Vector3& vector )
{
	m_Value.f[0] = vector.GetValue().x;
	m_Value.f[1] = vector.GetValue().y;
	m_Value.f[2] = vector.GetValue().z;

	return *this;
}

float Hikari::Vector4::GetX( void ) const
{
	return m_Value.f[0];
}

float Hikari::Vector4::GetY( void ) const
{
	return m_Value.f[1];
}

float Hikari::Vector4::GetZ( void ) const
{
	return m_Value.f[2];
}

float Hikari::Vector4::GetW( void ) const
{
	return m_Value.f[3];
}

void Hikari::Vector4::SetX( float x )
{
	m_Value.f[0] = x;
}

void Hikari::Vector4::SetY( float y )
{
	m_Value.f[1] = y;
}

void Hikari::Vector4::SetZ( float z )
{
	m_Value.f[2] = z;
}

void Hikari::Vector4::SetW( float w )
{
	m_Value.f[3] = w;
}
