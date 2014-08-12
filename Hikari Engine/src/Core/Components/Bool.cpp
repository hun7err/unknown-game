#include "../../../include/Core/Components/Bool.hpp"

Hikari::Components::Bool::Bool( const std::string& ID , bool defaultValue ) : Component( ID )
{
	m_Value = defaultValue;
}
