#ifndef __HIKARI_SIZEHPP__
#define __HIKARI_SIZEHPP__

#include "../../Core/Components/ComponentTypeWrapper.hpp"

#include "../../Helpers/ECS/Component.hpp"
#include "../../Helpers/Math/Vector3D.hpp"

namespace Hikari
{
	namespace Components
	{
		class Size : public Helpers::ComponentTypeWrapper<Hikari::Vector3D>, public Component
		{
			public:
				Size( float width = 0, float height = 0, float depth = 0 );

				void SetValue( const Vector2D& newValue );
				void SetValue( float width, float height, float depth = 0.0f );

		};
	}
}

#endif