#ifndef __HIKARI_VECTOR_HPP__
#define __HIKARI_VECTOR_HPP__

#include <cmath>

namespace Hikari
{
	class Vector2D
	{
		public:
			Vector2D();
			Vector2D(float x, float y);

			float x(void) const;
			float y(void) const;
			void x(float x);
			void y(float y);

		protected:
			float m_x, m_y;
	};

	class Vector3D : public Vector2D
	{
		public:
			Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);
			Vector3D(const Vector3D& rVector);
			Vector3D(const Vector3D& start, const Vector3D& end);

			float z(void) const;
			void z(float z);

			float length(void) const;
			float lengthSqrd(void) const;

			void normalize(void);
			Vector3D normalized(void);

			friend Vector3D operator+ (const Vector3D& rFirst, const Vector3D& rSecond);
			friend Vector3D operator- (const Vector3D& rFirst, const Vector3D& rSecond);

		protected:
			float m_z;
	};

	class Vector4D : public Vector3D
	{
		public:
			Vector4D(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
			Vector4D(const Vector3D& rVector, float w);
			Vector4D(const Vector3D& rStart, const Vector3D& rEnd);

			float w(void) const;
			void w(float w);

		protected:
			float m_w;
	};
}

#endif // __HIKARI_VECTOR_HPP__