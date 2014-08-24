#include "../../../include/Graphics/Shaders/DomainShader.hpp"
#include <d3dcompiler.h>

Hikari::Shaders::DomainShader::DomainShader( void ) : Shader( "DomainShader", ShaderType::DOMAIN_SHADER )
{
}

Hikari::Shaders::DomainShader::DomainShader( const std::wstring& filename ) : Shader( filename, "DomainShader", ShaderType::DOMAIN_SHADER )
{
}

Hikari::ErrorCode Hikari::Shaders::DomainShader::Compile( ID3D11Device *pDevice )
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
						"ds_5_0",
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
						"ds_5_0",
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
				pDevice->CreateDomainShader(
					m_pShaderBlob->GetBufferPointer(),
					m_pShaderBlob->GetBufferSize(),
					nullptr,
					&m_pDomainShader
				)
		)
	)
	{
		return ErrorCode::SHADER_CREATE_SHADER_FAILED;
	}

	return ErrorCode::SUCCESS;
}

ID3D11DomainShader *Hikari::Shaders::DomainShader::GetShaderPointer( void )
{
	return m_pDomainShader;
}
