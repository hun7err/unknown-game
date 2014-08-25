#ifndef __HIKARI_GRAPHICS_ASSETS_GEOMETRY_TRIANGLEHPP__
#define __HIKARI_GRAPHICS_ASSETS_GEOMETRY_TRIANGLEHPP__

#include "Geometry.hpp"
#include "../../../Core/Math/Vector3.hpp"
#include <string>
#include <DirectXMath.h>

namespace Hikari
{
	namespace Geometry
	{
		class Triangle : public Assets::Geometry
		{
			public:
				Triangle( const std::string& AssetID, Vector3 p1, Vector3 p2, Vector3 p3 );

			private:
		};
	}
}

#endif