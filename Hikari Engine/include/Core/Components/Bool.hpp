#ifndef __HIKARI_CORE_COMPONENTS_BOOLHPP__
#define __HIKARI_CORE_COMPONENTS_BOOLHPP__

#include "../../Helpers/ECS/ComponentTypeWrapper.hpp"
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