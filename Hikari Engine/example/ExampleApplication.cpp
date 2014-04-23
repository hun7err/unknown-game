#include "ExampleApplication.h"
#include "../WrongArgumentException.h"

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
	// g³ówna czêœæ aplikacji
}

ExampleApplication::~ExampleApplication() {}
