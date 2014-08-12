#ifndef __HIKARI_VECTOR3DHPP__
#define __HIKARI_VECTOR3DHPP__

#include "Vector2D.hpp"

namespace Hikari
{
	class Vector3D : public Vector2D
	{
		public:
			Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);
			Vector3D(const Vector3D& rVector);
			Vector3D(const Vector3D& start, const Vector3D& end);

			float GetZ(void) const;
			void SetZ(float z);

			float Length(void) const;
			float LengthSqrd(void) const;

			void Normalize(void);
			Vector3D Normalized(void);

			friend Vector3D operator+ (const Vector3D& rFirst, const Vector3D& rSecond);
			friend Vector3D operator- (const Vector3D& rFirst, const Vector3D& rSecond);

		protected:
			float m_z;
	};
}

#endif