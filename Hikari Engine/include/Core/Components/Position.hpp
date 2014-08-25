#ifndef __HIKARI_CORE_COMPONENTS_POSITIONHPP__
#define __HIKARI_CORE_COMPONENTS_POSITIONHPP__

#include "../../Helpers/ECS/ComponentTypeWrapper.hpp"

#include "../../Helpers/ECS/Component.hpp"
#include "../../Core/Math/Vector3.hpp"
#include "../../Core/Math/Vector2.hpp"

namespace Hikari
{
	namespace Components
	{
		class Position : public Helpers::ComponentTypeWrapper<Hikari::Vector3>, public Component
		{
			public:
				Position(float x = 0.0f, float y = 0.0f, float z = 0.0f);
				void SetValue(const Vector2& newValue);

		};
	}
}

#endif