#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <DirectXMath.h>

namespace Hikari
{
	class Camera
	{
		public:
			DirectX::XMMATRIX projectionMatrix(void);
			void projectionMatrix(DirectX::XMMATRIX *newProjectionMatrix);

		protected:
			DirectX::XMMATRIX m_ProjectionMatrix;
	};
}

#endif // __CAMERA_HPP__