#include <d3dcompiler.h>

#include "D3D11ShaderProgram.hpp"
#include "Exception.hpp"

Hikari::D3D11ShaderProgram::D3D11ShaderProgram(std::string vertexShaderName, std::string pixelShaderName = "")
{
	m_VertexShaderName = vertexShaderName;
	
	m_PixelShaderName = pixelShaderName;
}

Hikari::D3D11ShaderProgram::D3D11ShaderProgram(std::string shaderName)
{
	m_VertexShaderName = shaderName;
	m_PixelShaderName = shaderName;
}

Hikari::D3D11ShaderProgram::~D3D11ShaderProgram()
{
	m_pVertexShader->Release();
	m_pPixelShader->Release();
}

void Hikari::D3D11ShaderProgram::deviceContext(ID3D11DeviceContext* pDeviceContext)
{
	if(pDeviceContext == NULL)
	{
		throw new Exception("Invalid device context pointer in D3D11ShaderProgram::deviceContext(ID3D11DeviceContext*)", "NullPointerException");
	}

	m_pDeviceContext = pDeviceContext;
}

void Hikari::D3D11ShaderProgram::entryPointNames(std::string vertexShaderEntryPointName, std::string pixelShaderEntryPointName)
{
	m_VertexShaderEntryPointName = (LPCSTR)vertexShaderEntryPointName.c_str();
	m_PixelShaderEntryPointName = (LPCSTR)pixelShaderEntryPointName.c_str();
}

void Hikari::D3D11ShaderProgram::entryPointNames(std::string shaderEntryPointName)
{
	m_VertexShaderEntryPointName = (LPCSTR)shaderEntryPointName.c_str();
	m_PixelShaderEntryPointName = (LPCSTR)shaderEntryPointName.c_str();
}

ID3D10Blob* Hikari::D3D11ShaderProgram::vertexShaderBlob(void)
{
	if(m_pVertexShaderBlob == NULL)
	{
		throw new Exception("Vertex Shader blob pointer is not initialized in D3D11ShaderProgram::vertexShaderBlob(void)", "NullPointerException");
	}

	return m_pVertexShaderBlob;
}

ID3D10Blob* Hikari::D3D11ShaderProgram::pixelShaderBlob(void)
{
	if(m_pPixelShaderBlob == NULL)
	{
		throw new Exception("Pixel Shader blob is not initialized in D3D11ShaderProgram::pixelShaderBlob(void)", "NullPointerException");
	}

	return m_pPixelShaderBlob;
}

ID3D11VertexShader* Hikari::D3D11ShaderProgram::vertexShader(void)
{
	if(m_pVertexShader == NULL)
	{
		throw new Exception("Vertex Shader pointer is not initialized in D3D11ShaderProgram::vertexShader(void)", "NullPointerException");
	}

	return m_pVertexShader;
}

ID3D11PixelShader* Hikari::D3D11ShaderProgram::pixelShader(void)
{
	if(m_pPixelShader == NULL)
	{
		throw new Exception("Pixel Shader pointer is not initialized in D3D11ShaderProgram::pixelShader(void)", "NullPointerException");
	}

	return m_pPixelShader;
}

void Hikari::D3D11ShaderProgram::compile(void)
{
	D3DCompileFromFile((LPCWSTR)m_VertexShaderName.c_str(), 0, 0, m_VertexShaderEntryPointName, "vs_4_0", 0, 0, &m_pVertexShaderBlob, 0);
	D3DCompileFromFile((LPCWSTR)m_PixelShaderName.c_str(), 0, 0, m_PixelShaderEntryPointName, "ps_4_0", 0, 0, &m_pPixelShaderBlob, 0);
}
