#ifndef __POSITIONHPP__
#define __POSITIONHPP__

#include "../../Core/Components/ComponentTypeWrapper.hpp"

#include "../../Helpers/ECS/Component.hpp"
#include "../../Helpers/Math/Vector3D.hpp"

namespace Hikari
{
	namespace Components
	{
		class Position : public Helpers::ComponentTypeWrapper<Hikari::Vector3D>, public Component
		{
			public:
				Position(float x = 0.0f, float y = 0.0f, float z = 0.0f);
				void SetValue(const Vector2D& newValue);

		};
	}
}

#endif