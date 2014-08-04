#include "../../../../include/Core/Textures/Interface/Texture.hpp"

Hikari::Texture::Texture() : m_Name("NoName")
{
}

Hikari::Texture::Texture(std::string name) : m_Name(name)
{
}

Hikari::Texture::~Texture()
{
	if(m_pShaderResourceView)
	{
		m_pShaderResourceView->Release();
		m_pShaderResourceView = nullptr;
	}
}

ID3D11ShaderResourceView *Hikari::Texture::shaderResourceView(void)
{
	return m_pShaderResourceView;
}

void Hikari::Texture::name(std::string name)
{
	m_Name = name;
}

std::string Hikari::Texture::name(void)
{
	return m_Name;
}
