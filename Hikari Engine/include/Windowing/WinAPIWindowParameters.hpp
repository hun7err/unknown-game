#ifndef __WINAPIWINDOWPARAMETERSHPP__
#define __WINAPIWINDOWPARAMETERSHPP__

#include "../Helpers/ECS/Component.hpp"
#include <Windows.h>

namespace Hikari
{
	namespace Components
	{
		class WinAPIWindowParameters : public Component
		{
			public:
				WinAPIWindowParameters( void );
				
				HWND GetWindowHandle( void ) const;
				void SetWindowHandle( HWND WindowHandle );

				HINSTANCE GetInstanceHandle( void ) const;
				void SetInstanceHandle( HINSTANCE InstanceHandle );

				WNDCLASSEX GetWindowClassEx( void ) const;
				void SetWindowClassEx( WNDCLASSEX WindowClassEx );

				WNDPROC GetWndProcFunctionPtr( void ) const;
				void SetWndProcFunctionPtr( WNDPROC lpfnWndProc );

				int GetVisibility( void ) const;
				void SetVisibility( int visibility );

			private:
				HWND m_WindowHandle;
				HINSTANCE m_InstanceHandle;
				WNDCLASSEX m_WindowClassEx;
				WNDPROC m_lpfnWndProc;
				int m_Visibility;
		};
	}
}

#endif