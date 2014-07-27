#ifndef __HIKARI_VECTOR_HPP__
#define __HIKARI_VECTOR_HPP__

#include <cmath>

namespace Hikari
{
	class Vector2D
	{
		public:
			Vector2D();
			Vector2D(double x, double y);

			double x(void) const;
			double y(void) const;
			void x(double x);
			void y(double y);

		protected:
			double m_x, m_y;
	};

	class Vector3D : public Vector2D
	{
		public:
			Vector3D(double x = 0.0f, double y = 0.0f, double z = 0.0f);
			Vector3D(const Vector3D& rVector);
			Vector3D(const Vector3D& start, const Vector3D& end);

			double z(void) const;
			void z(double z);

			double length(void) const;
			double lengthSqrd(void) const;

			void normalize(void);
			Vector3D normalized(void);

			friend Vector3D operator+ (const Vector3D& rFirst, const Vector3D& rSecond);
			friend Vector3D operator- (const Vector3D& rFirst, const Vector3D& rSecond);

		protected:
			double m_z;
	};

	class Vector4D : public Vector3D
	{
		public:
			Vector4D(double x = 0.0f, double y = 0.0f, double z = 0.0f, double w = 0.0f);
			Vector4D(const Vector3D& rVector, double w);
			Vector4D(const Vector3D& rStart, const Vector3D& rEnd);

			double w(void) const;
			void w(double w);

		protected:
			double m_w;
	};
}

#endif // __HIKARI_VECTOR_HPP__