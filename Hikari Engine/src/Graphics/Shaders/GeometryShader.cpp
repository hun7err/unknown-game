#include "../../../include/Graphics/Shaders/GeometryShader.hpp"
#include <d3dcompiler.h>

Hikari::Shaders::GeometryShader::GeometryShader( void ) : Shader( "GeometryShader", ShaderType::GEOMETRY_SHADER )
{
}

Hikari::Shaders::GeometryShader::GeometryShader( const std::wstring& filename ) : Shader( filename, "GeometryShader", ShaderType::GEOMETRY_SHADER )
{
}

Hikari::ErrorCode Hikari::Shaders::GeometryShader::Compile( ID3D11Device *pDevice )
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
						"gs_5_0",
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
						"gs_5_0",
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
				pDevice->CreateGeometryShader(
					m_pShaderBlob->GetBufferPointer(),
					m_pShaderBlob->GetBufferSize(),
					nullptr,
					&m_pGeometryShader
				)
		)
	)
	{
		return ErrorCode::SHADER_CREATE_SHADER_FAILED;
	}

	return ErrorCode::SUCCESS;
}

ID3D11GeometryShader *Hikari::Shaders::GeometryShader::GetShaderPointer( void )
{
	return m_pGeometryShader;
}
