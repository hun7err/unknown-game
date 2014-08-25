#ifndef __HIKARI_CORE_MATH_VECTOR2HPP__
#define __HIKARI_CORE_MATH_VECTOR2HPP__

#include <DirectXMath.h>
#include <string>

namespace Hikari
{
	class Vector2
	{
		public:
			Vector2( float u = 0.0f, float v = 0.0f );

			std::string ToString( void );

			float GetU( void ) const;
			float GetV( void ) const;

			void SetU( float u );
			void SetV( float v );

		private:
			DirectX::XMFLOAT2 m_Value;
	};
}

#endif