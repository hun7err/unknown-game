#include "../../../../include/Graphics/Assets/Geometry/Triangle.hpp"

Hikari::Geometry::Triangle::Triangle( const std::string& AssetID, DirectX::XMFLOAT3 p1, DirectX::XMFLOAT3 p2, DirectX::XMFLOAT3 p3 ) : Geometry( AssetID )
{
	m_VertexCount = 3;
	m_IndexCount = 3;

	m_pVertices = new Vertex [ m_VertexCount ];
	m_pIndices = new unsigned int [ m_IndexCount ];

	m_pVertices[0].position_modelSpace.x = p1.x;
	m_pVertices[0].position_modelSpace.y = p1.y;
	m_pVertices[0].position_modelSpace.z = p1.z;
	m_pVertices[0].position_modelSpace.w = 1.0;
	m_pVertices[0].uv = DirectX::XMFLOAT2(0.0f, 1.0f);
	
	m_pVertices[1].position_modelSpace.x = p2.x;
	m_pVertices[1].position_modelSpace.y = p2.y;
	m_pVertices[1].position_modelSpace.z = p2.z;
	m_pVertices[1].position_modelSpace.w = 1.0;
	m_pVertices[1].uv = DirectX::XMFLOAT2(0.5f, 0.0f);
	
	m_pVertices[2].position_modelSpace.x = p3.x;
	m_pVertices[2].position_modelSpace.y = p3.y;
	m_pVertices[2].position_modelSpace.z = p3.z;
	m_pVertices[2].position_modelSpace.w = 1.0;
	m_pVertices[2].uv = DirectX::XMFLOAT2(1.0f, 1.0f);
}
