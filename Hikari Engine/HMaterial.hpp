#ifndef __HMATERIAL_HPP__
#define __HMATERIAL_HPP__

#include "MaterialManager.hpp"
#include "Handle.hpp"

namespace Hikari
{
	class HMaterial : public Handle<Material>
	{
		public:
			Material* operator->(void) const
			{
				return MaterialManager::get(m_ItemKey);
			}

			bool isValid(void)
			{
				return MaterialManager::isValidKey(m_ItemKey);
			}
	};
}

#endif