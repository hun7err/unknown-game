#ifndef __HIKARI_GRAPHICS_ASSETS_SHADERPROGRAMHPP__
#define __HIKARI_GRAPHICS_ASSETS_SHADERPROGRAMHPP__

#include "../../Helpers/ECS/Component.hpp"
#include "../../Helpers/ECS/Entity.hpp"
#include "../../Core/ErrorCode.hpp"
#include "Asset.hpp"

#include <DirectXMath.h>
#include <d3d11.h>

namespace Hikari
{
	namespace Assets
	{
		class ShaderProgram : public Entity, public Component, public Asset
		{
			public:
				ShaderProgram( const std::string& AssetID );
				virtual ~ShaderProgram();

				ErrorCode Load( const std::string& filename );
				ErrorCode Export( const std::string& filename );

				ErrorCode Compile( ID3D11Device *pDevice );

			private:
		};
	}
}

#endif