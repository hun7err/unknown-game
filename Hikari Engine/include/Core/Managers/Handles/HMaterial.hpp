#ifndef __HMATERIAL_HPP__
#define __HMATERIAL_HPP__

#include "Handle.hpp"
#include "../../../Core/Materials/Material.hpp"

namespace Hikari
{
	class HMaterial : public Handle<Material>
	{
		public:
			HMaterial(int key = -1);
			Material* operator->(void) const;
			bool isValid(void);
	};
}

#endif