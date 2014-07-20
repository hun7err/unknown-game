#include "Material.hpp"
#include <DirectXColors.h>

Hikari::Material::Material() : m_Name("NoName")
{
	initialize();
}

Hikari::Material::Material(std::string name)
{
	m_Name = name;
	initialize();
}

void Hikari::Material::initialize(void)
{
	m_DiffuseColor = DirectX::Colors::WhiteSmoke;
	m_SpecularColor = DirectX::Colors::White;
	m_EmissiveColor = DirectX::Colors::Black;
	m_AmbientColor = DirectX::Colors::Black;
	m_DiffuseMap = nullptr;
	m_BumpMap = nullptr;
	m_SpecularMap = nullptr;
	m_NormalMap = nullptr;
	m_Shininess = 0.5f;
}

Hikari::Material::~Material()
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

DirectX::XMVECTORF32 Hikari::Material::diffuseColor(void)
{
	return m_DiffuseColor;
}

void Hikari::Material::diffuseColor(DirectX::XMVECTORF32 *newDiffuseColor)
{
	m_DiffuseColor = *newDiffuseColor;
}

DirectX::XMVECTORF32 Hikari::Material::specularColor(void)
{
	return m_SpecularColor;
}

void Hikari::Material::specularColor(DirectX::XMVECTORF32 *newSpecularColor)
{
	m_SpecularColor = *newSpecularColor;
}

DirectX::XMVECTORF32 Hikari::Material::ambientColor(void)
{
	return m_AmbientColor;
}

void Hikari::Material::ambientColor(DirectX::XMVECTORF32 *newAmbientColor)
{
	m_AmbientColor = *newAmbientColor;
}

DirectX::XMVECTORF32 Hikari::Material::emissiveColor(void)
{
	return m_EmissiveColor;
}

void Hikari::Material::emissiveColor(DirectX::XMVECTORF32 *newEmissiveColor)
{
	m_EmissiveColor = *newEmissiveColor;
}

Hikari::HTexture Hikari::Material::diffuseMap(void)
{
	return m_DiffuseMap;
}

void Hikari::Material::diffuseMap(Hikari::HTexture newDiffuseMap)
{
	if(newDiffuseMap.isValid())
	{
		m_DiffuseMap = newDiffuseMap;
	}
}

Hikari::HTexture Hikari::Material::specularMap(void)
{
	return m_SpecularMap;
}

void Hikari::Material::specularMap(Hikari::HTexture newSpecularMap)
{
	if(newSpecularMap.isValid())
	{
		m_SpecularMap = newSpecularMap;
	}
}

Hikari::HTexture Hikari::Material::normalMap(void)
{
	return m_NormalMap;
}

void Hikari::Material::normalMap(Hikari::HTexture newNormalMap)
{
	if(newNormalMap.isValid())
	{
		m_NormalMap = newNormalMap;
	}
}

Hikari::HTexture Hikari::Material::bumpMap(void)
{
	return m_BumpMap;
}

void Hikari::Material::bumpMap(Hikari::HTexture newBumpMap)
{
}
