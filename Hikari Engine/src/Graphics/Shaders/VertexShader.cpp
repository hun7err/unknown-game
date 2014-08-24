#include "../../../include/Graphics/Shaders/VertexShader.hpp"
#include <d3dcompiler.h>

Hikari::Shaders::VertexShader::VertexShader( void ) : Shader( "VertexShader", ShaderType::VERTEX_SHADER )
{
}

Hikari::Shaders::VertexShader::VertexShader( const std::wstring& filename ) : Shader( filename, "VertexShader", ShaderType::VERTEX_SHADER )
{
}

Hikari::ErrorCode Hikari::Shaders::VertexShader::Compile( ID3D11Device *pDevice )
{
	if(
		FAILED(
				m_pShaderInput->CreateInputLayout(
					pDevice,
					m_pShaderBlob
				)
		)
	)
	{
		return ErrorCode::SHADER_INPUTELEMENT_LAYOUT_CREATION_FAILED;
	}

	if( m_FromFile )
	{
		if(
			FAILED(
					D3DCompileFromFile(
						( LPCWSTR )m_Filename.c_str(),
						nullptr,
						D3D_COMPILE_STANDARD_FILE_INCLUDE,
						( LPCSTR )m_EntryPointName.c_str(),
						"vs_5_0",
						0,
						0,
						&m_pShaderBlob,
						nullptr
					)
			)
		)
		{
			return ErrorCode::SHADER_COMPILATION_FAILED;
		}
	}
	else
	{
		if(
			FAILED(
					D3DCompile(
						m_ShaderCode.c_str(),
						m_ShaderCode.length(),
						nullptr,
						nullptr,
						D3D_COMPILE_STANDARD_FILE_INCLUDE,
						( LPCSTR )m_EntryPointName.c_str(),
						"vs_5_0",
						0,
						0,
						&m_pShaderBlob,
						nullptr
					)
			)
		)
		{
			return ErrorCode::SHADER_COMPILATION_FAILED;
		}
	}

	if(
		FAILED(
				pDevice->CreateVertexShader(
					m_pShaderBlob->GetBufferPointer(),
					m_pShaderBlob->GetBufferSize(),
					nullptr,
					&m_pVertexShader
				)
		)
	)
	{
		return ErrorCode::SHADER_CREATE_SHADER_FAILED;
	}

	return ErrorCode::SUCCESS;
}

ID3D11VertexShader *Hikari::Shaders::VertexShader::GetShaderPointer( void )
{
	return m_pVertexShader;
}
