#include "../include/Texture.hpp"

Hikari::Texture::Texture() : m_Name("NoName")
{
}

Hikari::Texture::Texture(std::string name) : m_Name(name)
{
}

void Hikari::Texture::createImage(void)
{
	ilGenImages(1, &m_ilImageName);
}

Hikari::Texture::~Texture()
{
	ilDeleteImages(1, &m_ilImageName);
}

/*
	Og�lnie rzecz bior�c nie jest to dobry pomys�, wi�c dobrze by�oby zrobi� co� w stylu ILContext(), kt�re by�oby Singletonem maj�cym w�asny mutex pozwalaj�cy tylko w jednym momencie mie� podpi�ty jeden obraz
*/
void Hikari::Texture::bind(void)
{
	ilBindImage(m_ilImageName);
}

ILuint Hikari::Texture::ilImageName(void)
{
	return m_ilImageName;
}

void Hikari::Texture::ilImageName(ILuint newILImageName)
{
	m_ilImageName = newILImageName;
}

unsigned int Hikari::Texture::width(void)
{
	bind();	// czy lepiej liczy� na to, �e user zbinduje sam?
	return ilGetInteger(IL_IMAGE_WIDTH);
}

unsigned int Hikari::Texture::height(void)
{
	bind();
	return ilGetInteger(IL_IMAGE_HEIGHT);
}

unsigned char* Hikari::Texture::data(void)
{
	bind();
	return ilGetData();
}

unsigned int Hikari::Texture::size(void)
{
	bind();
	int bpp = ilGetInteger(IL_IMAGE_BPP),
		height = ilGetInteger(IL_IMAGE_HEIGHT),
		width = ilGetInteger(IL_IMAGE_WIDTH);
	
	int size = bpp * height * width / 8;	// bo rozmiar jest w bajtach
	return size;
}

void Hikari::Texture::name(std::string name)
{
	m_Name = name;
}

std::string Hikari::Texture::name(void)
{
	return m_Name;
}
