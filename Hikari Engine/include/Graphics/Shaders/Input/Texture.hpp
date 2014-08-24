#ifndef __HIKARI_GRAPHICS_SHADERS_INPUT_TEXTUREHPP__
#define __HIKARI_GRAPHICS_SHADERS_INPUT_TEXTUREHPP__

#include "../../../Helpers/ECS/Component.hpp"
#include "../../../Helpers/ECS/Entity.hpp"

namespace Hikari
{
	namespace Shaders
	{
		namespace Input
		{
			class Texture : public Entity, public Component
			{
				public:
					Texture( const std::string& TextureID );
			};
		}
	}
}

#endif