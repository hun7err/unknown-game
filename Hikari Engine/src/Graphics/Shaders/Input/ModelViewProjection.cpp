#include "../../../../include/Graphics/Shaders/Input/ModelViewProjection.hpp"

Hikari::Shaders::Input::ModelViewProjection::ModelViewProjection( void ) : Component("ModelViewProjection")
{
	m_pMatrixBuffer = nullptr;

	m_BufferDescription.Usage = D3D11_USAGE_DYNAMIC;
	m_BufferDescription.ByteWidth = sizeof(MVP_Type);
	m_BufferDescription.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	m_BufferDescription.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	m_BufferDescription.MiscFlags = 0;
	m_BufferDescription.StructureByteStride = 0;
}

Hikari::Shaders::Input::ModelViewProjection::~ModelViewProjection( void )
{
	if( m_pMatrixBuffer != nullptr )
	{
		m_pMatrixBuffer->Release();
		m_pMatrixBuffer = nullptr;
	}
}

Hikari::ErrorCode Hikari::Shaders::Input::ModelViewProjection::CreateMatrixBuffer( ID3D11Device *pDevice )
{
	if(
		FAILED(
			pDevice->CreateBuffer(
				&m_BufferDescription,
				nullptr,
				&m_pMatrixBuffer
			)
		)
	)
	{
		return ErrorCode::SHADER_MODELVIEWPROJECTION_CREATE_BUFFER_FAILED;
	}

	return ErrorCode::SUCCESS;
}

ID3D11Buffer *Hikari::Shaders::Input::ModelViewProjection::GetMatrixBuffer( void )
{
	return m_pMatrixBuffer;
}
