#include "../../../../include/Graphics/Shaders/Input/InputElement.hpp"

Hikari::Shaders::Input::InputElement::InputElement( LPCSTR SemanticNameBase, const std::string& type ) : Component( ), m_SemanticNameBase( SemanticNameBase ), m_Type( type )
{
	m_InputElementDescription.SemanticName = nullptr;
}

Hikari::Shaders::Input::InputElement::InputElement( const std::string& ComponentName, LPCSTR SemanticNameBase, const std::string& type ) : Component( ComponentName ), m_SemanticNameBase( SemanticNameBase ), m_Type( type )
{
	m_InputElementDescription.SemanticName = nullptr;
}

Hikari::Shaders::Input::InputElement::~InputElement( void )
{
	if( m_InputElementDescription.SemanticName != nullptr)
	{
		delete [] m_InputElementDescription.SemanticName;
	}
}

void Hikari::Shaders::Input::InputElement::SetSemanticName( int offset )
{
	if(m_InputElementDescription.SemanticName != nullptr)
	{
		delete [] m_InputElementDescription.SemanticName;
	}

	std::string SemanticNameStr = m_SemanticNameBase;
	
	if( offset >= 0 )
	{
		SemanticNameStr += std::to_string( offset );
	}

	char * SemanticName = new char [ SemanticNameStr.size() + 1 ];
	CopyMemory( SemanticName, SemanticNameStr.c_str(), SemanticNameStr.size()+1 );

	m_InputElementDescription.SemanticName = SemanticName;
}

D3D11_INPUT_ELEMENT_DESC Hikari::Shaders::Input::InputElement::GetInputElementDescription( void ) const
{
	return m_InputElementDescription;
}

const std::string& Hikari::Shaders::Input::InputElement::GetType( void ) const
{
	return m_Type;
}
