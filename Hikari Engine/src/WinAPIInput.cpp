#include "../include/WinAPIInput.hpp"
#include "../include/Exception.hpp"

Hikari::WinAPIInput::WinAPIInput()
{
}

Hikari::WinAPIInput::WinAPIInput(const Hikari::WinAPIInput& other)
{
}

Hikari::WinAPIInput::~WinAPIInput()
{
}

void Hikari::WinAPIInput::setup()
{
	int i;

	//std::function<void(Hikari::Engine*)> defaultFunction = [](Hikari::Engine*) {};
	std::function<void(Hikari::Engine*)> defaultFunction = nullptr;
	for(i = 0; i < 256; i++)
	{
		m_Keys[i] = std::make_pair(false, defaultFunction);
	}
}

void Hikari::WinAPIInput::keyDown(unsigned int key)
{
	if(key >= 256)
	{
		throw Exception("Nieprawidlowy kod przycisku w KeyDown", "InvalidKeyException");
	}
	m_Keys[key].first = true;
}

void Hikari::WinAPIInput::keyUp(unsigned int key)
{
	if(key >= 256)
	{
		throw Exception("Nieprawidlowy kod przycisku w KeyUp", "InvalidKeyException");
	}
	m_Keys[key].first = false;
}

bool Hikari::WinAPIInput::isKeyDown(unsigned int key)
{
	if(key >= 256)
	{
		throw Exception("Nieprawidlowy kod przycisku w isKeyDown", "InvalidKeyException");
	}
	return m_Keys[key].first;
}

std::function<void(Hikari::Engine*)> Hikari::WinAPIInput::keyHandler(unsigned int key)
{
	if(key >= 256)
	{
		throw Exception("Nieprawidlowy kod przycisku w KeyUp", "InvalidKeyException");
	}

	return m_Keys[key].second;
}

void Hikari::WinAPIInput::keyHandler(unsigned int key, std::function<void(Hikari::Engine*)> keyHandler)
{
	if(key >= 256)
	{
		throw Exception("Nieprawidlowy kod przycisku w keyHandler(std::function<void(Hikari::Engine*)>)", "InvalidKeyException");
	}

	m_Keys[key].second = keyHandler;
}
