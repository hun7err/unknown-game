#include "../../../include/Graphics/Assets/ShaderProgram.hpp"
#include "../../../include/Graphics/Shaders/Shader.hpp"

Hikari::Assets::ShaderProgram::ShaderProgram( const std::string& AssetID ) : Entity( "ShaderProgram" ), Component( "ShaderProgram" ), Asset( AssetID )
{
}

Hikari::Assets::ShaderProgram::~ShaderProgram()
{
}

Hikari::ErrorCode Hikari::Assets::ShaderProgram::Load( const std::string& filename )
{
	// stworzyæ opis formatu binarnego z opisem pól + ew. jakaœ kompresja, przetrzymywaæ prekompilowany efekt (przez fxc) w pliku

	return ErrorCode::NOT_IMPLEMENTED_YET;
}

Hikari::ErrorCode Hikari::Assets::ShaderProgram::Export( const std::string& filename )
{
	return ErrorCode::NOT_IMPLEMENTED_YET;
}

Hikari::ErrorCode Hikari::Assets::ShaderProgram::Compile( ID3D11Device *pDevice )
{
	Hikari::ErrorCode e;

	for( auto shader = m_Components.begin(); shader != m_Components.end(); ++shader )
	{
		e = ( ( Shader* )( *shader ) )->Compile( pDevice );

		if( e != ErrorCode::SUCCESS )
		{
			return e;
		}
	}

	return ErrorCode::SUCCESS;
}
