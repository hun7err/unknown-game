#include "../../include/Helpers/Vector.hpp"

Hikari::Vector2D::Vector2D() : m_x(0), m_y(0)
{
}

Hikari::Vector2D::Vector2D(float x, float y): m_x(x), m_y(y)
{
}

float Hikari::Vector2D::x(void) const
{
	 return m_x;
}

float Hikari::Vector2D::y(void) const
{
	 return m_y;
}

void Hikari::Vector2D::x(float x)
{
	m_x = x;
}

void Hikari::Vector2D::y(float y)
{
	m_y = y;
}

Hikari::Vector3D::Vector3D(float x, float y, float z) : Vector2D(x, y), m_z(z)
{
}

Hikari::Vector3D::Vector3D(const Vector3D& rVector) : Vector2D(rVector.m_x, rVector.m_y), m_z(rVector.m_z)
{
}

Hikari::Vector3D::Vector3D(const Vector3D& start, const Vector3D& end) : Vector2D(end.x()-start.x(), end.y()-start.y()), m_z(end.z()-start.z())
{
}

float Hikari::Vector3D::z(void) const
{
	 return m_z;
}

void Hikari::Vector3D::z(float z)
{
	m_z = z;
}

float Hikari::Vector3D::length(void) const
{
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

float Hikari::Vector3D::lengthSqrd(void) const
{
	return m_x * m_x + m_y * m_y + m_z * m_z;
}

void Hikari::Vector3D::normalize(void)
{
	float len = length();
	m_x /= len;
	m_y /= len;
	m_z /= len;
}

Hikari::Vector3D Hikari::Vector3D::normalized(void)
{
	float len = length();
	return Vector3D(m_x/len, m_y/len, m_z/len);
}

Hikari::Vector3D Hikari::operator+ (const Hikari::Vector3D& rFirst, const Hikari::Vector3D& rSecond)
{
	return Hikari::Vector3D(
							rFirst.m_x + rSecond.m_x,
							rFirst.m_y + rSecond.m_y,
							rFirst.m_z + rSecond.m_z
							);
}

Hikari::Vector3D Hikari::operator- (const Hikari::Vector3D& rFirst, const Hikari::Vector3D& rSecond)
{
	return Hikari::Vector3D(
							rFirst.m_x - rSecond.m_x,
							rFirst.m_y - rSecond.m_y,
							rFirst.m_z - rSecond.m_z
							);
}

Hikari::Vector4D::Vector4D(float x, float y, float z, float w) : Vector3D(x, y, z), m_w(w)
{
}

Hikari::Vector4D::Vector4D(const Vector3D& rVector, float w) : Vector3D(rVector), m_w(w)
{
}

Hikari::Vector4D::Vector4D(const Vector3D& rStart, const Vector3D& rEnd) : Vector3D(rEnd - rStart), m_w(0)
{
} // czy na pewno 0 to wektor?

float Hikari::Vector4D::w(void) const
{
	return m_w;
}

void Hikari::Vector4D::w(float w)
{
	m_w = w;
}