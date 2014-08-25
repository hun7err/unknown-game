#ifndef __HIKARI_SIZEHPP__
#define __HIKARI_SIZEHPP__

#include "../../Helpers/ECS/ComponentTypeWrapper.hpp"

#include "../../Helpers/ECS/Component.hpp"
#include "../../Core/Math/Vector3.hpp"
#include "../../Core/Math/Vector2.hpp"

namespace Hikari
{
	namespace Components
	{
		class Size : public Helpers::ComponentTypeWrapper<Hikari::Vector3>, public Component
		{
			public:
				Size( float width = 0, float height = 0, float depth = 0 );

				void SetValue( const Vector2& newValue );
				void SetValue( float width, float height, float depth = 0.0f );

		};
	}
}

#endif