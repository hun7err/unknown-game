#ifndef __WINDOWHPP__
#define __WINDOWHPP__

#include "../Helpers/Math/Vector2D.hpp"
#include "WinAPIWindowParameters.hpp"
#include <Windows.h>

namespace Hikari
{
	class Window
	{
		public:
			Window( const char* title, unsigned int width = 800, unsigned int height = 600, unsigned int posX = 0, unsigned int posY = 0 );
			void Create( void );
			void ChangeVisibility( int nCmdShow );

			bool IsFullscreen( void ) const;
			void SetFullscreen( bool fullscreen );

			const Vector2D& GetPosition( void ) const;
			void SetPosition( const Vector2D& newPosition );

			const Vector2D& GetSize( void ) const;
			void Resize( const Vector2D& newSize );

			WinAPIWindowParameters* GetWinAPIWindowParameters( void );

			~Window();

		private:
			void SetFullscreenProper( HWND WindowHandle, bool Fullscreen, int nCmdShow, float Width, float Height, float x, float y );
			std::string m_Title;
			bool m_Fullscreen;
			Vector2D	m_Position,
						m_Size;
			WinAPIWindowParameters *m_pWindowParameters;

	};
}

#endif