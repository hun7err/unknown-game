#include "../../../../include/Graphics/Shaders/Input/UV.hpp"
#include <string>

Hikari::Shaders::Input::UV::UV( void ) : InputElement( "UV", "TEXCOORD", "float2" )
{
	m_InputElementDescription.SemanticIndex = 0;
	m_InputElementDescription.Format = DXGI_FORMAT_R32G32_FLOAT;
	m_InputElementDescription.InputSlot = 0;
	m_InputElementDescription.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	m_InputElementDescription.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	m_InputElementDescription.InstanceDataStepRate = 0;
}
