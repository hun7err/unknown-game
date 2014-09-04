#include "../../../../include/Graphics/Shaders/Input/ShaderInput.hpp"
#include "../../../../include/Graphics/Shaders/Input/InputElement.hpp"
#include "../../../../include/Graphics/Shaders/Input/Texture.hpp"
#include "../../../../include/Graphics/Shaders/Input/SamplerState.hpp"
#include "../../../../include/Graphics/Shaders/Input/ModelViewProjection.hpp"

Hikari::Shaders::ShaderInput::ShaderInput( void )
{
}

Hikari::ErrorCode Hikari::Shaders::ShaderInput::CreateInputLayout( ID3D11Device *pDevice, ID3D10Blob *pShaderBlob )
{
	Input::InputElement *pInputElement;
	int uvOffset = 0,
		normalOffset = 0,
		positionOffset = 0;

	for( auto inputElement = m_Components.begin(); inputElement != m_Components.end(); ++inputElement )
	{
		if( (*inputElement)->GetID() == "Position" )
		{
			pInputElement = ( Input::InputElement* )( *inputElement );
			pInputElement->SetSemanticName( positionOffset );
			++positionOffset;
			m_InputElementsDescriptions.push_back( pInputElement->GetInputElementDescription() );
		}
		else if ( (*inputElement)->GetID() == "Normal" )
		{
			pInputElement = ( Input::InputElement* )( *inputElement );
			pInputElement->SetSemanticName( normalOffset );
			++normalOffset;
			m_InputElementsDescriptions.push_back( pInputElement->GetInputElementDescription() );
		}
		else if ( (*inputElement)->GetID() == "Texture" )
		{
			Input::Texture *pTexture = ( Input::Texture* ) ( *inputElement );
			Input::SamplerState *pSamplerState = ( Input::SamplerState* )pTexture->GetComponent("SamplerState");

			if( pSamplerState != nullptr )
			{
				pSamplerState->Create( pDevice );
			}

			Component *pUV = pTexture->GetComponent("UV");

			if( pUV != nullptr )
			{
				pInputElement = ( Input::InputElement* )( pUV );
				pInputElement->SetSemanticName( uvOffset );
				++uvOffset;
				m_InputElementsDescriptions.push_back( pInputElement->GetInputElementDescription() );
			}
		}
		else if ( (*inputElement)->GetID() == "MVP" )
		{
			Input::ModelViewProjection *pMVP = ( Input::ModelViewProjection* )( *inputElement );

			pMVP->CreateMatrixBuffer( pDevice );
		}
	}

	if( !m_InputElementsDescriptions.empty() )
	{
		if(
			FAILED(
				pDevice->CreateInputLayout(
					&m_InputElementsDescriptions[0],
					m_InputElementsDescriptions.size(),
					pShaderBlob->GetBufferPointer(),
					pShaderBlob->GetBufferSize(),
					&m_pInputLayout
				)
			)
		)
		{
			return ErrorCode::SHADER_INPUTELEMENT_LAYOUT_CREATION_FAILED;
		}
	}

	return ErrorCode::SUCCESS;
}

void Hikari::Shaders::ShaderInput::AddComponent( Component *pComponent )
{
	m_Components.push_back( pComponent );

	if( pComponent->GetID() == "Texture" )
	{
		Shaders::Input::Texture *pTexture = ( Shaders::Input::Texture* ) pComponent;
		Shaders::Input::SamplerState *pSamplerState = ( Shaders::Input::SamplerState* ) pTexture->GetComponent( "SamplerState" );

		unsigned int key = m_Samplers.size( );
		m_Samplers.push_back( pSamplerState->GetSamplerStatePointer( ) );

		m_ComponentPositions.insert( std::make_pair( pComponent->GetID( ), key ) );
	}
}

bool Hikari::Shaders::ShaderInput::RemoveComponent( const std::string& componentID )
{
	auto element = m_ComponentPositions.find( componentID );
	unsigned int key = element->second;

	m_Samplers.erase( m_Samplers.begin( ) + key );	// naprawiæ to, bo jest Ÿle

	for( element = m_ComponentPositions.begin(); element != m_ComponentPositions.end(); ++element )
	{
		if( element->second > key )
		{
			element->second--;
		}
	}

	m_ComponentPositions.erase( element );

	for( auto component = m_Components.begin(); component != m_Components.end(); ++component )
	{
		if( ( *component )->GetID( ) == componentID )
		{
			m_Components.erase( component );

			return true;
		}
	}
	return false;
}

ID3D11SamplerState** Hikari::Shaders::ShaderInput::GetSamplers( void )
{
	if( m_Samplers.empty() )
	{
		return nullptr;
	}
	else
	{
		return &(m_Samplers[0]);
	}
}

unsigned int Hikari::Shaders::ShaderInput::GetSamplerCount( void ) const
{
	return m_Samplers.size();
}

ID3D11InputLayout *Hikari::Shaders::ShaderInput::GetInputLayout( void )
{
	return m_pInputLayout;
}
