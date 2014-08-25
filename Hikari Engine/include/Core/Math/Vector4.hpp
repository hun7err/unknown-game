#ifndef __HIKARI_CORE_MATH_VECTOR4HPP__
#define __HIKARI_CORE_MATH_VECTOR4HPP__

#include "Vector3.hpp"
#include <DirectXMath.h>
#include <string>

namespace Hikari
{
	class Vector4
	{
		public:
			Vector4( float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f );

			Vector4( const Vector3& vector, float w );

			const DirectX::XMVECTORF32& GetValue( void ) const;

			std::string ToString( void ) const;

			Vector4& operator=( const Vector3& vector );

			float GetX( void ) const;
			float GetY( void ) const;
			float GetZ( void ) const;
			float GetW( void ) const;

			void SetX( float x );
			void SetY( float y );
			void SetZ( float z );
			void SetW( float w );
	
		private:
			DirectX::XMVECTORF32 m_Value;
	};
}

#endif	// __HIKARI_CORE_MATH_VECTOR4HPP__
