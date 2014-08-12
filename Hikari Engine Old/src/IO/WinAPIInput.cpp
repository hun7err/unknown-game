#include "../../include/IO/WinAPIInput.hpp"
#include "../../include/Helpers/Exception.hpp"

Hikari::IO::WinAPIInput::WinAPIInput()
{
}

Hikari::IO::WinAPIInput::WinAPIInput(const Hikari::IO::WinAPIInput& other)
{
}

Hikari::IO::WinAPIInput::~WinAPIInput()
{
}

void Hikari::IO::WinAPIInput::setup()
{
	int i;

	//std::function<void(Hikari::IO::Engine*)> defaultFunction = [](Hikari::IO::Engine*) {};
	std::function<void(void)> defaultFunction = nullptr;
	for(i = 0; i < 256; i++)
	{
		m_Keys[i] = std::make_pair(false, defaultFunction);
	}
}

void Hikari::IO::WinAPIInput::keyDown(unsigned int key)
{
	if(key >= 256)
	{
		throw Exception("Nieprawidlowy kod przycisku w KeyDown", "InvalidKeyException");
	}
	m_Keys[key].first = true;
}

void Hikari::IO::WinAPIInput::keyUp(unsigned int key)
{
	if(key >= 256)
	{
		throw Exception("Nieprawidlowy kod przycisku w KeyUp", "InvalidKeyException");
	}
	m_Keys[key].first = false;
}

bool Hikari::IO::WinAPIInput::isKeyDown(unsigned int key)
{
	if(key >= 256)
	{
		throw Exception("Nieprawidlowy kod przycisku w isKeyDown", "InvalidKeyException");
	}
	return m_Keys[key].first;
}

std::function<void(void)> Hikari::IO::WinAPIInput::keyHandler(unsigned int key)
{
	if(key >= 256)
	{
		throw Exception("Nieprawidlowy kod przycisku w KeyUp", "InvalidKeyException");
	}

	return m_Keys[key].second;
}

void Hikari::IO::WinAPIInput::keyHandler(unsigned int key, std::function<void(void)> keyHandler)
{
	if(key >= 256)
	{
		throw Exception("Nieprawidlowy kod przycisku w keyHandler(std::function<void(Hikari::IO::Engine*)>)", "InvalidKeyException");
	}

	m_Keys[key].second = keyHandler;
}
