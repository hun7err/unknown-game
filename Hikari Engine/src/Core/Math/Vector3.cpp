#include "../../../include/Core/Math/Vector3.hpp"
			
Hikari::Vector3::Vector3( float x, float y, float z )
{
	m_Value.x = x;
	m_Value.y = y;
	m_Value.z = z;
}

DirectX::XMFLOAT3 Hikari::Vector3::GetValue( void ) const
{
	return m_Value;
}

std::string Hikari::Vector3::ToString( void ) const
{
	std::string vector( "(" + 
						std::to_string(m_Value.x) +
						"," +
						std::to_string(m_Value.y) +
						"," +
						std::to_string(m_Value.z) +
						")" );

	return vector;
}

float Hikari::Vector3::GetX( void ) const
{
	return m_Value.x;
}

float Hikari::Vector3::GetY( void ) const
{
	return m_Value.y;
}

float Hikari::Vector3::GetZ( void ) const
{
	return m_Value.z;
}

void Hikari::Vector3::SetX( float x )
{
	m_Value.x = x;
}

void Hikari::Vector3::SetY( float y )
{
	m_Value.y = y;
}

void Hikari::Vector3::SetZ( float z )
{
	m_Value.z = z;
}
