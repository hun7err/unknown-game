#include "../include/Vector.hpp"

Hikari::Vector2D::Vector2D() : m_x(0), m_y(0)
{
}

Hikari::Vector2D::Vector2D(double x, double y): m_x(x), m_y(y)
{
}

double Hikari::Vector2D::x(void) const
{
	 return m_x;
}

double Hikari::Vector2D::y(void) const
{
	 return m_y;
}

void Hikari::Vector2D::x(double x)
{
	m_x = x;
}

void Hikari::Vector2D::y(double y)
{
	m_y = y;
}

Hikari::Vector3D::Vector3D(double x, double y, double z) : Vector2D(x, y), m_z(z)
{
}

Hikari::Vector3D::Vector3D(const Vector3D& rVector) : Vector2D(rVector.m_x, rVector.m_y), m_z(rVector.m_z)
{
}

Hikari::Vector3D::Vector3D(const Vector3D& start, const Vector3D& end) : Vector2D(end.x()-start.x(), end.y()-start.y()), m_z(end.z()-start.z())
{
}

double Hikari::Vector3D::z(void) const
{
	 return m_z;
}

void Hikari::Vector3D::z(double z)
{
	m_z = z;
}

double Hikari::Vector3D::length(void) const
{
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

double Hikari::Vector3D::lengthSqrd(void) const
{
	return m_x * m_x + m_y * m_y + m_z * m_z;
}

void Hikari::Vector3D::normalize(void)
{
	double len = length();
	m_x /= len;
	m_y /= len;
	m_z /= len;
}

Hikari::Vector3D Hikari::Vector3D::normalized(void)
{
	double len = length();
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

Hikari::Vector4D::Vector4D(double x, double y, double z, double w) : Vector3D(x, y, z), m_w(w)
{
}

Hikari::Vector4D::Vector4D(const Vector3D& rVector, double w) : Vector3D(rVector), m_w(w)
{
}

Hikari::Vector4D::Vector4D(const Vector3D& rStart, const Vector3D& rEnd) : Vector3D(rEnd - rStart), m_w(0)
{
} // czy na pewno 0 to wektor?

double Hikari::Vector4D::w(void) const
{
	return m_w;
}

void Hikari::Vector4D::w(double w)
{
	m_w = w;
}
