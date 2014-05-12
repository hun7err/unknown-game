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
		- (!!!) Naprawi� -> tutoriale DX11, z Rastertek obs�uga okna itp.
		- ogarn�� kod i okomentowa� metody i zmienne
		- pododawa� nazwy argument�w metod
		- logo silnika
*/

namespace Hikari
{
	class WinAPIInput;

	LRESULT CALLBACK WndProc(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam); // czy static tu ma by�?

	class Engine
	{
		public:
			/** \brief	domy�lny konstruktor, zeruje wska�niki przygotowuj�c do odpalenia */
			Engine();
			Engine(const Engine& rOther /** \brief	referencja do obiektu kopiowanego */);	// konstruktor kopiuj�cy
			~Engine();	///< domy�lny destruktor (p�ki co nie robi nic)

			void setup(HINSTANCE hInstance, int nCmdShow);	///< przygotowuje silnik do pracy tworz�c wymagane obiekty
			void run(void);			///< uruchamia p�tl� g��wn� w��czaj�c proces renderingu, obs�ugi wej�cia/wyj�cia itp. w p�tli g��wnej
			void stop(void);		///< zatrzymuje dzia�anie silnika przez ustawienie zmiennej m_Running na false, co powoduje wyj�cie z p�tli g��wnej
			void cleanup(void);		///< sprz�ta po zako�czonej pracy

			Manager<Object>* objectManager(void);	///< pobiera wska�nik na mened�er obiekt�w; je�li ten jest NULLem, rzucony zostaje wyj�tek typu NullPointerException
			void objectManager(Manager<Object>* pObjectManager);	///< ustawia nowy mened�er obiekt�w, lub - je�li ma zosta� ustawiony NULL - rzuca wyj�tek Exception typu NullPointerException

			Manager<Material>* materialManager(void);	///< pobiera wska�nik na mened�er materia��w lub rzuca wyj�tek Exception typu NullPointerException, je�li ten jest NULLem
			void materialManager(Manager<Material>* pMaterialManager);	///< ustawia nowy mened�er materia��w lub rzuca wyj�tek Exception typu NullPointerException, je�li mia�by zosta� ustawiony NULL

			Window* window(void);	// pobiera wska�nik na okno
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

			// mutexy pozwalaj�ce zablokowa� zasoby nale��ce do sekcji krytycznej
			std::mutex objectManagerMutex;
			std::mutex materialManagerMutex;
			std::mutex inputMutex;
			std::mutex runningMutex;
			std::mutex d3dsystemMutex;
			// doda� mutexy na wszystkie "krytyczne" obiekty

			WinAPIWindow* m_pWindow;
	};

	static Engine* EngineHandle = 0;
}

#endif // ENGINE_HPP