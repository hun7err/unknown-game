#ifndef __EXAMPLEAPPLICATION_HPP__
#define __EXAMPLEAPPLICATION_HPP__

#include "Application.hpp"
#include <Windows.h>

/**
	\class ExampleApplication
	\brief Przyk³adowa aplikacja wykorzystuj¹ca Hikari Engine
*/
class ExampleApplication : public Application {
	public:
		void run(void);	///< dziedziczone z Application, uruchamia aplikacjê (czyli wszystko co istotne tak naprawdê)
		void setup(HINSTANCE hInstance, LPSTR lpCmdLine, int nCmdShow);	///< konfiguracja aplikacji: uchwyt do instancji, argumenty i tryb okna

		ExampleApplication();	///< póki co do konstruktora nic nie przekazujemy
		~ExampleApplication();	///< w destruktorze na t¹ chwilê nie ma co usuwaæ, wiêc jest pusty
	private:
		HINSTANCE m_hInstance;	///< uchwyt do uruchomionej aplikacji (patrz: example.cpp)
		LPSTR m_lpCmdLine;		///< argumenty linii poleceñ
		int m_nCmdShow;			///< tryb wyœwietlania okna
};

#endif // __EXAMPLEAPPLICATION_HPP__