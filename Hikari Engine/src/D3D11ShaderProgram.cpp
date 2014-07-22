#include <d3dcompiler.h>

#include "../include/D3D11ShaderProgram.hpp"
#include "../include/Exception.hpp"
#include "../include/File.hpp"

Hikari::D3D11ShaderProgram::D3D11ShaderProgram()
{
	m_pD3D11System = NULL;
	m_pInputLayout = NULL;
	m_pPixelShader = NULL;
	m_pPixelShaderBlob = NULL;
	m_pVertexShader = NULL;
	m_pVertexShaderBlob = NULL;
}

void Hikari::D3D11ShaderProgram::setup(std::wstring vertexShaderName, std::wstring pixelShaderName)
{
	if(!File::exists(vertexShaderName) || !File::exists(pixelShaderName))
	{
		throw Exception("The specified shader file could not be found in D3D11ShaderProgram::setup(std::string)", "FileNotFoundException");
	}

	m_VertexShaderName = vertexShaderName;
	m_PixelShaderName = pixelShaderName;
}

void Hikari::D3D11ShaderProgram::setup(std::wstring shaderName)
{
	if(!File::exists(shaderName))
	{
		throw Exception("The specified shader file could not be found in D3D11ShaderProgram::setup(std::string)", "FileNotFoundException");
	}

	m_VertexShaderName = shaderName;
	m_PixelShaderName = shaderName;
}

void Hikari::D3D11ShaderProgram::cleanup()
{
	m_pVertexShader->Release();
	m_pPixelShader->Release();
	m_pInputLayout->Release();
	m_pVertexShaderBlob->Release();
	m_pPixelShaderBlob->Release();
	m_pVertexShader = NULL;
	m_pPixelShader = NULL;
	m_pInputLayout = NULL;
	m_pPixelShaderBlob = NULL;
	m_pVertexShaderBlob = NULL;

	delete [] m_PixelShaderEntryPointName;
	delete [] m_VertexShaderEntryPointName;
}

Hikari::D3D11ShaderProgram::~D3D11ShaderProgram()
{
}

void Hikari::D3D11ShaderProgram::d3d11system(Hikari::D3D11System* pD3D11System)
{
	#ifdef _DEBUG
	if(pD3D11System == NULL)
	{
		throw Exception("Invalid device context pointer in D3D11ShaderProgram::deviceContext(ID3D11DeviceContext*)", "NullPointerException");
	}
	#endif

	m_pD3D11System = pD3D11System;
}

void Hikari::D3D11ShaderProgram::entryPointNames(std::string vertexShaderEntryPointName, std::string pixelShaderEntryPointName)
{
	m_VertexShaderEntryPointName = new char[vertexShaderEntryPointName.length()+1];
	ZeroMemory((PVOID)m_VertexShaderEntryPointName, vertexShaderEntryPointName.length()+1);
	CopyMemory((PVOID)m_VertexShaderEntryPointName, vertexShaderEntryPointName.c_str(), vertexShaderEntryPointName.length());
	
	m_PixelShaderEntryPointName = new char[pixelShaderEntryPointName.length()+1];
	ZeroMemory((PVOID)m_PixelShaderEntryPointName, pixelShaderEntryPointName.length()+1);
	CopyMemory((PVOID)m_PixelShaderEntryPointName, pixelShaderEntryPointName.c_str(), pixelShaderEntryPointName.length());
}

void Hikari::D3D11ShaderProgram::entryPointNames(std::string shaderEntryPointName)
{
	m_VertexShaderEntryPointName = (LPCSTR)shaderEntryPointName.c_str();
	m_PixelShaderEntryPointName = (LPCSTR)shaderEntryPointName.c_str();
}

ID3D10Blob* Hikari::D3D11ShaderProgram::vertexShaderBlob(void)
{
	#ifdef _DEBUG
	if(m_pVertexShaderBlob == NULL)
	{
		throw Exception("Vertex Shader blob pointer is not initialized in D3D11ShaderProgram::vertexShaderBlob(void)", "NullPointerException");
	}
	#endif

	return m_pVertexShaderBlob;
}

ID3D10Blob* Hikari::D3D11ShaderProgram::pixelShaderBlob(void)
{
	#ifdef _DEBUG
	if(m_pPixelShaderBlob == NULL)
	{
		throw Exception("Pixel Shader blob is not initialized in D3D11ShaderProgram::pixelShaderBlob(void)", "NullPointerException");
	}
	#endif

	return m_pPixelShaderBlob;
}

ID3D11VertexShader* Hikari::D3D11ShaderProgram::vertexShader(void)
{
	#ifdef _DEBUG
	if(m_pVertexShader == NULL)
	{
		throw Exception("Vertex Shader pointer is not initialized in D3D11ShaderProgram::vertexShader(void)", "NullPointerException");
	}
	#endif

	return m_pVertexShader;
}

ID3D11PixelShader* Hikari::D3D11ShaderProgram::pixelShader(void)
{
	#ifdef _DEBUG
	if(m_pPixelShader == NULL)
	{
		throw Exception("Pixel Shader pointer is not initialized in D3D11ShaderProgram::pixelShader(void)", "NullPointerException");
	}
	#endif

	return m_pPixelShader;
}

ID3D11InputLayout* Hikari::D3D11ShaderProgram::inputLayout(void)
{
	return m_pInputLayout;
}

void Hikari::D3D11ShaderProgram::compileAndCreateShaders(void)
{
	LPCWSTR wVertexShaderName = (LPCWSTR)m_VertexShaderName.c_str(),
			wPixelShaderName = (LPCWSTR)m_PixelShaderName.c_str();

	if(FAILED(D3DCompileFromFile(wVertexShaderName, NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, m_VertexShaderEntryPointName, "vs_4_0", 0, 0, &m_pVertexShaderBlob, NULL)))
	{
		throw Exception("Vertex shader compilation failed", "ShaderCompilationException");
	}

	if(FAILED(D3DCompileFromFile(wPixelShaderName, NULL, D3D_COMPILE_STANDARD_FILE_INCLUDE, m_PixelShaderEntryPointName, "ps_4_0", 0, 0, &m_pPixelShaderBlob, NULL)))
	{
		throw Exception("Pixel shader compilation failed", "ShaderCompilationException");
	}

	m_pD3D11System->device()->CreateVertexShader(m_pVertexShaderBlob->GetBufferPointer(), m_pVertexShaderBlob->GetBufferSize(), NULL, &m_pVertexShader);
	m_pD3D11System->device()->CreatePixelShader(m_pPixelShaderBlob->GetBufferPointer(), m_pPixelShaderBlob->GetBufferSize(), NULL, &m_pPixelShader);
}

void Hikari::D3D11ShaderProgram::setInputElementDescription(void)
{
	// pozycja w przestrzeni modelu (xyz)
	m_InputElementDescription[0].SemanticName = "POSITION";
	m_InputElementDescription[0].SemanticIndex = 0;
	m_InputElementDescription[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	m_InputElementDescription[0].InputSlot = 0;
	m_InputElementDescription[0].AlignedByteOffset = 0;
	m_InputElementDescription[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	m_InputElementDescription[0].InstanceDataStepRate = 0;
	// wspó³rzêdne teksturowania (uv)
	m_InputElementDescription[1].SemanticName = "TEXCOORD";
	m_InputElementDescription[1].SemanticIndex = 0;
	m_InputElementDescription[1].Format = DXGI_FORMAT_R32G32_FLOAT;
	m_InputElementDescription[1].InputSlot = 0;
	m_InputElementDescription[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	m_InputElementDescription[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	m_InputElementDescription[1].InstanceDataStepRate = 0;
	// wektor normalny (xyz)
	m_InputElementDescription[2].SemanticName = "NORMAL";
	m_InputElementDescription[2].SemanticIndex = 0;
	m_InputElementDescription[2].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	m_InputElementDescription[2].InputSlot = 0;
	m_InputElementDescription[2].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	m_InputElementDescription[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	m_InputElementDescription[2].InstanceDataStepRate = 0;
}

void Hikari::D3D11ShaderProgram::compile(void)
{
	compileAndCreateShaders();
	setInputElementDescription();

	int descriptionElementCount = sizeof(m_InputElementDescription)/sizeof(m_InputElementDescription[0]);

	if(FAILED(m_pD3D11System->device()->CreateInputLayout(m_InputElementDescription, descriptionElementCount, m_pVertexShaderBlob->GetBufferPointer(), m_pVertexShaderBlob->GetBufferSize(), &m_pInputLayout)))
	{
		throw Exception("Could not create input layout in D3D11ShaderProgram::compile(void)", "ShaderCompilationException");
	}
}
