#include "WinAPIInput.hpp"
#include "Exception.hpp"

Hikari::WinAPIInput::WinAPIInput()
{
}

Hikari::WinAPIInput::WinAPIInput(const Hikari::WinAPIInput& other)
{
}

Hikari::WinAPIInput::~WinAPIInput()
{
}

void Hikari::WinAPIInput::Setup()
{
	int i;

	for(i = 0; i < 256; i++)
	{
		m_Keys[i] = false;
	}
}

void Hikari::WinAPIInput::KeyDown(unsigned int key)
{
	if(key >= 256)
	{
		throw new Exception("Nieprawidlowy kod przycisku w KeyDown", "InvalidKeyException");
	}
	m_Keys[key] = true;
}

void Hikari::WinAPIInput::KeyUp(unsigned int key)
{
	if(key >= 256)
	{
		throw new Exception("Nieprawidlowy kod przycisku w KeyUp", "InvalidKeyException");
	}
	m_Keys[key] = false;
}

bool Hikari::WinAPIInput::isKeyDown(unsigned int key)
{
	if(key >= 256)
	{
		throw new Exception("Nieprawidlowy kod przycisku w isKeyDown", "InvalidKeyException");
	}
	return m_Keys[key];
}
