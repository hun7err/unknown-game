#include "../../../include/Core/Managers/TextureManager.hpp"
#include "../../../include/Core/Textures/Texture2D.hpp"

std::vector<Hikari::Texture*> Hikari::Manager<Hikari::Texture>::m_Items;
std::mutex Hikari::Manager<Hikari::Texture>::m_ItemMutex;

Hikari::TextureManager::TextureManager()
{
}

Hikari::HTexture Hikari::TextureManager::add(Hikari::Texture *pTexture)
{
	int key = Manager::add(pTexture);

	return HTexture(key);
}

Hikari::HTexture Hikari::TextureManager::load2D(std::string filename)
{
	Hikari::Texture2D *pTexture = new Hikari::Texture2D();
	pTexture->load(filename);
	
	int key = Manager::add(pTexture);
	return HTexture(key);
}
