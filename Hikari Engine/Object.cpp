#include "Object.hpp"

Hikari::Object::Object()
{
}

Hikari::Object::Object(std::string name)
{
	m_Name = name;
}

Hikari::Object::~Object()
{
}

std::string Hikari::Object::name(void)
{
	return m_Name;
}

void Hikari::Object::name(std::string name)
{
	m_Name = name;
}
