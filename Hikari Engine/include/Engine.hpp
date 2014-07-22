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
		- (!!!) Naprawiæ -> tutoriale DX11, z Rastertek obs³uga okna itp.
		- StackWalker -> stacktrace zbieraæ jak coœ siê stanie z³ego
		- logo silnika
*/

namespace Hikari
{
	class WinAPIInput;

	LRESULT CALLBACK WndProc(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam); ///< wywo³ywane przez DispatchMessage, odpowiada za przetworzenie komunikatów okna

	class Engine
	{
		public:
			/** \brief	domyœlny konstruktor, zeruje wskaŸniki przygotowuj¹c do odpalenia */
			~Engine();	///< domyœlny destruktor (póki co nie robi nic)

			static void initialize(HINSTANCE hApplicationInstance = nullptr, int nCmdShow = -1);
			static void run(void);			///< uruchamia pêtlê g³ówn¹ w³¹czaj¹c proces renderingu, obs³ugi wejœcia/wyjœcia itp. w pêtli g³ównej
			static void stop(void);		///< zatrzymuje dzia³anie silnika przez ustawienie zmiennej m_Running na false, co powoduje wyjœcie z pêtli g³ównej
			static void cleanup(void);		///< sprz¹ta po zakoñczonej pracy

			static Window* window(void);	// pobiera wskaŸnik na okno; jeœli mia³by zostaæ zwrócony NULL, rzucony zostanie wyj¹tek Exception typu NullPointerException
			static void window(Window* pWindow, unsigned int sampleCount = 1);	// ustawia nowe okno jeœli pWindow nie jest NULLem, w przeciwnym wypadku rzucony zostanie wyj¹tek Exception typu NullPointerException

			static WinAPIInput* input(void);		///< zwraca wskaŸnik na obiekt m_pInput klasy WinAPIInput odpowiadaj¹cy za obs³ugê wejœcia, lub - jeœli wskaŸnik ten jest NULLem - rzuca wyj¹tek Exception typu NullPointerException
			static void input(WinAPIInput* pInput);	///< jeœli pInput nie jest NULLem, ustawia nowy wskaŸnik m_pInput na wartoœæ pInput - nie jest przeprowadzana walidacja kompatybilnoœci wskaŸników. Jeœli pInput jest NULLem, zostanie rzucony wyj¹tek Exception typu NullPointerException

			static Renderer* renderer(void);	///< zwraca wskaŸnik na obiekt m_pRenderer klasy Renderer, lub - jeœli m_pRenderer jest NULLem - rzuca wyj¹tek Exception typu NullPointerException
			static void renderer(Renderer* pRenderer);	///< jeœli pRenderer nie jest NULLem, zostanie ustawiony nowy renderer. Jeœli jest, zostanie rzucony wyj¹tek Exception typu NullPointerException

			static HINSTANCE applicationInstanceHandle(void);
			static void applicationInstanceHandle(HINSTANCE newApplicationHandle);

			static int windowShowFlags(void);
			static void windowShowFlags(int newFlags);

			static D3D11System *d3dsystem(void);

			static LRESULT CALLBACK MessageHandler(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam); ///< procedura obs³ugi komunikatów okna przekazanych z WndProc(HWND, UINT, WPARAM, LPARAM)
			static void processFrame(void);	///< odpowiada za przetworzenie pojedynczej klatki: zebranie inputu/outputu, rendering itp.

		private:
			Engine();
			Engine(const Engine& rOther /** \brief	referencja do obiektu kopiowanego */);	// konstruktor kopiuj¹cy

			static bool m_Running;				///< czy pêtla g³ówna ma siê wykonywaæ?

			//LPCWSTR m_applicationName;	///< nazwa aplikacji
			static HINSTANCE m_hInstance;		///< uchwyt do instancji aplikacji
			static HWND m_hwnd;				///< uchwyt okna
			static int m_nCmdShow;				///< tryb wyœwietlania okna
			static WinAPIInput* m_pInput;		///< przetwarza input
			static WinAPIWindow* m_pWindow;	///< okno WinAPI 

			static Renderer* m_pRenderer;		///< generuje obraz metod¹ render()
			static D3D11System* m_pD3DSystem;	///< odpowiada za utworzenie i zwolnienie urz¹dzenia D3D11 i jego kontekstu + swapChain
			Application* m_pApplication;			// mo¿liwe ¿e zbêdne

			// mutexy pozwalaj¹ce zablokowaæ zasoby nale¿¹ce do sekcji krytycznej
			static std::mutex inputMutex;
			static std::mutex runningMutex;
			static std::mutex d3dsystemMutex;

			static const char buildDate[];
			static const char buildTime[];

			static Engine *m_pInstance;
			// dodaæ mutexy na wszystkie "krytyczne" obiekty
	};

	//static Engine* EngineHandle = 0;	///< wskaŸnik na instancjê obiektu, pozwala uzyskaæ coœ w stylu Singletona (niestety jest to konieczne z punktu widzenia WndProc)
}

#endif // __ENGINE_HPP__