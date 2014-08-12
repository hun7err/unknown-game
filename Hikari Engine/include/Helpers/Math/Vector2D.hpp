#ifndef __HIKARI_VECTOR2D_HPP__
#define __HIKARI_VECTOR2D_HPP__

#include <cmath>

namespace Hikari
{
	class Vector2D
	{
		public:
			Vector2D();
			Vector2D(float x, float y);

			float GetX(void) const;
			float GetY(void) const;
			void SetX(float x);
			void SetY(float y);

		protected:
			float m_x, m_y;
	};
}

#endif // __HIKARI_VECTOR2D_HPP__