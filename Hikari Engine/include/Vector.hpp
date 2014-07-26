#ifndef __HIKARI_VECTOR_HPP__
#define __HIKARI_VECTOR_HPP__

namespace Hikari
{
	class Vector2D
	{
		public:
			Vector2D(void): m_x(0), m_y(0) {}
			Vector2D(float x, float y): m_x(x), m_y(y) {}

			float x(void) { return m_x; }
			float y(void) { return m_y; }
			void x(float x) { m_x = x; }
			void y(float y) { m_y = y; }

		protected:
			float m_x, m_y;
	};

	class Vector3D : public Vector2D
	{
		public:
			Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f): Vector2D(x, y), m_z(z) {}
			Vector3D(const Vector3D& rVector): Vector2D(rVector.m_x, rVector.m_y), m_z(rVector.m_z) {}

			float z(void) { return m_z; }
			void z(float z) { m_z = z; }

			friend Vector3D operator+ (const Vector3D& rFirst, const Vector3D& rSecond);
			friend Vector3D operator- (const Vector3D& rFirst, const Vector3D& rSecond);

		protected:
			float m_z;
	};

	Vector3D operator+ (const Vector3D& rFirst, const Vector3D& rSecond) { return Vector3D(rFirst.m_x + rSecond.m_x, rFirst.m_y + rSecond.m_y, rFirst.m_z + rSecond.m_z); }
	Vector3D operator- (const Vector3D& rFirst, const Vector3D& rSecond) { return Vector3D(rFirst.m_x - rSecond.m_x, rFirst.m_y - rSecond.m_y, rFirst.m_z - rSecond.m_z); }

	class Vector4D : public Vector3D
	{
		public:
			Vector4D(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f): Vector3D(x, y, z), m_w(w) {}
			Vector4D(Vector3D& rVector, float w): Vector3D(rVector), m_w(w) {}
			Vector4D(Vector3D& rStart, Vector3D& rEnd): Vector3D(rEnd - rStart), m_w(0) {} // czy na pewno 0 to wektor?

			float w(void) { return m_w; }

		protected:
			float m_w;
	};
}

#endif // __HIKARI_VECTOR_HPP__