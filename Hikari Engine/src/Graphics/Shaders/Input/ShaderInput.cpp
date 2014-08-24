#include "../../../../include/Graphics/Shaders/Input/ShaderInput.hpp"
#include "../../../../include/Graphics/Shaders/Input/InputElement.hpp"
#include "../../../../include/Graphics/Shaders/Input/Texture.hpp"
#include "../../../../include/Graphics/Shaders/Input/ModelViewProjection.hpp"
#include "../../../../include/Graphics/Shaders/Input/SamplerState.hpp"

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

	if(!m_InputElementsDescriptions.empty())
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

ID3D11InputLayout *Hikari::Shaders::ShaderInput::GetInputLayout( void )
{
	return m_pInputLayout;
}
