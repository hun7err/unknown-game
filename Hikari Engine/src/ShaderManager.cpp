#include "../include/ShaderManager.hpp"

std::vector<Hikari::ShaderProgram*> Hikari::Manager<Hikari::ShaderProgram>::m_Items;
std::mutex Hikari::Manager<Hikari::ShaderProgram>::m_ItemMutex;

Hikari::HShader Hikari::ShaderManager::add(Hikari::ShaderProgram *pShader)
{
	int key = Manager::add(pShader);
	return HShader(key);
}
