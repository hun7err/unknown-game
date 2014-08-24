#include "../../../../include/Graphics/Shaders/Input/SamplerState.hpp"

Hikari::Shaders::Input::SamplerState::SamplerState( void ) : Component("SamplerState")
{
	m_SamplerDescription.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	m_SamplerDescription.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	m_SamplerDescription.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	m_SamplerDescription.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	m_SamplerDescription.MipLODBias = 0.0f;
	m_SamplerDescription.MaxAnisotropy = 1;
	m_SamplerDescription.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	ZeroMemory(m_SamplerDescription.BorderColor, 4*sizeof(float));
	m_SamplerDescription.MinLOD = 0;
	m_SamplerDescription.MaxLOD = D3D11_FLOAT32_MAX;
}

Hikari::ErrorCode Hikari::Shaders::Input::SamplerState::Create( ID3D11Device *pDevice )
{
	if(
		FAILED(
				pDevice->CreateSamplerState(
					&m_SamplerDescription,
					&m_pSamplerState
				)
		)
	)
	{
		m_pSamplerState->Release();
		m_pSamplerState = nullptr;

		return ErrorCode::SHADER_SAMPLERSTATE_CREATION_FAILED;
	}

	return ErrorCode::SUCCESS;
}

ID3D11SamplerState *Hikari::Shaders::Input::SamplerState::GetSamplerStatePointer( void )
{
	return m_pSamplerState;
}

const D3D11_SAMPLER_DESC& Hikari::Shaders::Input::SamplerState::GetSamplerDescription( void ) const
{
	return m_SamplerDescription;
}

void Hikari::Shaders::Input::SamplerState::SetSamplerDescription( const D3D11_SAMPLER_DESC& SamplerDescription )
{
	m_SamplerDescription = SamplerDescription;
}
