#include "../../../include/Core/Components/Color.hpp"

inline void clamp( float *pValue, float minValue, float maxValue )
{
	if( *pValue < minValue )
	{
		*pValue = minValue;
	}
	if( *pValue > maxValue )
	{
		*pValue = maxValue;
	}
}

Hikari::Components::Color::Color( const std::string& ComponentID, float red, float green, float blue, float alpha ) : Component( ComponentID )
{
	clamp( &red, 0, 1 );
	clamp( &green, 0, 1 );
	clamp( &blue, 0, 1 );
	clamp( &alpha, 0, 1 );

	m_Value.f[0] = red;
	m_Value.f[1] = green;
	m_Value.f[2] = blue;
	m_Value.f[3] = alpha;
}

float Hikari::Components::Color::GetRed( void ) const
{
	return m_Value.f[0];
}

float Hikari::Components::Color::GetGreen( void ) const
{
	return m_Value.f[1];
}

float Hikari::Components::Color::GetBlue( void ) const
{
	return m_Value.f[2];
}

float Hikari::Components::Color::GetAlpha( void ) const
{
	return m_Value.f[3];
}

void Hikari::Components::Color::SetRGB( float red, float green, float blue, float alpha )
{
	clamp( &red, 0, 1 );
	clamp( &green, 0, 1 );
	clamp( &blue, 0, 1 );
	clamp( &alpha, 0, 1 );

	m_Value.f[0] = red;
	m_Value.f[1] = green;
	m_Value.f[2] = blue;
	m_Value.f[3] = alpha;
}

void Hikari::Components::Color::SetAlpha( float alpha )
{
	clamp( &alpha, 0, 1 );
	
	m_Value.f[3] = alpha;
}

void Hikari::Components::Color::SetRed( float red )
{
	clamp( &red, 0, 1 );

	m_Value.f[0] = red;
}

void Hikari::Components::Color::SetGreen( float green )
{
	clamp( &green, 0, 1 );

	m_Value.f[1] = green;
}

void Hikari::Components::Color::SetBlue( float blue )
{
	clamp( &blue, 0, 1 );

	m_Value.f[2] = blue;
}
