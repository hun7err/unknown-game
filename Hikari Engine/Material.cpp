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

void Hikari::Material::diffuseColor(float r, float g, float b, float a = 1.0f)
{
	m_DiffuseColor.f[0] = r;
	m_DiffuseColor.f[1] = g;
	m_DiffuseColor.f[2] = b;
	m_DiffuseColor.f[3] = a;
}

DirectX::XMVECTORF32 Hikari::Material::specularColor(void)
{
	return m_SpecularColor;
}

void Hikari::Material::specularColor(DirectX::XMVECTORF32 *newSpecularColor)
{
	m_SpecularColor = *newSpecularColor;
}

void Hikari::Material::specularColor(float r, float g, float b, float a = 1.0f)
{
	m_SpecularColor.f[0] = r;
	m_SpecularColor.f[1] = g;
	m_SpecularColor.f[2] = b;
	m_SpecularColor.f[3] = a;
}

DirectX::XMVECTORF32 Hikari::Material::ambientColor(void)
{
	return m_AmbientColor;
}

void Hikari::Material::ambientColor(DirectX::XMVECTORF32 *newAmbientColor)
{
	m_AmbientColor = *newAmbientColor;
}

void Hikari::Material::ambientColor(float r, float g, float b, float a = 1.0f)
{
	m_AmbientColor.f[0] = r;
	m_AmbientColor.f[1] = g;
	m_AmbientColor.f[2] = b;
	m_AmbientColor.f[3] = a;
}

DirectX::XMVECTORF32 Hikari::Material::emissiveColor(void)
{
	return m_EmissiveColor;
}

void Hikari::Material::emissiveColor(DirectX::XMVECTORF32 *newEmissiveColor)
{
	m_EmissiveColor = *newEmissiveColor;
}

void Hikari::Material::emissiveColor(float r, float g, float b, float a = 1.0f)
{
	m_EmissiveColor.f[0] = r;
	m_EmissiveColor.f[1] = g;
	m_EmissiveColor.f[2] = b;
	m_EmissiveColor.f[3] = a;
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
