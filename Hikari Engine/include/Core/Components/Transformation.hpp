#ifndef __HIKARI_CORE_COMPONENTS_TRANSFORMATIONHPP__
#define __HIKARI_CORE_COMPONENTS_TRANSFORMATIONHPP__

#include "../../Helpers/ECS/Component.hpp"
#include <DirectXMath.h>

namespace Hikari
{
	namespace Components
	{
		class Transformation : public Component
		{
			public:
				Transformation( void );

				void Move( const DirectX::XMFLOAT3& translation );
				void Move( float x, float y, float z );

				void Rotate( const DirectX::XMVECTOR& rotationAxis, float angle );
				void RotateNormal( const DirectX::XMVECTOR& normalAxis, float angle );
				void RotateQuaternion( const DirectX::XMVECTOR& quaternion );

				void Scale( const DirectX::XMFLOAT3& vector );
				void Scale( float x, float y, float z );

				DirectX::XMMATRIX* GetTransformationMatrixPointer( void );
				const DirectX::XMMATRIX& GetTransformationMatrix( void ) const;

			private:
				struct TransformationMatrix {
					DirectX::XMMATRIX value;
				};

				TransformationMatrix m_TransformationMatrix;
		};
	}
}

#endif