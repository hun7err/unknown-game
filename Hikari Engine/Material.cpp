#include "Material.hpp"

Hikari::Material::Material()
{
}

Hikari::Material::Material(std::string name)
{
	m_Name = name;
}

Hikari::Material::Material()
{
}

std::string Hikari::Material::name(void)
{
	return m_Name;
}

void Hikari::Material::name(std::string name)
{
	m_Name = name;
}
