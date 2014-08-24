#include "../../../include/Graphics/Shaders/ComputeShader.hpp"
#include <d3dcompiler.h>

Hikari::Shaders::ComputeShader::ComputeShader( void ) : Shader( "ComputeShader", ShaderType::COMPUTE_SHADER )
{
}

Hikari::Shaders::ComputeShader::ComputeShader( const std::wstring& filename ) : Shader( filename, "ComputeShader", ShaderType::COMPUTE_SHADER )
{
}

Hikari::ErrorCode Hikari::Shaders::ComputeShader::Compile( ID3D11Device *pDevice )
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
						"cs_5_0",
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
						"cs_5_0",
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
				pDevice->CreateComputeShader(
					m_pShaderBlob->GetBufferPointer(),
					m_pShaderBlob->GetBufferSize(),
					nullptr,
					&m_pComputeShader
				)
		)
	)
	{
		return ErrorCode::SHADER_CREATE_SHADER_FAILED;
	}

	return ErrorCode::SUCCESS;
}

ID3D11ComputeShader *Hikari::Shaders::ComputeShader::GetShaderPointer( void )
{
	return m_pComputeShader;
}
