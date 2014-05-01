#ifndef __WINAPI_WINDOW_H__
#define __WINAPI_WINDOW_H__

#include "Window.hpp"
#include <Windows.h>

namespace Hikari {
	class WinAPIWindow : public Window {
		public:
			WinAPIWindow(const char* title, unsigned int width = 800, unsigned int height = 600, unsigned int posX = 0, unsigned int posY = 0): Window(title, width, height, posX, posY) {}
			
			void Setup(HWND hWnd);
			void Shutdown(void);

			// dokoñczyæ + commit :f, potem testy czy wszystko jest ok z oknem i ca³ym frameworkiem
	};
}

#endif // __WINAPI_WINDOW_H__