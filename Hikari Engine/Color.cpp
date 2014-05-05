#include "Color.hpp"

Hikari::Color::Color(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f)
{
	m_Red = red;
	m_Green = green;
	m_Blue = blue;
	m_Alpha = alpha;
}

float Hikari::Color::red(void)
{
	if(m_Red < 0.0f)
	{
		m_Red = 0.0f;
	}
	else if(m_Red > 1.0f)
	{
		m_Red = 1.0f;
	}

	return m_Red;
}

void Hikari::Color::red(float red)
{
	m_Red = red;
}

float Hikari::Color::green(void)
{
	if(m_Green < 0.0f)
	{
		m_Green = 0.0f;
	}
	else if(m_Green > 1.0f)
	{
		m_Green = 1.0f;
	}

	return m_Green;
}

void Hikari::Color::green(float green)
{
	m_Green = green;
}

float Hikari::Color::blue(void)
{
	if(m_Blue < 0.0f)
	{
		m_Blue = 0.0f;
	}
	else if(m_Blue > 1.0f)
	{
		m_Blue = 1.0f;
	}

	return m_Blue;
}

void Hikari::Color::blue(float blue)
{
	m_Blue = blue;
}

float Hikari::Color::alpha(void)
{
	if(m_Alpha < 0.0f)
	{
		m_Alpha = 0.0f;
	}
	else if(m_Alpha > 1.0f)
	{
		m_Alpha = 1.0f;
	}

	return m_Alpha;
}

void Hikari::Color::alpha(float alpha)
{
	m_Alpha = alpha;
}

float* Hikari::Color::components(void)
{
	return &m_Red;
}

void Hikari::Color::components(float* components)
{
	m_Red = components[0];
	m_Green = components[1];
	m_Blue = components[2];
	m_Alpha = components[3];
}
