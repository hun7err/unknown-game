#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

// biblioteka standardowa
#include <mutex>
// windows
#include <Windows.h>
// silnik
#include "WinAPIWindow.hpp"
#include "Application.hpp"
#include "WinAPIInput.hpp"
#include "Renderer.hpp"
#include "D3D11System.hpp"

/*
	to-do:
		- (!!!) Naprawi� -> tutoriale DX11, z Rastertek obs�uga okna itp.
		- StackWalker -> stacktrace zbiera� jak co� si� stanie z�ego
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
			~Engine();	///< domy�lny destruktor (p�ki co nie robi nic)

			static void initialize(HINSTANCE hApplicationInstance = nullptr, int nCmdShow = -1);
			static void run(void);			///< uruchamia p�tl� g��wn� w��czaj�c proces renderingu, obs�ugi wej�cia/wyj�cia itp. w p�tli g��wnej
			static void stop(void);		///< zatrzymuje dzia�anie silnika przez ustawienie zmiennej m_Running na false, co powoduje wyj�cie z p�tli g��wnej
			static void cleanup(void);		///< sprz�ta po zako�czonej pracy

			static Window* window(void);	// pobiera wska�nik na okno; je�li mia�by zosta� zwr�cony NULL, rzucony zostanie wyj�tek Exception typu NullPointerException
			static void window(Window* pWindow, unsigned int sampleCount = 1);	// ustawia nowe okno je�li pWindow nie jest NULLem, w przeciwnym wypadku rzucony zostanie wyj�tek Exception typu NullPointerException

			static WinAPIInput* input(void);		///< zwraca wska�nik na obiekt m_pInput klasy WinAPIInput odpowiadaj�cy za obs�ug� wej�cia, lub - je�li wska�nik ten jest NULLem - rzuca wyj�tek Exception typu NullPointerException
			static void input(WinAPIInput* pInput);	///< je�li pInput nie jest NULLem, ustawia nowy wska�nik m_pInput na warto�� pInput - nie jest przeprowadzana walidacja kompatybilno�ci wska�nik�w. Je�li pInput jest NULLem, zostanie rzucony wyj�tek Exception typu NullPointerException

			static Renderer* renderer(void);	///< zwraca wska�nik na obiekt m_pRenderer klasy Renderer, lub - je�li m_pRenderer jest NULLem - rzuca wyj�tek Exception typu NullPointerException
			static void renderer(Renderer* pRenderer);	///< je�li pRenderer nie jest NULLem, zostanie ustawiony nowy renderer. Je�li jest, zostanie rzucony wyj�tek Exception typu NullPointerException

			static HINSTANCE applicationInstanceHandle(void);
			static void applicationInstanceHandle(HINSTANCE newApplicationHandle);

			static int windowShowFlags(void);
			static void windowShowFlags(int newFlags);

			static D3D11System *d3dsystem(void);

			static LRESULT CALLBACK MessageHandler(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam); ///< procedura obs�ugi komunikat�w okna przekazanych z WndProc(HWND, UINT, WPARAM, LPARAM)
			static void processFrame(void);	///< odpowiada za przetworzenie pojedynczej klatki: zebranie inputu/outputu, rendering itp.

		private:
			Engine();
			Engine(const Engine& rOther /** \brief	referencja do obiektu kopiowanego */);	// konstruktor kopiuj�cy

			static bool m_Running;				///< czy p�tla g��wna ma si� wykonywa�?

			//LPCWSTR m_applicationName;	///< nazwa aplikacji
			static HINSTANCE m_hInstance;		///< uchwyt do instancji aplikacji
			static HWND m_hwnd;				///< uchwyt okna
			static int m_nCmdShow;				///< tryb wy�wietlania okna
			static WinAPIInput* m_pInput;		///< przetwarza input
			static WinAPIWindow* m_pWindow;	///< okno WinAPI 

			static Renderer* m_pRenderer;		///< generuje obraz metod� render()
			static D3D11System* m_pD3DSystem;	///< odpowiada za utworzenie i zwolnienie urz�dzenia D3D11 i jego kontekstu + swapChain
			Application* m_pApplication;			// mo�liwe �e zb�dne

			// mutexy pozwalaj�ce zablokowa� zasoby nale��ce do sekcji krytycznej
			static std::mutex inputMutex;
			static std::mutex runningMutex;
			static std::mutex d3dsystemMutex;

			static const char buildDate[];
			static const char buildTime[];

			static Engine *m_pInstance;
			// doda� mutexy na wszystkie "krytyczne" obiekty
	};

	//static Engine* EngineHandle = 0;	///< wska�nik na instancj� obiektu, pozwala uzyska� co� w stylu Singletona (niestety jest to konieczne z punktu widzenia WndProc)
}

#endif // __ENGINE_HPP__