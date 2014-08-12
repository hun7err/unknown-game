#ifndef __HIKARI_VECTOR4DHPP__
#define __HIKARI_VECTOR4DHPP__

#include "Vector3D.hpp"

namespace Hikari
{
	class Vector4D : public Vector3D
	{
		public:
			Vector4D(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
			Vector4D(const Vector3D& rVector, float w);
			Vector4D(const Vector3D& rStart, const Vector3D& rEnd);

			float GetW(void) const;
			void SetW(float w);

		protected:
			float m_w;
	};
}

#endif