#include "../../../include/Graphics/Shaders/HullShader.hpp"
#include <d3dcompiler.h>

Hikari::Shaders::HullShader::HullShader( void ) : Shader( "HullShader", ShaderType::HULL_SHADER )
{
}

Hikari::Shaders::HullShader::HullShader( const std::wstring& filename ) : Shader( filename, "HullShader", ShaderType::HULL_SHADER )
{
}

Hikari::ErrorCode Hikari::Shaders::HullShader::Compile( ID3D11Device *pDevice )
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
						"hs_5_0",
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
						"hs_5_0",
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
				pDevice->CreateHullShader(
					m_pShaderBlob->GetBufferPointer(),
					m_pShaderBlob->GetBufferSize(),
					nullptr,
					&m_pHullShader
				)
		)
	)
	{
		return ErrorCode::SHADER_CREATE_SHADER_FAILED;
	}

	return ErrorCode::SUCCESS;
}

ID3D11HullShader *Hikari::Shaders::HullShader::GetShaderPointer( void )
{
	return m_pHullShader;
}
