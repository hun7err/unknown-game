#include "../../../include/Core/Objects/Object.hpp"
#include "../../../include/Core/Engine/Engine.hpp"
#include "../../../include/Helpers/Exception.hpp"
using namespace DirectX;

void Hikari::Object::initialize(void)
{
	m_pIndexBuffer = nullptr;
	m_pVertexBuffer = nullptr;
	m_pIndices = nullptr;
	m_pVertices = nullptr;
	m_IndexCount = 0;
	m_VertexCount = 0;
	m_PrimitiveTopology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	XMStoreFloat4x4(&m_TransformationMatrix, XMMatrixIdentity());
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
		m_pVertexBuffer = nullptr;
	}

	if(m_pIndexBuffer)
	{
		m_pIndexBuffer->Release();
		m_pIndexBuffer = nullptr;
	}
}

void Hikari::Object::setup(void)
{
	if(m_pVertices == nullptr || m_pIndices == nullptr)
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

void Hikari::Object::draw(XMFLOAT4X4 transformationMatrix)
{
	if(m_IndexCount == 0 || m_VertexCount == 0)
	{
		Exception e("Unitialized object description in Hikari::Object::draw(ID3D11DeviceContext*)", "Exception");
		throw e;
	}
	else
	{
		DirectX::XMFLOAT4X4 modelMatrix;
		XMStoreFloat4x4(&modelMatrix, XMMatrixMultiply(XMLoadFloat4x4(&transformationMatrix), XMLoadFloat4x4(&m_TransformationMatrix)));

		unsigned int offset, stride;

		offset = 0;
		stride = sizeof(Vertex);

		Hikari::Engine::d3dsystem()->deviceContext()->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);
		Hikari::Engine::d3dsystem()->deviceContext()->IASetIndexBuffer(m_pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
		Hikari::Engine::d3dsystem()->deviceContext()->IASetPrimitiveTopology(m_PrimitiveTopology);

		ID3D11ShaderResourceView *pTexture = m_hMaterial->diffuseMap()->shaderResourceView();
		ID3D11SamplerState *pSamplerState = m_hMaterial->shader()->samplerState();

		Hikari::Engine::d3dsystem()->deviceContext()->PSSetShaderResources(0, 1, &pTexture);

		Hikari::Engine::d3dsystem()->deviceContext()->VSSetShader(m_hMaterial->shader()->vertexShader(), 0, 0);
		Hikari::Engine::d3dsystem()->deviceContext()->PSSetShader(m_hMaterial->shader()->pixelShader(), 0, 0);
		Hikari::Engine::d3dsystem()->deviceContext()->IASetInputLayout(m_hMaterial->shader()->inputLayout());

		Hikari::Engine::d3dsystem()->deviceContext()->PSSetSamplers(0, 1, &pSamplerState);
		
		D3D11_MAPPED_SUBRESOURCE mappedSubResource;
		MatrixType* dataPtr;
		unsigned int cBufferId = 0;
		ID3D11Buffer* pMatrixBuffer = m_hMaterial->shader()->matrixBuffer();

		if(FAILED(Hikari::Engine::d3dsystem()->deviceContext()->Map(pMatrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedSubResource)))
		{
			throw Exception("Could not map subresource in Hikari::Object::draw(DirectX::XMMATRIX)", "ObjectDrawException");
		}
		dataPtr = (MatrixType*)mappedSubResource.pData;
		dataPtr->model = DirectX::XMMatrixTranspose(XMLoadFloat4x4(&modelMatrix));
		dataPtr->view = DirectX::XMMatrixTranspose(XMLoadFloat4x4(&Hikari::Engine::camera()->viewMatrix()));
		dataPtr->projection = DirectX::XMMatrixTranspose(XMLoadFloat4x4(&Hikari::Engine::camera()->projectionMatrix()));	// a co jak bez transpose?

		Hikari::Engine::d3dsystem()->deviceContext()->Unmap(pMatrixBuffer, 0);

		Hikari::Engine::d3dsystem()->deviceContext()->VSSetConstantBuffers(cBufferId, 1, &pMatrixBuffer);

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
	return m_hMaterial;
}

void Hikari::Object::material(Hikari::HMaterial hMaterial)
{
	if(hMaterial.isValid())
	{
		m_hMaterial = hMaterial;
	}
}

void Hikari::Object::cleanup(void)
{
	if(m_pIndexBuffer)
	{
		m_pIndexBuffer->Release();
		m_pIndexBuffer = nullptr;
	}

	if(m_pVertexBuffer)
	{
		m_pVertexBuffer->Release();
		m_pVertexBuffer = nullptr;
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
