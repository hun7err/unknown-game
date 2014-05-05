#ifndef __HIKARI_VECTOR_HPP__
#define __HIKARI_VECTOR_HPP__

namespace Hikari
{
	class Vector2D
	{
		public:
			Vector2D(int x, int y): m_x(x), m_y(y) {}

			int x(void) { return m_x; }
			int y(void) { return m_y; }
			void x(int x) { m_x = x; }
			void y(int y) { m_y = y; }

		protected:
			int m_x, m_y;
	};

	class Vector3D : public Vector2D
	{
		public:
			Vector3D(int x, int y, int z): Vector2D(x, y), m_z(z) {}
			Vector3D(const Vector3D& rVector): Vector2D(rVector.m_x, rVector.m_y), m_z(rVector.m_z) {}

			int z(void) { return m_z; }
			void z(int z) { m_z = z; }

			Vector3D operator- (const Vector3D& rOther) { return Vector3D(m_x - rOther.m_x, m_y - rOther.m_y, m_z - rOther.m_z); }
		protected:
			int m_z;
	};

	class Vector4D : public Vector3D
	{
		public:
			Vector4D(int x, int y, int z, int w): Vector3D(x, y, z), m_w(w) {}
			Vector4D(Vector3D& rVector, int w): Vector3D(rVector), m_w(w) {}
			Vector4D(Vector3D& rStart, Vector3D& rEnd): Vector3D(rEnd - rStart), m_w(0) {} // czy na pewno 0 to wektor?

			int w(void) { return m_w; }

		protected:
			int m_w;
	};
}

#endif // __HIKARI_VECTOR_HPP__