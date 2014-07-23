#include "../include/MaterialManager.hpp"

std::vector<Hikari::Material*> Hikari::Manager<Hikari::Material>::m_Items;
std::mutex Hikari::Manager<Hikari::Material>::m_ItemMutex;

Hikari::MaterialManager::MaterialManager()
{
}

Hikari::HMaterial Hikari::MaterialManager::add(Hikari::Material *pMaterial)
{
	int key = Manager::add(pMaterial);
	return HMaterial(key);
}
