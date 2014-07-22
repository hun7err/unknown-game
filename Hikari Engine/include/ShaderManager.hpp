#ifndef __SHADERMANAGER_HPP__
#define __SHADERMANAGER_HPP__

#include "ShaderProgram.hpp"
#include "Manager.hpp"

namespace Hikari
{
	typedef Manager<ShaderProgram> ShaderManager;

	std::vector<ShaderProgram*> ShaderManager::m_Items;
	std::mutex ShaderManager::m_ItemMutex;
}

#endif // __SHADERMANAGER_HPP__