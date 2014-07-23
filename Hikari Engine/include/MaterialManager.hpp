#ifndef __MATERIALMANAGER_HPP__
#define __MATERIALMANAGER_HPP__

#include "Material.hpp"
#include "Manager.hpp"
#include "HMaterial.hpp"

namespace Hikari
{
	class MaterialManager : public Manager<Material>
	{
		public:
			static HMaterial add(Material *pMaterial);

		private:
			MaterialManager();
	};
}

#endif // __MATERIALMANAGER_HPP__