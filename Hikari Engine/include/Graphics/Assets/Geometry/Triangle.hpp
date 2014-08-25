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
				Triangle( const std::string& AssetID, DirectX::XMFLOAT3 p1, DirectX::XMFLOAT3 p2, DirectX::XMFLOAT3 p3 );

			private:
		};
	}
}

#endif