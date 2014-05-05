#ifndef ENGINE_HPP
#define ENGINE_HPP

// biblioteka standardowa
#include <mutex>
// windows
#include <Windows.h>
// silnik
#include "WinAPIWindow.hpp"
#include "Application.hpp"
#include "WinAPIInput.hpp"
#include "Material.hpp"
#include "Renderer.hpp"
#include "Manager.hpp"
#include "Object.hpp"
#include "D3D11System.hpp"

/*
	to-do:
		- (!!!) Naprawiæ -> tutoriale DX11, z Rastertek obs³uga okna itp.
		- ogarn¹æ kod i okomentowaæ metody i zmienne
		- pododawaæ nazwy argumentów metod
		- logo silnika
*/

namespace Hikari
{
	static LRESULT CALLBACK WndProc(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam); // czy static tu ma byæ?

	class Engine
	{
		public:
			/** \brief	domyœlny konstruktor, zeruje wskaŸniki przygotowuj¹c do odpalenia */
			Engine();
			Engine(const Engine& rOther /** \brief	referencja do obiektu kopiowanego */);	// konstruktor kopiuj¹cy
			~Engine();	// domyœlny destruktor (póki co nie robi nic)

			void setup(HINSTANCE hInstance, int nCmdShow);	// przygotowuje silnik do pracy
			void run(void);
			void stop(void);
			void cleanup(void);		// sprz¹ta po zakoñczonej pracy

			Manager<Object>* objectManager(void);	// pobiera wskaŸnik na mened¿er obiektów
			void objectManager(Manager<Object>* pObjectManager);	// ustawia nowy mened¿er obiektów

			Manager<Material>* materialManager(void);	// pobiera wskaŸnik na mened¿er materia³ów
			void materialManager(Manager<Material>* pMaterialManager);	// ustawia nowy mened¿er materia³ów

			Window* window(void);	// pobiera wskaŸnik na okno
			void window(Window* window);	// ustawia nowe okno

			Application* application(void);
			void application(Application* application);

			WinAPIInput* input(void);
			void input(WinAPIInput* input);

			LRESULT CALLBACK MessageHandler(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam); //
			void processFrame(void);

		private:
			bool m_Running;

			LPCWSTR m_applicationName;
			HINSTANCE m_hInstance;
			HWND m_hwnd;
			int m_nCmdShow;
			WinAPIInput* m_pInput;

			Renderer* m_pRenderer;
			D3D11System* m_pD3DSystem;
			Manager<Object>* m_pObjectManager;
			Manager<Material>* m_pMaterialManager;
			Application* m_pApplication;

			std::mutex objectManagerMutex;
			std::mutex materialManagerMutex;
			std::mutex inputMutex;
			std::mutex runningMutex;
			std::mutex d3dsystemMutex;
			// dodaæ mutexy na wszystkie "krytyczne" obiekty

			WinAPIWindow* m_pWindow;
	};

	static Engine* EngineHandle = 0;
}

#endif // ENGINE_HPP