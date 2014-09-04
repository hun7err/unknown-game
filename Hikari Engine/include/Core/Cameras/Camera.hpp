#ifndef __HIKARI_CORE_CAMERAS_CAMERAHPP__
#define __HIKARI_CORE_CAMERAS_CAMERAHPP__

#include <DirectXMath.h>
#include <string>
#include "../Actor.hpp"

namespace Hikari
{
	class Camera : public Actor
	{
		public:
			Camera( void );
			Camera( const std::string& ID );

			const DirectX::XMMATRIX& GetProjectionMatrix( void ) const;
			void SetProjectionMatrix( const DirectX::XMMATRIX& projectionMatrix );

			const DirectX::XMMATRIX& GetViewMatrix( void ) const;
			void SetViewMatrix( const DirectX::XMMATRIX& viewMatrix );

		private:
			struct Matrices
			{
				DirectX::XMMATRIX ProjectionMatrix;
				DirectX::XMMATRIX ViewMatrix;
			};

			Matrices m_Matrices;
	};
}

#endif