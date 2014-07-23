#include "../include/Object.hpp"
#include "../include/Exception.hpp"
#include "../include/Engine.hpp"

void Hikari::Object::initialize(void)
{
	m_pIndexBuffer = NULL;
	m_pVertexBuffer = NULL;
	m_pIndices = NULL;
	m_pVertices = NULL;
	m_IndexCount = 0;
	m_VertexCount = 0;
	m_PrimitiveTopology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
}

Hikari::Object::Object()
{
	initialize();
}

Hikari::Object::Object(std::string name)
{
	m_Name = name;
	initialize();
}

Hikari::Object::~Object()
{
	if(m_pVertexBuffer)
	{
		m_pVertexBuffer->Release();
		m_pVertexBuffer = NULL;
	}

	if(m_pIndexBuffer)
	{
		m_pIndexBuffer->Release();
		m_pIndexBuffer = NULL;
	}
}

void Hikari::Object::setup(void)
{
	if(m_pVertices == NULL || m_pIndices == NULL)
	{
		throw Exception("Vertex and/or Index Array is not initialized in Object::setup(ID3D11Device*)", "NullPointerException");
	}

	D3D11_BUFFER_DESC	vertexBufferDescription,
						indexBufferDescription;
	D3D11_SUBRESOURCE_DATA	vertexData,
							indexData;

	vertexBufferDescription.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDescription.ByteWidth = sizeof(Vertex) * m_VertexCount;
	vertexBufferDescription.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDescription.CPUAccessFlags = 0;
	vertexBufferDescription.MiscFlags = 0;
	vertexBufferDescription.StructureByteStride = 0;

	vertexData.pSysMem = m_pVertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateBuffer(&vertexBufferDescription, &vertexData, &m_pVertexBuffer)))
	{
		throw Exception("Could not create Vertex Buffer in Hikari::Object::setup(ID3D11Device*)", "DirectXException");
	}

	indexBufferDescription.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDescription.ByteWidth = sizeof(unsigned long) * m_IndexCount;
	indexBufferDescription.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDescription.CPUAccessFlags = 0;
	indexBufferDescription.MiscFlags = 0;
	indexBufferDescription.StructureByteStride = 0;

	indexData.pSysMem = m_pIndices;

	if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateBuffer(&indexBufferDescription, &indexData, &m_pIndexBuffer)))
	{
		throw Exception("Could not create Index Buffer in Hikari::Object::setup(ID3D11Device*)", "DirectXException");
	}
}

void Hikari::Object::draw(void)
{
	if(m_IndexCount == 0 || m_VertexCount == 0)
	{
		Exception e("Unitialized object description in Hikari::Object::draw(ID3D11DeviceContext*)", "Exception");
		throw e;
	}
	else
	{
		unsigned int offset, stride;

		offset = 0;
		stride = sizeof(Vertex);

		Hikari::Engine::d3dsystem()->deviceContext()->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);
		Hikari::Engine::d3dsystem()->deviceContext()->IASetIndexBuffer(m_pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
		Hikari::Engine::d3dsystem()->deviceContext()->IASetPrimitiveTopology(m_PrimitiveTopology);

		Hikari::Engine::d3dsystem()->deviceContext()->VSSetShader(m_MaterialHandle->shader()->vertexShader(), 0, 0);
		Hikari::Engine::d3dsystem()->deviceContext()->PSSetShader(m_MaterialHandle->shader()->pixelShader(), 0, 0);
		Hikari::Engine::d3dsystem()->deviceContext()->IASetInputLayout(m_MaterialHandle->shader()->inputLayout());

		Hikari::Engine::d3dsystem()->deviceContext()->DrawIndexed(m_IndexCount, 0, 0);
	}
}

unsigned int Hikari::Object::indexCount(void)
{
	return m_IndexCount;
}

unsigned int Hikari::Object::vertexCount(void)
{
	return m_VertexCount;
}

Hikari::HMaterial Hikari::Object::material(void)
{
	return m_MaterialHandle;
}

void Hikari::Object::material(Hikari::HMaterial materialHandle)
{
	if(materialHandle.isValid())
	{
		m_MaterialHandle = materialHandle;
	}
}

void Hikari::Object::cleanup(void)
{
	if(m_pIndexBuffer)
	{
		m_pIndexBuffer->Release();
		m_pIndexBuffer = NULL;
	}

	if(m_pVertexBuffer)
	{
		m_pVertexBuffer->Release();
		m_pVertexBuffer = NULL;
	}
}

std::string Hikari::Object::name(void)
{
	return m_Name;
}

void Hikari::Object::name(std::string name)
{
	m_Name = name;
}
