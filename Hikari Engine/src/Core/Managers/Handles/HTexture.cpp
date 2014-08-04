#include "../../../../include/Core/Managers/Handles/HTexture.hpp"
#include "../../../../include/Core/Managers/TextureManager.hpp"

Hikari::HTexture::HTexture(int key) : Handle(key)
{
}

Hikari::Texture* Hikari::HTexture::operator->(void) const
{
	return Hikari::TextureManager::get(m_ItemKey);
}

bool Hikari::HTexture::isValid(void)
{
	return Hikari::TextureManager::isValidKey(m_ItemKey);
}

void Hikari::HTexture::operator=(std::nullptr_t value)
{
	m_ItemKey = -1;
}
