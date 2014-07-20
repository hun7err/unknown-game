#include "Object.hpp"
#include "Exception.hpp"

void Hikari::Object::initialize(void)
{
	m_pIndexBuffer = NULL;
	m_pVertexBuffer = NULL;
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
}

void Hikari::Object::draw(ID3D11DeviceContext* pDeviceContext)
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

		pDeviceContext->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);
		pDeviceContext->IASetIndexBuffer(m_pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
		pDeviceContext->IASetPrimitiveTopology(m_PrimitiveTopology);

		pDeviceContext->DrawIndexed(m_IndexCount, 0, 0);
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
