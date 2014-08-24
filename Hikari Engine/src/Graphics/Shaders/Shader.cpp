#include "../../../include/Graphics/Shaders/Shader.hpp"

Hikari::Shader::Shader( const std::string& ShaderName, Shaders::ShaderType shaderType ) : Component( ShaderName ), m_ShaderType( shaderType ), m_pShaderBlob( nullptr ), m_FromFile( false ), m_FromString( false )
{
	m_pShaderInput = new Shaders::ShaderInput();
}

Hikari::Shader::Shader( const std::wstring& filename, const std::string& ShaderName, Shaders::ShaderType shaderType ) : Component( ShaderName ), m_ShaderType( shaderType ), m_pShaderBlob( nullptr ), m_FromFile( true ), m_FromString( false ), m_Filename( filename )
{
	m_pShaderInput = new Shaders::ShaderInput();
}

Hikari::Shader::~Shader( void )
{
	m_pShaderBlob->Release();
	m_pShaderBlob = nullptr;

	delete m_pShaderInput;
	m_pShaderInput = nullptr;
}

Hikari::Shaders::ShaderType Hikari::Shader::GetShaderType( void ) const
{
	return m_ShaderType;
}

ID3D10Blob *Hikari::Shader::GetShaderBlob( void )
{
	return m_pShaderBlob;
}

void Hikari::Shader::SetShaderBlob( ID3D10Blob *pShaderBlob )
{
	m_pShaderBlob = pShaderBlob;
}

Hikari::Shaders::ShaderInput *Hikari::Shader::GetShaderInput( void )
{
	return m_pShaderInput;
}

void Hikari::Shader::SetEntryPoint( const std::string& entryPointName )
{
	m_EntryPointName = entryPointName;
}

void Hikari::Shader::SetFileName( const std::wstring& filename )
{
	m_FromString = false;
	m_ShaderCode.clear();
	m_FromFile = true;
	m_Filename = filename;
}

void Hikari::Shader::SetShaderCode( const std::string& ShaderCode )
{
	m_FromFile = false;
	m_ShaderCode.clear();
	m_FromString = true;
	m_ShaderCode = ShaderCode;
}
