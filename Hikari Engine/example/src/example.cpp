#include <Windows.h>
#include <iostream>
#include "../include/ExampleApplication.hpp"
#include "../../include/Exception.hpp"
#include "../../include/Logger.hpp"

/**
	\fn int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
	\brief					G��wna funkcja WINAPI, jej zadaniem jest uruchomienie przyk�adowej aplikacji. Makro WINAPI powoduje odwr�cenie kolejno�ci parametr�w (z prawo-lewo na lewo-prawo)
	\param	hInstance		uchwyt do instancji aplikacji (wype�niane przez system przy uruchomieniu pliku wykonywalnego)
	\param	hPrevInstance	niby uchwyt do poprzedniej instancji, w praktyce nullptr
	\param	lpCmdLine		wska�nik na ci�g znak�w zawieraj�cy argumenty
	\param	nCmdShow		okre�la co powinno sta� si� z oknem: <ul><li>SW_SHOWNORMAL - aktywuje i wy�wietla je (przekazywane na starcie)</li><li>SW_SHOW - aktywuje i wy�wietla je w aktualnym miejscu</li><li>SW_HIDE - ukrywa je i aktywuje inne okno</li><li>SW_MAXIMIZE - maksymalizuje wybrane okno</li><li>SW_MINIMIZE - minimalizuje okno i aktywuje okno kt�re by�o pod nim</li><li>SW_RESTORE - je�li okno by�o zminimalizowane/zmaksymalizowane, zostanie przywr�cone do poprzedniego rozmiaru i po�o�enia</li><li>SW_SHOWMAXIMIZED - aktywuje i wy�wietla zmaksymalizowane</li><li>SW_SHOWMINIMIZED - aktywuje i wy�wietla zminimalizowane</li><li>SW_SHOWMINNOACTIVE - jak SW_SHOWMINIMIZED ale nie aktywuje okna</li><li>SW_SHOWNA - jak SW_SHOW, ale nie aktywuje</li><li>SW_SHOWNOACTIVE - jak SW_SHOWNORMAL, ale nie aktywuje</li></ul>
*/
int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine, int nCmdShow)
{
	Hikari::Application *application = new ExampleApplication();	// przyk�adowa aplikacja (z dost�pn� tylko i wy��cznie metod� run() )

	ExampleApplication *eApp = dynamic_cast<ExampleApplication*>(application);	// przyk�adowa aplikacja ze wszystkimi dost�pnymi metodami lub nullptr (je�li nie uda�o si� zrzutowa� na ExampleApplication*)
	if(eApp == nullptr)	// brak mozliwosci zrzutowania na ExampleApplication*
	{
		std::cerr << "Nie udalo sie dokonac dynamic_cast na ExampleApplication* (niezgodnosc typow)" << std::endl;
		system("PAUSE");
		return -1;
	}
	
	try
	{
		#ifdef DEBUG
			std::cout << "setup() przykladowej aplikacji" << std::endl;
		#endif
		eApp->setup(hInstance, lpCmdLine, nCmdShow);	// konfiguracja aplikacji; mogliby�my teoretycznie zrobi� to w konstruktorze, ale nie mo�na by�oby wtedy obs�u�y� ewentualnych b��d�w
	}
	catch(Exception& rException) /* wyj�tek podczas konfiguracji aplikacji */
	{
		std::cerr << "Przechwycono wyjatek " << rException.type() << ": " << rException.message() << std::endl;	// wypisujemy informacj� o b��dzie
		system("PAUSE");	// czekamy na wci�ni�cie dowolnego przycisku
		return -1;			// ko�czymy dzia�anie zwracaj�c kod b��du
	}

	#ifdef DEBUG
		std::cout << "Uruchamianie przykladowej aplikacji" << std::endl;
	#endif
	
	Hikari::Logger::addRecord("odpalam aplikacj�");
	Hikari::Logger::dump("test.txt");

	application->run();	// uruchamiamy aplikacj�

	return 0;
}