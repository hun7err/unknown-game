#include "../include/Triangle.hpp"
#include "../include/Exception.hpp"

Hikari::Objects::Triangle::Triangle(Hikari::Vector3D first_vertex, Hikari::Vector3D second_vertex, Hikari::Vector3D third_vertex) : Object()
{
	m_VertexCount = 3;
	m_IndexCount = 3;

	m_pVertices = new Vertex[m_VertexCount];
	m_pIndices = new unsigned long [m_IndexCount];

	m_pVertices[0].position_modelSpace = first_vertex;
	m_pVertices[1].position_modelSpace = second_vertex;
	m_pVertices[2].position_modelSpace = third_vertex;


	// naprawiæ, ¿eby dla ka¿dego trójk¹ta pasowa³o
	/*
	m_Vertices[0].uv = Hikari::Vector2D(0.0f, 1.0f);
	m_Vertices[1].uv = Hikari::Vector2D(0.5f, 0.0f);
	m_Vertices[2].uv = Hikari::Vector2D(1.0f, 1.0f);
	*/
	m_pIndices[0] = 0;
	m_pIndices[1] = 1;
	m_pIndices[2] = 2;
}

Hikari::Objects::Triangle::~Triangle()
{
	delete [] m_pVertices;
	delete [] m_pIndices;
}

Hikari::Objects::EquilateralTriangle::EquilateralTriangle(Hikari::Vector3D triangleCenter, float sideLength) : Triangle(triangleCenter + Hikari::Vector3D(-sideLength/2.0f,-sideLength/3.0f,0.0f), triangleCenter + Hikari::Vector3D(sideLength/2.0f,-sideLength/3,0.0f), triangleCenter + Hikari::Vector3D(0.0f,sideLength*2.0f/3.0f,0.0f))
{
}
