#ifndef __HIKARI_GRAPHICS_SHADERS_INPUT_MODELVIEWPROJECTIONHPP__
#define __HIKARI_GRAPHICS_SHADERS_INPUT_MODELVIEWPROJECTIONHPP__

#include "../../../Helpers/ECS/Component.hpp"
#include "../../../Core/ErrorCode.hpp"
#include <DirectXMath.h>
#include <d3d11.h>

namespace Hikari
{
	namespace Shaders
	{
		namespace Input
		{
			class ModelViewProjection : public Component
			{
				public:
					ModelViewProjection( void );
					~ModelViewProjection( void );

					ErrorCode CreateMatrixBuffer( ID3D11Device *pDevice );
						
					ID3D11Buffer *GetMatrixBuffer( void );


				private:
					struct MVP_Type
					{
						DirectX::XMMATRIX ModelMatrix;
						DirectX::XMMATRIX ViewMatrix;
						DirectX::XMMATRIX ProjectionMatrix;
					};

					ID3D11Buffer *m_pMatrixBuffer;
					D3D11_BUFFER_DESC m_BufferDescription;
			};
		}
	}
}

#endif