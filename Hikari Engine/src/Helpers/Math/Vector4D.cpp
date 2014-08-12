#include "../../../include/Helpers/Math/Vector4D.hpp"

Hikari::Vector4D::Vector4D(float x, float y, float z, float w) : Vector3D(x, y, z), m_w(w)
{
}

Hikari::Vector4D::Vector4D(const Vector3D& rVector, float w) : Vector3D(rVector), m_w(w)
{
}

Hikari::Vector4D::Vector4D(const Vector3D& rStart, const Vector3D& rEnd) : Vector3D(rEnd - rStart), m_w(0)
{
} // czy na pewno 0 to wektor?

float Hikari::Vector4D::GetW(void) const
{
	return m_w;
}

void Hikari::Vector4D::SetW(float w)
{
	m_w = w;
}
