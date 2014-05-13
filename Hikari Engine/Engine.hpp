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

	LRESULT CALLBACK WndProc(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam); ///< wywo�ywane przez DispatchMessage, odpowiada za przetworzenie komunikat�w okna

	class Engine
	{
		public:
			/** \brief	domy�lny konstruktor, zeruje wska�niki przygotowuj�c do odpalenia */
			Engine();
			Engine(const Engine& rOther /** \brief	referencja do obiektu kopiowanego */);	// konstruktor kopiuj�cy
			~Engine();	///< domy�lny destruktor (p�ki co nie robi nic)

			void setup(HINSTANCE hInstance /** \brief uchwyt do instancji aplikacji */, int nCmdShow /** \brief tryb wy�wietlania (patrz: WinAPIWindow.hpp) */);	///< przygotowuje silnik do pracy tworz�c wymagane obiekty
			void run(void);			///< uruchamia p�tl� g��wn� w��czaj�c proces renderingu, obs�ugi wej�cia/wyj�cia itp. w p�tli g��wnej
			void stop(void);		///< zatrzymuje dzia�anie silnika przez ustawienie zmiennej m_Running na false, co powoduje wyj�cie z p�tli g��wnej
			void cleanup(void);		///< sprz�ta po zako�czonej pracy

			Manager<Object>* objectManager(void);	///< pobiera wska�nik na mened�er obiekt�w; je�li ten jest NULLem, rzucony zostaje wyj�tek typu NullPointerException
			void objectManager(Manager<Object>* pObjectManager);	///< ustawia nowy mened�er obiekt�w, lub - je�li ma zosta� ustawiony NULL - rzuca wyj�tek Exception typu NullPointerException

			Manager<Material>* materialManager(void);	///< pobiera wska�nik na mened�er materia��w lub rzuca wyj�tek Exception typu NullPointerException, je�li ten jest NULLem
			void materialManager(Manager<Material>* pMaterialManager);	///< ustawia nowy mened�er materia��w lub rzuca wyj�tek Exception typu NullPointerException, je�li mia�by zosta� ustawiony NULL

			Window* window(void);	// pobiera wska�nik na okno; je�li mia�by zosta� zwr�cony NULL, rzucony zostanie wyj�tek Exception typu NullPointerException
			void window(Window* pWindow);	// ustawia nowe okno je�li pWindow nie jest NULLem, w przeciwnym wypadku rzucony zostanie wyj�tek Exception typu NullPointerException

			// to mo�e by� zb�dne
			Application* application(void);
			void application(Application* application);
			// dot�d

			WinAPIInput* input(void);		///< zwraca wska�nik na obiekt m_pInput klasy WinAPIInput odpowiadaj�cy za obs�ug� wej�cia, lub - je�li wska�nik ten jest NULLem - rzuca wyj�tek Exception typu NullPointerException
			void input(WinAPIInput* pInput);	///< je�li pInput nie jest NULLem, ustawia nowy wska�nik m_pInput na warto�� pInput - nie jest przeprowadzana walidacja kompatybilno�ci wska�nik�w. Je�li pInput jest NULLem, zostanie rzucony wyj�tek Exception typu NullPointerException

			Renderer* renderer(void);	///< zwraca wska�nik na obiekt m_pRenderer klasy Renderer, lub - je�li m_pRenderer jest NULLem - rzuca wyj�tek Exception typu NullPointerException
			void renderer(Renderer* pRenderer);	///< je�li pRenderer nie jest NULLem, zostanie ustawiony nowy renderer. Je�li jest, zostanie rzucony wyj�tek Exception typu NullPointerException

			LRESULT CALLBACK MessageHandler(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam); ///< procedura obs�ugi komunikat�w okna przekazanych z WndProc(HWND, UINT, WPARAM, LPARAM)
			void processFrame(void);	///< odpowiada za przetworzenie pojedynczej klatki: zebranie inputu/outputu, rendering itp.

		private:
			bool m_Running;				///< czy p�tla g��wna ma si� wykonywa�?

			//LPCWSTR m_applicationName;	///< nazwa aplikacji
			HINSTANCE m_hInstance;		///< uchwyt do instancji aplikacji
			HWND m_hwnd;				///< uchwyt okna
			int m_nCmdShow;				///< tryb wy�wietlania okna
			WinAPIInput* m_pInput;		///< przetwarza input
			WinAPIWindow* m_pWindow;	///< okno WinAPI 

			Renderer* m_pRenderer;		///< generuje obraz metod� render()
			D3D11System* m_pD3DSystem;	///< odpowiada za utworzenie i zwolnienie urz�dzenia D3D11 i jego kontekstu + swapChain
			Manager<Object>* m_pObjectManager;		///< mened�er obiekt�w, przechowuje renderowane obiekty
			Manager<Material>* m_pMaterialManager;	///< mened�er materia��w
			Application* m_pApplication;			// mo�liwe �e zb�dne

			// mutexy pozwalaj�ce zablokowa� zasoby nale��ce do sekcji krytycznej
			std::mutex objectManagerMutex;
			std::mutex materialManagerMutex;
			std::mutex inputMutex;
			std::mutex runningMutex;
			std::mutex d3dsystemMutex;
			// doda� mutexy na wszystkie "krytyczne" obiekty
	};

	static Engine* EngineHandle = 0;	///< wska�nik na instancj� obiektu, pozwala uzyska� co� w stylu Singletona (niestety jest to konieczne z punktu widzenia WndProc)
}

#endif // ENGINE_HPP