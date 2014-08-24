#ifndef __HIKARI_GRAPHICS_ASSETS_MATERIALHPP__
#define __HIKARI_GRAPHICS_ASSETS_MATERIALHPP__

#include "../../Helpers/ECS/Entity.hpp"
#include "Asset.hpp"

namespace Hikari
{
	namespace Assets
	{
		class Material : public Asset, public Entity, public Component
		{
			public:
				Material( void );
				Material( const std::string& AssetID );

			private:
		};
	}
}

#endif