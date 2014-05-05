#include "ExampleApplication.hpp"
#include "../WrongArgumentException.hpp"
#include "../WinAPIWindow.hpp"
#include <functional>

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

	m_hInstance = hInstance;
	m_lpCmdLine = lpCmdLine;
	m_nCmdShow = nCmdShow;
}

void ExampleApplication::stopEngine(Hikari::Engine* pEngine)
{
	pEngine->stop();
}

void ExampleApplication::run(void)
{
	Hikari::Engine* engine;

	engine = new Hikari::Engine();
	if(!engine)
	{
		throw new Exception("Could not create Hikari::Engine instance", "EngineInitException");
	}

	engine->setup(m_hInstance, m_nCmdShow);
	Hikari::Window* mainWindow = new Hikari::WinAPIWindow("Hikari::Engine application", 800, 600, 100, 100);
	engine->window(mainWindow);
	std::function<void(Hikari::Engine*)> escHandler = std::bind(&ExampleApplication::stopEngine, this, std::placeholders::_1);
	engine->input()->keyHandler(VK_ESCAPE, escHandler);

	engine->run();

	engine->cleanup();
	delete engine;
	engine = NULL;
}

ExampleApplication::~ExampleApplication() {}
