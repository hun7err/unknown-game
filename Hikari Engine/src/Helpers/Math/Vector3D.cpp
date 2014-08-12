#include "../../../include/Helpers/Math/Vector3D.hpp"

Hikari::Vector3D::Vector3D(float x, float y, float z) : Vector2D(x, y), m_z(z)
{
}

Hikari::Vector3D::Vector3D(const Vector3D& rVector) : Vector2D(rVector.m_x, rVector.m_y), m_z(rVector.m_z)
{
}

Hikari::Vector3D::Vector3D(const Vector3D& start, const Vector3D& end) : Vector2D(end.GetX()-start.GetX(), end.GetY()-start.GetY()), m_z(end.GetZ()-start.GetZ())
{
}

float Hikari::Vector3D::GetZ(void) const
{
	 return m_z;
}

void Hikari::Vector3D::SetZ(float z)
{
	m_z = z;
}

float Hikari::Vector3D::Length(void) const
{
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

float Hikari::Vector3D::LengthSqrd(void) const
{
	return m_x * m_x + m_y * m_y + m_z * m_z;
}

void Hikari::Vector3D::Normalize(void)
{
	float len = Length();
	m_x /= len;
	m_y /= len;
	m_z /= len;
}

Hikari::Vector3D Hikari::Vector3D::Normalized(void)
{
	float len = Length();
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
