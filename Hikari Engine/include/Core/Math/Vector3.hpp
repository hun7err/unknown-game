#ifndef __HIKARI_CORE_MATH_VECTOR3HPP__
#define __HIKARI_CORE_MATH_VECTOR3HPP__

#include <DirectXMath.h>
#include <string>

namespace Hikari
{
	class Vector3
	{
		public:
			Vector3( float x = 0.0f, float y = 0.0f, float z = 0.0f );

			DirectX::XMFLOAT3 GetValue( void ) const;

			std::string ToString( void ) const;

			float GetX( void ) const;
			float GetY( void ) const;
			float GetZ( void ) const;

			void SetX( float x );
			void SetY( float y );
			void SetZ( float z );

		private:
			DirectX::XMFLOAT3 m_Value;
	};
}

#endif