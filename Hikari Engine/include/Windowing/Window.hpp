#ifndef __WINDOWHPP__
#define __WINDOWHPP__

#include "../Core/Math/Vector2.hpp"
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

			const Vector2& GetPosition( void ) const;
			void SetPosition( const Vector2& newPosition );

			const Vector2& GetSize( void ) const;
			void Resize( const Vector2& newSize );

			WinAPIWindowParameters* GetWinAPIWindowParameters( void );

			~Window();

		private:
			void SetFullscreenProper( HWND WindowHandle, bool Fullscreen, int nCmdShow, float Width, float Height, float x, float y );
			std::string m_Title;
			bool m_Fullscreen;
			Vector2	m_Position,
						m_Size;
			WinAPIWindowParameters *m_pWindowParameters;

	};
}

#endif