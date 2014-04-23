#ifndef ENGINE_H
#define ENGINE_H

#include <Windows.h>

/*
	to-do:
		- ogarn¹æ kod i okomentowaæ metody i zmienne
		- zamieniæ m_Graphics na Renderer które bêdzie klas¹ abstrakcyjn¹ (void render())
			- DeferredRenderer itp.
		- pododawaæ nazwy argumentów metod
		- logo silnika
*/

namespace Hikari
{
	class Engine {
		public:
			Engine();
			Engine(const Engine&);
			~Engine();

			void Setup();
			void Shutdown();
			void Run();

			LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

		private:
			bool Frame();
			void InitializeWindows(int&, int&);
			void ShutdownWindows();

			LPCWSTR m_applicationName;
			HINSTANCE m_hInstance;
			HWND m_hwnd;

			WinAPIInput* m_Input;
			GraphicsClass* m_Graphics;
	};

	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	static Engine* ApplicationHandle = 0;
}

#endif // ENGINE_H