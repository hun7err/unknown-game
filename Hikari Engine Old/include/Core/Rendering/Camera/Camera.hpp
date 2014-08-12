#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <DirectXMath.h>

namespace Hikari
{
	class Camera
	{
		public:
			Camera();

			DirectX::XMFLOAT4X4 projectionMatrix(void);
			void projectionMatrix(DirectX::XMFLOAT4X4 newProjectionMatrix);
	
			DirectX::XMFLOAT4X4 viewMatrix(void);
			void viewMatrix(DirectX::XMFLOAT4X4 newViewMatrix);

			DirectX::XMFLOAT4 position(void);
			void moveTo(DirectX::XMFLOAT4 newPosition);
			void moveTo(float x, float y, float z);
			void moveBy(float dx, float dy, float dz);

			virtual void tick(void) = 0;

			float yaw(void);
			void yaw(float yaw);

			float pitch(void);
			void pitch(float pitch);

			virtual void setBindings(void) = 0;
			virtual void disableBindigs(void) = 0;

		protected:
			DirectX::XMFLOAT4X4	m_ProjectionMatrix,
								m_ViewMatrix;

			DirectX::XMFLOAT4	m_Position;

			DirectX::XMFLOAT4	m_defaultForward,
								m_defaultRight,
								m_camForward,
								m_camUp,
								m_camRight,
								m_Target;

			DirectX::XMFLOAT4X4	m_camRotationMatrix,
								m_groundWorld;

			float	m_moveLeftRight,
					m_moveBackForward;

			float	m_Yaw,
					m_Pitch;
	};
}

#endif // __CAMERA_HPP__