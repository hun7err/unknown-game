#include "ExampleApplication.h"
#include "../WrongArgumentException.h"
#include "../Engine.h"

ExampleApplication::ExampleApplication() {}

void ExampleApplication::setup(HINSTANCE hInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if(hInstance == NULL)
	{
		throw new WrongArgumentException("niepoprawny argument hInstance(NULL)");
	}

	if(lpCmdLine == NULL)
	{
		throw new WrongArgumentException("niepoprawny argument lpCmdLine (NULL)");
	}

	int options = SW_SHOWNORMAL|SW_SHOW|SW_HIDE|SW_MAXIMIZE|SW_MINIMIZE|SW_RESTORE|SW_SHOWMAXIMIZED|SW_SHOWMINIMIZED|SW_SHOWMINNOACTIVE|SW_SHOWNA|SW_SHOWNOACTIVATE;
	if(! (nCmdShow & options))
	{
		throw new WrongArgumentException("niepoprawny parametr nCmdShow");
	}
}

void ExampleApplication::run(void)
{
	Hikari::Engine* engine;
	bool result;

	engine = new Hikari::Engine();
	if(!engine)
	{
		throw new Exception("Could not create Hikari::Engine instance", "EngineInitException");
	}

	engine->Setup().setWindowTitle("Example application");

	engine->Run();

	// to-do:
	// - przepisaæ wszystko z engine, aby bardziej by³o silnikiem ni¿ frameworkiem
	// - wielkie litery zmienic na male na poczatku linii

	engine->Shutdown();
	delete engine;
	engine = NULL;

	// g³ówna czêœæ aplikacji
}

ExampleApplication::~ExampleApplication() {}
