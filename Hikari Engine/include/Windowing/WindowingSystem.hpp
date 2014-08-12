#ifndef __WINDOWINGSYSTEMHPP__
#define __WINDOWINGSYSTEMHPP__

#include "../Helpers/ECS/System.hpp"
#include "../Core/Messaging/Messenger.hpp"
#include "../Core/Messaging/Listener.hpp"
#include "../Core/Engine.hpp"
#include "Window.hpp"
#include <Windows.h>

namespace Hikari
{
	class WindowingSystem : public System
	{
		public:
			WindowingSystem( void );

			void Init( Engine *pEngine );
			void Update( float dt );
			
			Messenger *GetMessenger( void );
			static LRESULT CALLBACK WndProc( HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam );

			~WindowingSystem();

		private:
			LRESULT CALLBACK HandleInput( HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam );
			void SystemKeyPressHandler(Message *pMessage);

			static WindowingSystem *m_pInstance;
			Entities::Window *m_pMainWindow;
			Messenger *m_pMessenger;
			Listener *m_pListener;

			Engine *m_pEngine;
	};
}

#endif