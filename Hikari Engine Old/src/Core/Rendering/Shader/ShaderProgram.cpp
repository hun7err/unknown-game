#include <d3dcompiler.h>

#include "../../../../include/Core/Rendering/Shader/ShaderProgram.hpp"
#include "../../../../include/Helpers/Exception.hpp"
#include "../../../../include/IO/File.hpp"
#include "../../../../include/Core/Engine/Engine.hpp"

Hikari::ShaderProgram::ShaderProgram()
{
	m_pInputLayout = nullptr;
	m_pPixelShader = nullptr;
	m_pPixelShaderBlob = nullptr;
	m_pVertexShader = nullptr;
	m_pVertexShaderBlob = nullptr;
	m_pMatrixBuffer = nullptr;
	m_pSamplerState = nullptr;
}

void Hikari::ShaderProgram::setup(std::wstring vertexShaderName, std::wstring pixelShaderName)
{
	if(!IO::File::exists(vertexShaderName) || !IO::File::exists(pixelShaderName))
	{
		throw Exception("The specified shader file could not be found in ShaderProgram::setup(std::string)", "FileNotFoundException");
	}

	m_VertexShaderName = vertexShaderName;
	m_PixelShaderName = pixelShaderName;
}

void Hikari::ShaderProgram::setup(std::wstring shaderName)
{
	if(!IO::File::exists(shaderName))
	{
		throw Exception("The specified shader file could not be found in ShaderProgram::setup(std::string)", "FileNotFoundException");
	}

	m_VertexShaderName = shaderName;
	m_PixelShaderName = shaderName;
}

void Hikari::ShaderProgram::cleanup()
{
	m_pVertexShader->Release();
	m_pPixelShader->Release();
	m_pVertexShaderBlob->Release();
	m_pPixelShaderBlob->Release();
	m_pInputLayout->Release();
	m_pMatrixBuffer->Release();
	m_pSamplerState->Release();

	m_pVertexShader = nullptr;
	m_pPixelShader = nullptr;
	m_pInputLayout = nullptr;
	m_pPixelShaderBlob = nullptr;
	m_pVertexShaderBlob = nullptr;
	m_pMatrixBuffer = nullptr;
	m_pSamplerState = nullptr;

	delete [] m_PixelShaderEntryPointName;
	m_PixelShaderEntryPointName = nullptr;
	delete [] m_VertexShaderEntryPointName;
	m_VertexShaderEntryPointName = nullptr;
}

Hikari::ShaderProgram::~ShaderProgram()
{
}

void Hikari::ShaderProgram::entryPointNames(std::string vertexShaderEntryPointName, std::string pixelShaderEntryPointName)
{
	m_VertexShaderEntryPointName = new char[vertexShaderEntryPointName.length()+1];
	ZeroMemory((PVOID)m_VertexShaderEntryPointName, vertexShaderEntryPointName.length()+1);
	CopyMemory((PVOID)m_VertexShaderEntryPointName, vertexShaderEntryPointName.c_str(), vertexShaderEntryPointName.length());
	
	m_PixelShaderEntryPointName = new char[pixelShaderEntryPointName.length()+1];
	ZeroMemory((PVOID)m_PixelShaderEntryPointName, pixelShaderEntryPointName.length()+1);
	CopyMemory((PVOID)m_PixelShaderEntryPointName, pixelShaderEntryPointName.c_str(), pixelShaderEntryPointName.length());
}

void Hikari::ShaderProgram::entryPointNames(std::string shaderEntryPointName)
{
	m_VertexShaderEntryPointName = (LPCSTR)shaderEntryPointName.c_str();
	m_PixelShaderEntryPointName = (LPCSTR)shaderEntryPointName.c_str();
}

ID3D10Blob* Hikari::ShaderProgram::vertexShaderBlob(void)
{
	#ifdef _DEBUG
	if(m_pVertexShaderBlob == nullptr)
	{
		throw Exception("Vertex Shader blob pointer is not initialized in ShaderProgram::vertexShaderBlob(void)", "NullPointerException");
	}
	#endif

	return m_pVertexShaderBlob;
}

ID3D10Blob* Hikari::ShaderProgram::pixelShaderBlob(void)
{
	#ifdef _DEBUG
	if(m_pPixelShaderBlob == nullptr)
	{
		throw Exception("Pixel Shader blob is not initialized in ShaderProgram::pixelShaderBlob(void)", "NullPointerException");
	}
	#endif

	return m_pPixelShaderBlob;
}

ID3D11VertexShader* Hikari::ShaderProgram::vertexShader(void)
{
	#ifdef _DEBUG
	if(m_pVertexShader == nullptr)
	{
		throw Exception("Vertex Shader pointer is not initialized in ShaderProgram::vertexShader(void)", "NullPointerException");
	}
	#endif

	return m_pVertexShader;
}

ID3D11PixelShader* Hikari::ShaderProgram::pixelShader(void)
{
	#ifdef _DEBUG
	if(m_pPixelShader == nullptr)
	{
		throw Exception("Pixel Shader pointer is not initialized in ShaderProgram::pixelShader(void)", "NullPointerException");
	}
	#endif

	return m_pPixelShader;
}

ID3D11SamplerState *Hikari::ShaderProgram::samplerState(void)
{
	return m_pSamplerState;
}

ID3D11InputLayout* Hikari::ShaderProgram::inputLayout(void)
{
	return m_pInputLayout;
}

ID3D11Buffer* Hikari::ShaderProgram::matrixBuffer(void)
{
	return m_pMatrixBuffer;
}

void Hikari::ShaderProgram::compileAndCreateShaders()
{
	LPCWSTR wVertexShaderName = (LPCWSTR)m_VertexShaderName.c_str(),
			wPixelShaderName = (LPCWSTR)m_PixelShaderName.c_str();

	if(FAILED(D3DCompileFromFile(wVertexShaderName, nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, m_VertexShaderEntryPointName, "vs_5_0", 0, 0, &m_pVertexShaderBlob, nullptr)))
	{
		throw Exception("Vertex shader compilation failed", "ShaderCompilationException");
	}

	if(FAILED(D3DCompileFromFile(wPixelShaderName, nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, m_PixelShaderEntryPointName, "ps_5_0", 0, 0, &m_pPixelShaderBlob, nullptr)))
	{
		throw Exception("Pixel shader compilation failed", "ShaderCompilationException");
	}

	Hikari::Engine::d3dsystem()->device()->CreateVertexShader(m_pVertexShaderBlob->GetBufferPointer(), m_pVertexShaderBlob->GetBufferSize(), nullptr, &m_pVertexShader);
	Hikari::Engine::d3dsystem()->device()->CreatePixelShader(m_pPixelShaderBlob->GetBufferPointer(), m_pPixelShaderBlob->GetBufferSize(), nullptr, &m_pPixelShader);
}

void Hikari::ShaderProgram::setInputElementDescription(void)
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

void Hikari::ShaderProgram::createInputLayout(void)
{
	int descriptionElementCount = sizeof(m_InputElementDescription)/sizeof(m_InputElementDescription[0]);

	if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateInputLayout(m_InputElementDescription, descriptionElementCount, m_pVertexShaderBlob->GetBufferPointer(), m_pVertexShaderBlob->GetBufferSize(), &m_pInputLayout)))
	{
		throw Exception("Could not create input layout in ShaderProgram::compile(void)", "ShaderCompilationException");
	}
}

void Hikari::ShaderProgram::createMatrixBuffer(void)
{
	D3D11_BUFFER_DESC matrixBufferDescription;

	matrixBufferDescription.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDescription.ByteWidth = sizeof(MatrixBufferType);
	matrixBufferDescription.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDescription.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDescription.MiscFlags = 0;
	matrixBufferDescription.StructureByteStride = 0;

	if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateBuffer(&matrixBufferDescription, nullptr, &m_pMatrixBuffer)))
	{
		throw Exception("Could not create matrix buffer in ShaderProgram::compile(void)", "ShaderCompilationException");
	}
}

void Hikari::ShaderProgram::createSamplerState(void)
{
	D3D11_SAMPLER_DESC samplerDescription;

	samplerDescription.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDescription.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDescription.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDescription.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDescription.MipLODBias = 0.0f;
	samplerDescription.MaxAnisotropy = 1;
	samplerDescription.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	ZeroMemory(samplerDescription.BorderColor, 4*sizeof(float));
	samplerDescription.MinLOD = 0;
	samplerDescription.MaxLOD = D3D11_FLOAT32_MAX;

	if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateSamplerState(&samplerDescription, &m_pSamplerState)))
	{
		m_pSamplerState->Release();
		m_pSamplerState = nullptr;

		throw Exception("Could not create sampler state in Hikari::ShaderProgram::compile(void)", "ShaderCompilationException");
	}
}

void Hikari::ShaderProgram::compile(void)
{
	compileAndCreateShaders();
	setInputElementDescription();
	createInputLayout();
	createMatrixBuffer();
	createSamplerState();
}
