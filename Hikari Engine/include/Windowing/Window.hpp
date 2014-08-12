#ifndef __WINDOWHPP__
#define __WINDOWHPP__

#include "../Helpers/ECS/Component.hpp"
#include "../Helpers/ECS/Entity.hpp"
#include "../Helpers/Math/Vector2D.hpp"
#include <Windows.h>

namespace Hikari
{
	namespace Entities
	{
		class Window : public Entity
		{
			public:
				Window( const char* title, unsigned int width = 800, unsigned int height = 600, unsigned int posX = 0, unsigned int posY = 0 );
				void Create( void );
				void ChangeVisibility( int nCmdShow );
				void SetFullscreen( bool fullscreen );

				~Window();
			private:
				void SetFullscreenProper( HWND WindowHandle, bool Fullscreen, int nCmdShow, float Width, float Height, float x, float y );
		};
	}
}

#endif