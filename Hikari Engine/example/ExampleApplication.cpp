#include "ExampleApplication.hpp"
#include "../WrongArgumentException.hpp"
#include "../WinAPIWindow.hpp"
#include "../SimpleRenderer.hpp"
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

/*
	to-do:
	
	- dodaæ tu komentarze w kodzie
	- dokoñczyæ komentowanie ca³oœci (zwróciæ uwagê przy pierwszych plikach na to, czy opisane s¹ wyj¹tki rzucane przy z³ych parametrach/z³ych memberach)
	- dodaæ ustawianie DEBUG na 1 w Debug, a na 0 w Release
	- dodaæ zwalnianie poprzednich wskaŸników przy ustawianiu nowych memberów, które s¹ wskaŸnikami
	- sprawdziæ, czy wyj¹tki nie powoduj¹ memory leaków
	- dodaæ obs³ugê b³êdów inicjalizacji DirectXa (np. brak wsparcia)
	- Engine jako Singleton?
	- ObjectGroup jako kompozyt
	- Logger jako singleton
*/

void ExampleApplication::run(void)
{
	Hikari::Engine* engine;

	engine = new Hikari::Engine();
	if(!engine)
	{
		throw new Exception("Could not create Hikari::Engine instance", "EngineInitException");
	}

	engine->setup(m_hInstance, m_nCmdShow);
	
	Hikari::Renderer* myRenderer = new Hikari::SimpleRenderer();
	engine->renderer(myRenderer);

	Hikari::Window* mainWindow = new Hikari::WinAPIWindow("Hikari::Engine application", 800, 600, 100, 100);
	engine->window(mainWindow);

	std::function<void(Hikari::Engine*)> escHandler = std::bind(&ExampleApplication::stopEngine, this, std::placeholders::_1);
	engine->input()->keyHandler(VK_ESCAPE, escHandler);	// ustaw escHandler jako procedurê obs³ugi przycisku Escape

	engine->run();

	engine->cleanup();
	delete engine;
	engine = NULL;
}

ExampleApplication::~ExampleApplication() {}
