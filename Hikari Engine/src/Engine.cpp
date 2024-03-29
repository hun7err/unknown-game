#include "../include/Engine.hpp"
#include "../include/Exception.hpp"
#include "../include/SimpleRenderer.hpp"

bool Hikari::Engine::m_Running = false;
HINSTANCE Hikari::Engine::m_hInstance;
HWND Hikari::Engine::m_hwnd;
int Hikari::Engine::m_nCmdShow;
Hikari::WinAPIInput *Hikari::Engine::m_pInput = NULL;
Hikari::WinAPIWindow *Hikari::Engine::m_pWindow = NULL;
Hikari::Renderer *Hikari::Engine::m_pRenderer = NULL;
Hikari::D3D11System *Hikari::Engine::m_pD3DSystem = NULL;
std::mutex Hikari::Engine::inputMutex;
std::mutex Hikari::Engine::runningMutex;
std::mutex Hikari::Engine::d3dsystemMutex;
Hikari::Engine *Hikari::Engine::m_pInstance = NULL;
	
const char Hikari::Engine::buildDate[] = __DATE__;
const char Hikari::Engine::buildTime[] = __TIME__;

Hikari::Engine::Engine(void)
{
	m_pInstance = this;
	m_pRenderer = NULL;
	m_pD3DSystem = NULL;
	m_pInput = NULL;
	m_Running = false;
}

Hikari::Engine::Engine(const Hikari::Engine& rOther)
{
}

Hikari::Engine::~Engine()
{
}

HINSTANCE Hikari::Engine::applicationInstanceHandle(void)
{
	return m_hInstance;
}

void Hikari::Engine::applicationInstanceHandle(HINSTANCE hApplicationInstance)
{
	m_hInstance = hApplicationInstance;
}

int Hikari::Engine::windowShowFlags(void)
{
	return m_nCmdShow;
}

void Hikari::Engine::windowShowFlags(int newFlags)
{
	m_nCmdShow = newFlags;
}

void Hikari::Engine::initialize(HINSTANCE hApplicationInstance, int nCmdShow)
{
	m_hInstance = hApplicationInstance;
	m_nCmdShow = nCmdShow;

	inputMutex.lock();
	m_pInput = new Hikari::WinAPIInput();
	inputMutex.unlock();

	d3dsystemMutex.lock();
	m_pD3DSystem = new Hikari::D3D11System();
	d3dsystemMutex.unlock();

	m_pInput->setup();
}

void Hikari::Engine::run(void)
{
	Vector2D windowSize = m_pWindow->size();

	// wyrzuci� to do setup albo initialize
	m_pRenderer->setup(m_pWindow->width(), m_pWindow->height());

	MSG eventMessage;
	ZeroMemory(&eventMessage, sizeof(MSG));

	runningMutex.lock();
	m_Running = true;
	runningMutex.unlock();

	while(true)
	{
		if(PeekMessage(&eventMessage, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&eventMessage);
			DispatchMessage(&eventMessage);
		}

		if(eventMessage.message == WM_QUIT)
		{
			stop();
		}
		else
		{
			processFrame();
		}

		runningMutex.lock();
		if(m_Running == false)
		{
			runningMutex.unlock();
			break;
		}
		runningMutex.unlock();
	}
}

void Hikari::Engine::stop(void)
{
	runningMutex.lock();
	if(m_Running == true)
	{
		m_Running = false;
	}
	runningMutex.unlock();
}

void Hikari::Engine::processFrame(void)
{
	for(int currentKey = 0; currentKey < 256; currentKey++)
	{
		if( m_pInput->keyHandler(currentKey) != nullptr && m_pInput->isKeyDown(currentKey) )
		{
			m_pInput->keyHandler(currentKey)();
		}
	}

	// podepnij bufory obiekt�w itp.
	m_pRenderer->render();
}

void Hikari::Engine::cleanup(void)
{
	// mutex
	m_pRenderer->cleanup();
	delete m_pRenderer;
	m_pRenderer = NULL;

	m_pD3DSystem->cleanup();

	delete m_pInput;
	m_pInput = NULL;

	//Hikari::EngineHandle = NULL;
}

LRESULT CALLBACK Hikari::WndProc(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		case WM_CLOSE:
		{
			PostQuitMessage(0);
			return 0;
		}
		default:
		{
			return Engine::MessageHandler(WindowHandle, message, wParam, lParam);
		}
	}
}

LRESULT CALLBACK Hikari::Engine::MessageHandler(HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_KEYDOWN:
		{
			m_pInput->keyDown((unsigned int)wParam);
			return 0;
		}
		case WM_KEYUP:
		{
			m_pInput->keyUp((unsigned int)wParam);
			return 0;
		}
		default:
		{
			return DefWindowProc(WindowHandle, message, wParam, lParam);
		}
	}
}

Hikari::Window* Hikari::Engine::window(void)
{
	if(m_pWindow == NULL)
	{
		throw Exception("m_pWindow is not initialized in Engine::window(void)", "NullPointerException");
	}

	return m_pWindow;
}

void Hikari::Engine::window(Hikari::Window* pWindow, unsigned int sampleCount)
{
	if(pWindow == NULL)
	{
		throw Exception("Can't set new window to a NULL pointer in Engine::window(Window*)", "NullPointerException");
	}

	WinAPIWindow* newWindow = dynamic_cast<WinAPIWindow*>(pWindow);

	if(newWindow == NULL)
	{
		throw Exception("Can't dynamically cast window parameter to WinAPIWindow in Engine::window(Window*,uint)", "InvalidTypeException");
	}

	m_pWindow = newWindow;
	m_pWindow->setup(m_hInstance, m_nCmdShow);
	m_pD3DSystem->setup(m_pWindow->handle(), m_pWindow->fullscreen(), m_pWindow->width(), m_pWindow->height(), sampleCount);
}

Hikari::Renderer* Hikari::Engine::renderer(void)
{
	if(m_pRenderer == NULL)
	{
		throw Exception("m_pRenderer is not initialized in Engine::renderer(void)", "NullPointerException");
	}

	return m_pRenderer;
}

void Hikari::Engine::renderer(Hikari::Renderer* pRenderer)
{
	if(pRenderer == NULL)
	{
		throw Exception("Can't set new renderer to NULL in Engine::renderer(Renderer*)", "NullPointerException");
	}

	if(m_pRenderer != NULL)
	{
		delete m_pRenderer;
	}

	m_pRenderer = pRenderer;
}

Hikari::WinAPIInput* Hikari::Engine::input(void)
{
	if(m_pInput == NULL)
	{
		throw Exception("m_pInput is not initialized in Engine::input(void)", "NullPointerException");
	}

	return m_pInput;
}

void Hikari::Engine::input(Hikari::WinAPIInput* pInput)
{
	if(pInput == NULL)
	{
		throw Exception("Can't set new input handler to a NULL pointer in Engine::input(WinAPIInput*)", "NullPointerException");
	}

	m_pInput = pInput;
}

Hikari::D3D11System *Hikari::Engine::d3dsystem(void)
{
	return m_pD3DSystem;
}
