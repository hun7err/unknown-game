#include "../../include/Managers/TextureManager.hpp"

std::vector<Hikari::Texture*> Hikari::Manager<Hikari::Texture>::m_Items;
std::mutex Hikari::Manager<Hikari::Texture>::m_ItemMutex;

Hikari::HTexture Hikari::TextureManager::add(Hikari::Texture *pTexture)
{
	int key = Manager::add(pTexture);
	return HTexture(key);
}
