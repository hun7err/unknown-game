#ifndef __BOOLHPP__
#define __BOOLHPP__

#include "../../Core/Components/ComponentTypeWrapper.hpp"
#include "../../Helpers/ECS/Component.hpp"

#include <string>

namespace Hikari
{
	namespace Components
	{
		class Bool : public Helpers::ComponentTypeWrapper<bool>, public Component
		{
			public:
				Bool( const std::string& ID, bool defaultValue = true );
		};
	}
}

#endif