#include "../../../include/Core/Components/Float.hpp"

Hikari::Components::Float::Float( const std::string& ComponentID ) : Component( ComponentID )
{
}

Hikari::Components::Float::Float( const std::string& ComponentID, float defaultValue ) : Component( ComponentID )
{
	m_Value = defaultValue;
}

float Hikari::Components::Float::GetMinValue( void )
{
	return m_MinValue;
}

float Hikari::Components::Float::GetMaxValue( void )
{
	return m_MaxValue;
}

void Hikari::Components::Float::SetMinValue( float minValue )
{
	m_MinValue = minValue;
}

void Hikari::Components::Float::SetMaxValue( float maxValue )
{
	m_MaxValue = maxValue;
}
