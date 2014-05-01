#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <Windows.hpp>
#include "WinAPIWindow.hpp"
#include "Renderer.hpp"

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

			Engine& Setup();
			void Shutdown();
			void Run();

			Engine& setWindowTitle(const char* title);
			Engine& setWindowSize(unsigned int width, unsigned int height);

			LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

		private:
			bool Frame();
			void InitializeWindows(int&, int&);
			void ShutdownWindows();

			LPCWSTR m_applicationName;
			HINSTANCE m_hInstance;
			HWND m_hwnd;

			WinAPIInput* m_Input;
			Renderer* m_Renderer;
			WinAPIWindow* m_Window;
	};

	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	static Engine* ApplicationHandle = 0;
}

#endif // ENGINE_HPP