#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <mutex>
#include <Windows.h>
#include "WinAPIWindow.hpp"
#include "WinAPIInput.hpp"
#include "Renderer.hpp"
#include "Manager.hpp"
#include "Object.hpp"
#include "Material.hpp"

/*
	to-do:
		- (!!!) Naprawiæ -> tutoriale DX11, z Rastertek obs³uga okna itp.
		- ogarn¹æ kod i okomentowaæ metody i zmienne
		- pododawaæ nazwy argumentów metod
		- logo silnika
*/

namespace Hikari
{
	/*static*/ LRESULT CALLBACK WndProc(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam);

	class Engine {
		public:
			Engine();
			Engine(const Engine& rOther);
			~Engine();

			void setup(void);
			void cleanup(void);

			Manager<Object>* objectManager(void);
			void objectManager(Manager<Object>* pObjectManager);

			Manager<Material>* materialManager(void);
			void materialManager(Manager<Material>* pMaterialManager);

			Engine& setWindowTitle(const char* title);
			Engine& setWindowSize(unsigned int width, unsigned int height);

			LRESULT CALLBACK MessageHandler(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam);

		private:
			bool Frame();

			LPCWSTR m_applicationName;
			HINSTANCE m_hInstance;
			HWND m_hwnd;

			WinAPIInput* m_Input;
			Renderer* m_pRenderer;
			Manager<Object>* m_pObjectManager;
			Manager<Material>* m_pMaterialManager;

			std::mutex objectManagerMutex;
			std::mutex materialManagerMutex;

			WinAPIWindow* m_Window;
	};

	static Engine* EngineHandle = 0;
}

#endif // ENGINE_HPP