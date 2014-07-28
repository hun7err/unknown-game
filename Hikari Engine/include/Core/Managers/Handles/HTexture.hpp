#ifndef __HTEXTURE_HPP__
#define __HTEXTURE_HPP__

//#include "TextureManager.hpp"
#include "Handle.hpp"
#include "../../../Core/Textures/Interface/Texture.hpp"

#include <cstddef>

namespace Hikari
{
	class HTexture : public Handle<Texture>
	{
		public:
			HTexture(int key = -1);

			Texture* operator->(void) const;
			bool isValid(void);
			void operator=(std::nullptr_t value);
	};
}

#endif 