#include "../../../include/Core/Objects/Cube.hpp"

/*
       2---------1
      /|        /|
     / |       / |            y+
    3--+------0  |            ^
	|  6------|--5            |   z+
	| /       | /             |  /      uk³ad wspó³rzêdnych LH (D3D)
	|/        |/              | /
	7---------4               |/
	                          +--------> x+
*/

Hikari::Objects::Cube::Cube(const Hikari::Vector3D& center, float sideLength)
{
	m_VertexCount = 8;
	m_IndexCount = 36;

	m_pVertices = new Vertex[m_VertexCount];
	m_pIndices = new unsigned long [m_IndexCount];

	m_pVertices[0].position_modelSpace = center + Vector3D(sideLength/2.0f,sideLength/2.0f,-sideLength/2.0f);
	m_pVertices[1].position_modelSpace = center + Vector3D(sideLength/2.0f,sideLength/2.0f,sideLength/2.0f);
	m_pVertices[2].position_modelSpace = center + Vector3D(-sideLength/2.0f,sideLength/2.0f,sideLength/2.0f);
	m_pVertices[3].position_modelSpace = center + Vector3D(-sideLength/2.0f,sideLength/2.0f,-sideLength/2.0f);
	m_pVertices[4].position_modelSpace = center + Vector3D(sideLength/2.0f,-sideLength/2.0f,-sideLength/2.0f);
	m_pVertices[5].position_modelSpace = center + Vector3D(sideLength/2.0f,-sideLength/2.0f,sideLength/2.0f);
	m_pVertices[6].position_modelSpace = center + Vector3D(-sideLength/2.0f,-sideLength/2.0f,sideLength/2.0f);
	m_pVertices[7].position_modelSpace = center + Vector3D(-sideLength/2.0f,-sideLength/2.0f,-sideLength/2.0f);

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

Hikari::Objects::Cube::~Cube()
{
	delete [] m_pVertices;
	m_pVertices = nullptr;
	delete [] m_pIndices;
	m_pIndices = nullptr;
}
