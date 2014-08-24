#ifndef __HIKARI_GRAPHICS_SHADERS_INPUT_INPUTELEMENTHPP__
#define __HIKARI_GRAPHICS_SHADERS_INPUT_INPUTELEMENTHPP__

#include "../../../Helpers/ECS/Component.hpp"
#include <string>
#include <d3d11.h>

namespace Hikari
{
	namespace Shaders
	{
		namespace Input
		{
			class InputElement : public Component
			{
				public:
					InputElement( LPCSTR SemanticNameBase, const std::string& type );
					InputElement( const std::string& ComponentName, LPCSTR SemanticNameBase, const std::string& type );
					~InputElement( void );

					void SetSemanticName( int offset = -1 );
					D3D11_INPUT_ELEMENT_DESC GetInputElementDescription( void ) const;

					const std::string& GetType( void ) const;

				protected:
					D3D11_INPUT_ELEMENT_DESC m_InputElementDescription;
					LPCSTR m_SemanticNameBase;
					std::string m_Type;
			};
		}
	}
}

#endif