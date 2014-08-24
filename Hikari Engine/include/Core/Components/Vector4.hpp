#ifndef __HIKARI_CORE_COMPONENTS_VECTOR4HPP__
#define __HIKARI_CORE_COMPONENTS_VECTOR4HPP__

#include "../../Helpers/ECS/Component.hpp"
#include <DirectXPackedVector.h>
#include <string>

namespace Hikari
{
	namespace Components
	{
		class Vector4 : public Component
		{
			public:
				Vector4( float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f );
				Vector4( const std::string& ID, float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f );

				void SetValue( float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f );	
				void SetValue( const DirectX::XMVECTOR& newValue );
				const DirectX::XMVECTOR& GetValue( void ) const;

				float GetX( void ) const;
				float GetY( void ) const;
				float GetZ( void ) const;
				float GetW( void ) const;

				void SetX( float x );
				void SetY( float y );
				void SetZ( float z );
				void SetW( float w );
			
			private:
				struct Vector {
					DirectX::XMVECTOR value;
				};

				Vector m_Vector;
				
		};
	}
}

#endif