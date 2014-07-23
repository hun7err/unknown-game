#include "../include/HShader.hpp"
#include "../include/ShaderManager.hpp"

Hikari::HShader::HShader(int key) : Handle(key)
{
}

Hikari::ShaderProgram* Hikari::HShader::operator->(void) const
{
	return Hikari::ShaderManager::get(m_ItemKey);
}

bool Hikari::HShader::isValid(void)
{
	return Hikari::ShaderManager::isValidKey(m_ItemKey);
}

void Hikari::HShader::operator=(std::nullptr_t value)
{
	m_ItemKey = -1;
}
