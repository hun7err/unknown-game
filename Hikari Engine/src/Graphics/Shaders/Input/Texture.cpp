#include "../../../../include/Graphics/Shaders/Input/Texture.hpp"
#include "../../../../include/Graphics/Shaders/Input/SamplerState.hpp"
#include "../../../../include/Graphics/Shaders/Input/UV.hpp"

Hikari::Shaders::Input::Texture::Texture( const std::string& TextureID ) : Entity( TextureID ), Component( "Texture" )
{
	Component *pUV = new UV();
	Component *pSamplerState = new SamplerState();

	AddComponent(pUV);
	AddComponent(pSamplerState);
}
