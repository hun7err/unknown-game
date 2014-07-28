#include "../../../../include/Core/Managers/Handles/HMaterial.hpp"
#include "../../../../include/Core/Managers/MaterialManager.hpp"

Hikari::HMaterial::HMaterial(int key) : Handle(key)
{
}

Hikari::Material* Hikari::HMaterial::operator->(void) const
{
	return Hikari::MaterialManager::get(m_ItemKey);
}

bool Hikari::HMaterial::isValid(void)
{
	return MaterialManager::isValidKey(m_ItemKey);
}
