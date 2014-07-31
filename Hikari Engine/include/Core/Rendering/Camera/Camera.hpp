#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <DirectXMath.h>

namespace Hikari
{
	class Camera
	{
		public:
			Camera();

			DirectX::XMMATRIX projectionMatrix(void);
			void projectionMatrix(DirectX::XMMATRIX *pNewProjectionMatrix);
	
			DirectX::XMMATRIX viewMatrix(void);
			void viewMatrix(DirectX::XMMATRIX *pNewViewMatrix);

			DirectX::XMVECTOR position(void);
			void move(DirectX::XMVECTOR *pNewPosition);
			void move(float x, float y, float z);

			virtual void tick(void) = 0;

			float yaw(void);
			void yaw(float yaw);

			float pitch(void);
			void pitch(float pitch);

			virtual void setBindings(void) = 0;
			virtual void disableBindigs(void) = 0;

		protected:
			DirectX::XMMATRIX	m_ProjectionMatrix,
								m_ViewMatrix;

			DirectX::XMVECTOR	m_Position;

			DirectX::XMVECTOR	m_defaultForward,
								m_defaultRight,
								m_camForward,
								m_camUp,
								m_camRight,
								m_Target;

			DirectX::XMMATRIX	m_camRotationMatrix,
								m_groundWorld;

			float	m_moveLeftRight,
					m_moveBackForward;

			float	m_Yaw,
					m_Pitch;
	};
}

#endif // __CAMERA_HPP__