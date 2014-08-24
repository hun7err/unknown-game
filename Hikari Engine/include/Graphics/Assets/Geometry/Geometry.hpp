#ifndef __HIKARI_GRAPHICS_ASSETS_GEOMETRY_GEOMETRYHPP__
#define __HIKARI_GRAPHICS_ASSETS_GEOMETRY_GEOMETRYHPP__

#include "../../../Helpers/ECS/Component.hpp"
#include "../../../Helpers/ECS/Entity.hpp"
#include "../../../Core/ErrorCode.hpp"
#include "../Asset.hpp"
#include <DirectXMath.h>
#include <string>
#include <vector>

#include <d3d11.h>

namespace Hikari
{
	struct Vertex
	{
		DirectX::XMFLOAT4 position_modelSpace;
		DirectX::XMFLOAT2 uv;
		DirectX::XMFLOAT4 normal_modelSpace;
	};

	namespace Assets
	{
		class Geometry : public Asset, public Entity, public Component
		{
			public:
				Geometry( const std::string& AssetID );
				virtual ~Geometry( void );

				ErrorCode Init( ID3D11Device *pDevice );

				void SetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY primitiveTopology );

				const D3D11_PRIMITIVE_TOPOLOGY& GetPrimitiveTopology( void ) const;

				ID3D11Buffer *GetVertexBuffer( void );
				ID3D11Buffer *GetIndexBuffer( void );

			protected:
				Vertex *m_pVertices;
				unsigned int *m_pIndices;

				unsigned int m_VertexCount,
							 m_IndexCount;
				D3D11_PRIMITIVE_TOPOLOGY m_PrimitiveTopology;

				ID3D11Buffer *m_pVertexBuffer, *m_pIndexBuffer;
		};
	}
}

#endif