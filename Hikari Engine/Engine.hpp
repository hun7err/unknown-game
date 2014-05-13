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
	class WinAPIInput;

	LRESULT CALLBACK WndProc(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam); ///< wywo³ywane przez DispatchMessage, odpowiada za przetworzenie komunikatów okna

	class Engine
	{
		public:
			/** \brief	domyœlny konstruktor, zeruje wskaŸniki przygotowuj¹c do odpalenia */
			Engine();
			Engine(const Engine& rOther /** \brief	referencja do obiektu kopiowanego */);	// konstruktor kopiuj¹cy
			~Engine();	///< domyœlny destruktor (póki co nie robi nic)

			void setup(HINSTANCE hInstance /** \brief uchwyt do instancji aplikacji */, int nCmdShow /** \brief tryb wyœwietlania (patrz: WinAPIWindow.hpp) */);	///< przygotowuje silnik do pracy tworz¹c wymagane obiekty
			void run(void);			///< uruchamia pêtlê g³ówn¹ w³¹czaj¹c proces renderingu, obs³ugi wejœcia/wyjœcia itp. w pêtli g³ównej
			void stop(void);		///< zatrzymuje dzia³anie silnika przez ustawienie zmiennej m_Running na false, co powoduje wyjœcie z pêtli g³ównej
			void cleanup(void);		///< sprz¹ta po zakoñczonej pracy

			Manager<Object>* objectManager(void);	///< pobiera wskaŸnik na mened¿er obiektów; jeœli ten jest NULLem, rzucony zostaje wyj¹tek typu NullPointerException
			void objectManager(Manager<Object>* pObjectManager);	///< ustawia nowy mened¿er obiektów, lub - jeœli ma zostaæ ustawiony NULL - rzuca wyj¹tek Exception typu NullPointerException

			Manager<Material>* materialManager(void);	///< pobiera wskaŸnik na mened¿er materia³ów lub rzuca wyj¹tek Exception typu NullPointerException, jeœli ten jest NULLem
			void materialManager(Manager<Material>* pMaterialManager);	///< ustawia nowy mened¿er materia³ów lub rzuca wyj¹tek Exception typu NullPointerException, jeœli mia³by zostaæ ustawiony NULL

			Window* window(void);	// pobiera wskaŸnik na okno; jeœli mia³by zostaæ zwrócony NULL, rzucony zostanie wyj¹tek Exception typu NullPointerException
			void window(Window* pWindow);	// ustawia nowe okno jeœli pWindow nie jest NULLem, w przeciwnym wypadku rzucony zostanie wyj¹tek Exception typu NullPointerException

			// to mo¿e byæ zbêdne
			Application* application(void);
			void application(Application* application);
			// dot¹d

			WinAPIInput* input(void);		///< zwraca wskaŸnik na obiekt m_pInput klasy WinAPIInput odpowiadaj¹cy za obs³ugê wejœcia, lub - jeœli wskaŸnik ten jest NULLem - rzuca wyj¹tek Exception typu NullPointerException
			void input(WinAPIInput* pInput);	///< jeœli pInput nie jest NULLem, ustawia nowy wskaŸnik m_pInput na wartoœæ pInput - nie jest przeprowadzana walidacja kompatybilnoœci wskaŸników. Jeœli pInput jest NULLem, zostanie rzucony wyj¹tek Exception typu NullPointerException

			Renderer* renderer(void);	///< zwraca wskaŸnik na obiekt m_pRenderer klasy Renderer, lub - jeœli m_pRenderer jest NULLem - rzuca wyj¹tek Exception typu NullPointerException
			void renderer(Renderer* pRenderer);	///< jeœli pRenderer nie jest NULLem, zostanie ustawiony nowy renderer. Jeœli jest, zostanie rzucony wyj¹tek Exception typu NullPointerException

			LRESULT CALLBACK MessageHandler(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam); ///< procedura obs³ugi komunikatów okna przekazanych z WndProc(HWND, UINT, WPARAM, LPARAM)
			void processFrame(void);	///< odpowiada za przetworzenie pojedynczej klatki: zebranie inputu/outputu, rendering itp.

		private:
			bool m_Running;				///< czy pêtla g³ówna ma siê wykonywaæ?

			//LPCWSTR m_applicationName;	///< nazwa aplikacji
			HINSTANCE m_hInstance;		///< uchwyt do instancji aplikacji
			HWND m_hwnd;				///< uchwyt okna
			int m_nCmdShow;				///< tryb wyœwietlania okna
			WinAPIInput* m_pInput;		///< przetwarza input
			WinAPIWindow* m_pWindow;	///< okno WinAPI 

			Renderer* m_pRenderer;		///< generuje obraz metod¹ render()
			D3D11System* m_pD3DSystem;	///< odpowiada za utworzenie i zwolnienie urz¹dzenia D3D11 i jego kontekstu + swapChain
			Manager<Object>* m_pObjectManager;		///< mened¿er obiektów, przechowuje renderowane obiekty
			Manager<Material>* m_pMaterialManager;	///< mened¿er materia³ów
			Application* m_pApplication;			// mo¿liwe ¿e zbêdne

			// mutexy pozwalaj¹ce zablokowaæ zasoby nale¿¹ce do sekcji krytycznej
			std::mutex objectManagerMutex;
			std::mutex materialManagerMutex;
			std::mutex inputMutex;
			std::mutex runningMutex;
			std::mutex d3dsystemMutex;
			// dodaæ mutexy na wszystkie "krytyczne" obiekty
	};

	static Engine* EngineHandle = 0;	///< wskaŸnik na instancjê obiektu, pozwala uzyskaæ coœ w stylu Singletona (niestety jest to konieczne z punktu widzenia WndProc)
}

#endif // ENGINE_HPP