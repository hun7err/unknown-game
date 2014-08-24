#include "../../../../include/Graphics/Shaders/Input/Normal.hpp"

Hikari::Shaders::Input::Normal::Normal( void ) : InputElement("Normal", "NORMAL", "float4")
{
	m_InputElementDescription.SemanticIndex = 0;
	m_InputElementDescription.Format = DXGI_FORMAT_R32G32B32_FLOAT;
	m_InputElementDescription.InputSlot = 0;
	m_InputElementDescription.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	m_InputElementDescription.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	m_InputElementDescription.InstanceDataStepRate = 0;
}
