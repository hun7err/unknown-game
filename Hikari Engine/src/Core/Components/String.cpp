#include "../../../include/Core/Components/String.hpp"

Hikari::Components::String::String( const std::string& ID ) : Component( ID )
{
	m_Value = "";
}

Hikari::Components::String::String( const std::string& ID, const std::string& value ) : Component( ID )
{
	m_Value = value;
}
