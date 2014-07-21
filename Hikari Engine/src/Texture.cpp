#include "../include/Texture.hpp"

Hikari::Texture::Texture() : m_Name("NoName") {}

Hikari::Texture::Texture(std::string name) : m_Name(name) {}

void Hikari::Texture::name(std::string name)
{
	m_Name = name;
}

std::string Hikari::Texture::name(void)
{
	return m_Name;
}
