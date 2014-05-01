#ifndef __EXAMPLEAPPLICATION_HPP__
#define __EXAMPLEAPPLICATION_HPP__

#include "Application.hpp"
#include <Windows.h>

/**
	\class ExampleApplication
	\brief Przyk�adowa aplikacja wykorzystuj�ca Hikari Engine
*/
class ExampleApplication : public Application {
	public:
		void run(void);	///< dziedziczone z Application, uruchamia aplikacj� (czyli wszystko co istotne tak naprawd�)
		void setup(HINSTANCE hInstance, LPSTR lpCmdLine, int nCmdShow);	///< konfiguracja aplikacji: uchwyt do instancji, argumenty i tryb okna

		ExampleApplication();	///< p�ki co do konstruktora nic nie przekazujemy
		~ExampleApplication();	///< w destruktorze na t� chwil� nie ma co usuwa�, wi�c jest pusty
	private:
		HINSTANCE m_hInstance;	///< uchwyt do uruchomionej aplikacji (patrz: example.cpp)
		LPSTR m_lpCmdLine;		///< argumenty linii polece�
		int m_nCmdShow;			///< tryb wy�wietlania okna
};

#endif // __EXAMPLEAPPLICATION_HPP__