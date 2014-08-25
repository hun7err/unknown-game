#include "../../../../include/Graphics/Assets/Geometry/Triangle.hpp"

Hikari::Geometry::Triangle::Triangle( const std::string& AssetID, Vector3 p1, Vector3 p2, Vector3 p3 ) : Geometry( AssetID )
{
	m_VertexCount = 3;
	m_IndexCount = 3;

	m_pVertices = new Vertex [ m_VertexCount ];
	m_pIndices = new unsigned int [ m_IndexCount ];

	m_pVertices[0].position_modelSpace = p1;
	m_pVertices[0].position_modelSpace.SetW( 1.0 );
	m_pVertices[0].uv = Vector2(0.0f, 1.0f);
	
	m_pVertices[1].position_modelSpace = p2;
	m_pVertices[1].position_modelSpace.SetW( 1.0 );
	m_pVertices[1].uv = Vector2(0.5f, 0.0f);
	
	m_pVertices[2].position_modelSpace = p3;
	m_pVertices[2].position_modelSpace.SetW( 1.0 );
	m_pVertices[2].uv = Vector2(1.0f, 1.0f);
}
