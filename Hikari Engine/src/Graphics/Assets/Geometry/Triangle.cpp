#include "../../../../include/Graphics/Assets/Geometry/Triangle.hpp"

Hikari::Geometry::Triangle::Triangle( const std::string& AssetID, DirectX::XMFLOAT4 p1, DirectX::XMFLOAT4 p2, DirectX::XMFLOAT4 p3 ) : Geometry( AssetID )
{
	m_VertexCount = 3;
	m_IndexCount = 3;

	m_pVertices = new Vertex [ m_VertexCount ];
	m_pIndices = new unsigned int [ m_IndexCount ];

	m_pVertices[0].position_modelSpace = p1;
	m_pVertices[0].uv = DirectX::XMFLOAT2(0.0f, 1.0f);

	m_pVertices[1].position_modelSpace = p2;
	m_pVertices[1].uv = DirectX::XMFLOAT2(0.5f, 0.0f);

	m_pVertices[2].position_modelSpace = p3;
	m_pVertices[2].uv = DirectX::XMFLOAT2(1.0f, 1.0f);
}
