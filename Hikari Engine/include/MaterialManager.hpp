#ifndef __MATERIALMANAGER_HPP__
#define __MATERIALMANAGER_HPP__

#include "Material.hpp"
#include "Manager.hpp"

namespace Hikari
{
	typedef Manager<Material> MaterialManager;

	std::vector<Material*> MaterialManager::m_Items;
	std::mutex MaterialManager::m_ItemMutex;
}

#endif