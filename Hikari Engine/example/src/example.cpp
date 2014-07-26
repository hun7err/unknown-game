#include <Windows.h>
#include <iostream>
#include "../include/ExampleApplication.hpp"
#include "../../include/Exception.hpp"
#include "../../include/Logger.hpp"

/**
	\fn int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
	\brief					G³ówna funkcja WINAPI, jej zadaniem jest uruchomienie przyk³adowej aplikacji. Makro WINAPI powoduje odwrócenie kolejnoœci parametrów (z prawo-lewo na lewo-prawo)
	\param	hInstance		uchwyt do instancji aplikacji (wype³niane przez system przy uruchomieniu pliku wykonywalnego)
	\param	hPrevInstance	niby uchwyt do poprzedniej instancji, w praktyce nullptr
	\param	lpCmdLine		wskaŸnik na ci¹g znaków zawieraj¹cy argumenty
	\param	nCmdShow		okreœla co powinno staæ siê z oknem: <ul><li>SW_SHOWNORMAL - aktywuje i wyœwietla je (przekazywane na starcie)</li><li>SW_SHOW - aktywuje i wyœwietla je w aktualnym miejscu</li><li>SW_HIDE - ukrywa je i aktywuje inne okno</li><li>SW_MAXIMIZE - maksymalizuje wybrane okno</li><li>SW_MINIMIZE - minimalizuje okno i aktywuje okno które by³o pod nim</li><li>SW_RESTORE - jeœli okno by³o zminimalizowane/zmaksymalizowane, zostanie przywrócone do poprzedniego rozmiaru i po³o¿enia</li><li>SW_SHOWMAXIMIZED - aktywuje i wyœwietla zmaksymalizowane</li><li>SW_SHOWMINIMIZED - aktywuje i wyœwietla zminimalizowane</li><li>SW_SHOWMINNOACTIVE - jak SW_SHOWMINIMIZED ale nie aktywuje okna</li><li>SW_SHOWNA - jak SW_SHOW, ale nie aktywuje</li><li>SW_SHOWNOACTIVE - jak SW_SHOWNORMAL, ale nie aktywuje</li></ul>
*/
int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine, int nCmdShow)
{
	Hikari::Application *application = new ExampleApplication();	// przyk³adowa aplikacja (z dostêpn¹ tylko i wy³¹cznie metod¹ run() )

	ExampleApplication *eApp = dynamic_cast<ExampleApplication*>(application);	// przyk³adowa aplikacja ze wszystkimi dostêpnymi metodami lub nullptr (jeœli nie uda³o siê zrzutowaæ na ExampleApplication*)
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
		eApp->setup(hInstance, lpCmdLine, nCmdShow);	// konfiguracja aplikacji; moglibyœmy teoretycznie zrobiæ to w konstruktorze, ale nie mo¿na by³oby wtedy obs³u¿yæ ewentualnych b³êdów
	}
	catch(Exception& rException) /* wyj¹tek podczas konfiguracji aplikacji */
	{
		std::cerr << "Przechwycono wyjatek " << rException.type() << ": " << rException.message() << std::endl;	// wypisujemy informacjê o b³êdzie
		system("PAUSE");	// czekamy na wciœniêcie dowolnego przycisku
		return -1;			// koñczymy dzia³anie zwracaj¹c kod b³êdu
	}

	#ifdef DEBUG
		std::cout << "Uruchamianie przykladowej aplikacji" << std::endl;
	#endif
	
	Hikari::Logger::addRecord("odpalam aplikacjê");
	Hikari::Logger::dump("test.txt");

	application->run();	// uruchamiamy aplikacjê

	return 0;
}