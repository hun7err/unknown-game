#ifndef __SHADERMANAGER_HPP__
#define __SHADERMANAGER_HPP__

#include "D3D11ShaderProgram.hpp"
#include "Manager.hpp"

namespace Hikari
{
	typedef Manager<D3D11ShaderProgram> ShaderManager;

	std::vector<D3D11ShaderProgram*> ShaderManager::m_Items;
	std::mutex ShaderManager::m_ItemMutex;
}

#endif