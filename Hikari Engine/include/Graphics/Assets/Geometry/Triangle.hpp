#ifndef __HIKARI_GRAPHICS_ASSETS_GEOMETRY_TRIANGLEHPP__
#define __HIKARI_GRAPHICS_ASSETS_GEOMETRY_TRIANGLEHPP__

#include "Geometry.hpp"
#include "../../../Helpers/Math/Vector3D.hpp"
#include <string>
#include <DirectXMath.h>

namespace Hikari
{
	namespace Geometry
	{
		class Triangle : public Assets::Geometry
		{
			public:
				Triangle( const std::string& AssetID, DirectX::XMFLOAT4 p1, DirectX::XMFLOAT4 p2, DirectX::XMFLOAT4 p3 );

			private:
		};
	}
}

#endif