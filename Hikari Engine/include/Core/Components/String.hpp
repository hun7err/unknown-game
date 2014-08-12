#ifndef __HIKARI_STRINGHPP__
#define __HIKARI_STRINGHPP__

#include "../../Core/Components/ComponentTypeWrapper.hpp"

#include "../../Helpers/ECS/Component.hpp"
#include <string>

namespace Hikari
{
	namespace Components
	{
		class String : public Helpers::ComponentTypeWrapper<std::string>, public Component
		{
			public:
				String( const std::string& ID );
				String( const std::string& ID, const std::string& value );

		};
	}
}

#endif