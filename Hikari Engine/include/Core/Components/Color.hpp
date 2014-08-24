#ifndef __HIKARI_CORE_COMPONENTS_COLORHPP__
#define __HIKARI_CORE_COMPONENTS_COLORHPP__

#include "../../Helpers/ECS/Component.hpp"
#include "../../Helpers/ECS/ComponentTypeWrapper.hpp"
#include <DirectXMath.h>

namespace Hikari
{
	namespace Components
	{
		class Color : public Component, public Helpers::ComponentTypeWrapper<DirectX::XMVECTORF32>
		{
			public:
				Color( const std::string& ComponentID, float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 0.0f );

				float GetRed( void ) const;
				float GetGreen( void ) const;
				float GetBlue( void ) const;
				float GetAlpha( void ) const;

				void SetRGB( float red, float green, float blue, float alpha );

				void SetRed( float red );
				void SetGreen( float green );
				void SetBlue( float blue );
				void SetAlpha( float alpha );

			private:
		};
	}
}

#endif