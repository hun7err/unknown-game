#include "../../../include/Core/Objects/Box.hpp"

Hikari::Objects::Box::Box(const Vector3D& center, float height, float width, float depth)
{
	m_VertexCount = 8;
	m_IndexCount = 36;

	m_pVertices = new Vertex[m_VertexCount];
	m_pIndices = new unsigned long [m_IndexCount];

	m_pVertices[0].position_modelSpace = center + Vector3D(width/2.0f,height/2.0f,-depth/2.0f);
	m_pVertices[1].position_modelSpace = center + Vector3D(width/2.0f,height/2.0f,depth/2.0f);
	m_pVertices[2].position_modelSpace = center + Vector3D(-width/2.0f,height/2.0f,depth/2.0f);
	m_pVertices[3].position_modelSpace = center + Vector3D(-width/2.0f,height/2.0f,-depth/2.0f);
	m_pVertices[4].position_modelSpace = center + Vector3D(width/2.0f,-height/2.0f,-depth/2.0f);
	m_pVertices[5].position_modelSpace = center + Vector3D(width/2.0f,-height/2.0f,depth/2.0f);
	m_pVertices[6].position_modelSpace = center + Vector3D(-width/2.0f,-height/2.0f,depth/2.0f);
	m_pVertices[7].position_modelSpace = center + Vector3D(-width/2.0f,-height/2.0f,-depth/2.0f);

	unsigned long indices[] = { 0L, 3L, 7L,
	                            0L, 4L, 7L,

	                            0L, 1L, 4L,
	                            1L, 4L, 5L,
	
	                            1L, 2L, 6L,
	                            1L, 5L, 6L,
	                            
	                            2L, 3L, 6L,
                                2L, 3L, 7L,
	
	                            0L, 1L, 2L,
	                            0L, 2L, 3L,
	
	                            4L, 5L, 6L,
	                            4L, 6L, 7L };

	CopyMemory(m_pIndices, indices, m_IndexCount * sizeof(unsigned long));
}

Hikari::Objects::Box::~Box()
{
	delete [] m_pVertices;
	m_pVertices = nullptr;
	delete [] m_pIndices;
	m_pIndices = nullptr;
}