#ifndef __TEXTUREMANAGER_HPP__
#define __TEXTUREMANAGER_HPP__

#include "Texture.hpp"
#include "Manager.hpp"

namespace Hikari
{
	typedef Manager<Texture> TextureManager;

	std::vector<Texture*> TextureManager::m_Items;
	std::mutex TextureManager::m_ItemMutex;
}

#endif