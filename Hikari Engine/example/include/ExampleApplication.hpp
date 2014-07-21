#ifndef __EXAMPLEAPPLICATION_HPP__
#define __EXAMPLEAPPLICATION_HPP__

#include <Windows.h>			// HINSTANCE, LPSTR itp.
#include "../../include/Application.hpp"	// Hikari::Application
#include "../../include/Engine.hpp"		// Hikari::Engine

/**
	\class ExampleApplication
	\brief Przyk³adowa aplikacja wykorzystuj¹ca Hikari Engine
*/
class ExampleApplication : public Hikari::Application
{
	public:
		void run(void);	///< dziedziczone z Application, uruchamia aplikacjê (czyli wszystko co istotne tak naprawdê)
		void setup(HINSTANCE hInstance, LPSTR lpCmdLine, int nCmdShow);	///< konfiguracja aplikacji: uchwyt do instancji, argumenty i tryb okna

		void stopEngine(Hikari::Engine* pEngine);	///< metoda zatrzymuj¹ca silnik (zbindujemy j¹ do odpowiedniego przycisku)
		ExampleApplication();	///< póki co do konstruktora nic nie przekazujemy
		~ExampleApplication();	///< w destruktorze na tê chwilê nie ma co usuwaæ, wiêc jest pusty
	private:
		HINSTANCE m_hInstance;	///< uchwyt do uruchomionej aplikacji (patrz: example.cpp)
		LPSTR m_lpCmdLine;		///< argumenty linii poleceñ
		int m_nCmdShow;			///< tryb wyœwietlania okna
};

#endif // __EXAMPLEAPPLICATION_HPP__