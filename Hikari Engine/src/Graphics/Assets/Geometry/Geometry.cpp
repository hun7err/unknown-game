#include "../../../../include/Graphics/Assets/Geometry/Geometry.hpp"

Hikari::Assets::Geometry::Geometry( const std::string& ComponentID ) : Component( ComponentID )
{
	m_pIndexBuffer = nullptr;
	m_pVertexBuffer = nullptr;
	m_pIndices = nullptr;
	m_pVertices = nullptr;
	m_IndexCount = 0;
	m_VertexCount = 0;
	m_PrimitiveTopology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
}

Hikari::Assets::Geometry::~Geometry( void )
{
	if( m_pIndexBuffer )
	{
		m_pIndexBuffer->Release( );
		m_pIndexBuffer = nullptr;
	}

	if( m_pVertexBuffer )
	{
		m_pVertexBuffer->Release();
		m_pVertexBuffer = nullptr;
	}

	delete [] m_pVertices;
	delete [] m_pIndices;

	m_pVertices = nullptr;
	m_pIndices = nullptr;
}

Hikari::ErrorCode Hikari::Assets::Geometry::CreateBuffers( ID3D11Device *pDevice )
{
	if( m_pVertices == nullptr )
	{
		return ErrorCode::GEOMETRY_VERTEX_ARRAY_NULL;
	}

	if( m_pIndices == nullptr )
	{
		return ErrorCode::GEOMETRY_INDEX_ARRAY_NULL;
	}

	D3D11_BUFFER_DESC	vertexBufferDescription,
						indexBufferDescription;
	D3D11_SUBRESOURCE_DATA	vertexData,
							indexData;

	vertexBufferDescription.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDescription.ByteWidth = sizeof( Vertex ) * m_VertexCount;
	vertexBufferDescription.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDescription.CPUAccessFlags = 0;
	vertexBufferDescription.MiscFlags = 0;
	vertexBufferDescription.StructureByteStride = 0;

	vertexData.pSysMem = m_pVertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	if(
		FAILED(
				pDevice->CreateBuffer(
					&vertexBufferDescription,
					&vertexData,
					&m_pVertexBuffer
				)
		)
	)
	{
		return ErrorCode::GEOMETRY_VERTEX_BUFFER_CREATION_FAILED;
	}

	indexBufferDescription.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDescription.ByteWidth = sizeof( unsigned long ) * m_IndexCount;
	indexBufferDescription.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDescription.CPUAccessFlags = 0;
	indexBufferDescription.MiscFlags = 0;
	indexBufferDescription.StructureByteStride = 0;

	indexData.pSysMem = m_pIndices;

	if(
		FAILED(
			pDevice->CreateBuffer(
				&indexBufferDescription,
				&indexData,
				&m_pIndexBuffer
			)
		)
	)
	{
		return ErrorCode::GEOMETRY_INDEX_BUFFER_CREATION_FAILED;
	}

	return ErrorCode::SUCCESS;
}

void Hikari::Assets::Geometry::SetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY primitiveTopology )
{
	m_PrimitiveTopology = primitiveTopology;
}

const D3D11_PRIMITIVE_TOPOLOGY& Hikari::Assets::Geometry::GetPrimitiveTopology( void ) const
{
	return m_PrimitiveTopology;
}

Hikari::ErrorCode Hikari::Assets::Geometry::Load( const std::string& filename )
{
	return ErrorCode::NOT_IMPLEMENTED_YET;	// nickthecoder.wordpress.com/2013/01/20/mesh-loading-with-assimp/
}

ID3D11Buffer *Hikari::Assets::Geometry::GetVertexBuffer( void )
{
	return m_pVertexBuffer;
}

ID3D11Buffer *Hikari::Assets::Geometry::GetIndexBuffer( void )
{
	return m_pIndexBuffer;
}
