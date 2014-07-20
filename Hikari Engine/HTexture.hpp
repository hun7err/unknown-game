#ifndef __HTEXTURE_HPP__
#define __HTEXTURE_HPP__

#include "TextureManager.hpp"
#include "Handle.hpp"

#include <cstddef>

namespace Hikari
{
	class HTexture : public Handle<Texture>
	{
		public:
			Texture* operator->(void) const
			{
				return TextureManager::get(m_ItemKey);
			}

			bool isValid(void)
			{
				return TextureManager::isValidKey(m_ItemKey);
			}

			void operator=(std::nullptr_t value)
			{
				m_ItemKey = -1;
			}
	};
}

#endif 