#include "Engine.hpp"
#include "Exception.hpp"
#include "SimpleRenderer.hpp"

Hikari::Engine::Engine(void)
{
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

void Hikari::Engine::setup(HINSTANCE hInstance, int nCmdShow)
{
	m_hInstance = hInstance;	// walidowaæ!
	m_nCmdShow = nCmdShow;	// walidowaæ!

	Hikari::EngineHandle = this;

	// m_pRenderer = new Hikari::

	// mutex
	//m_pRenderer = new SimpleRenderer();
	
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
	m_pWindow->setup(m_hInstance, m_nCmdShow);
	Vector2D windowSize = m_pWindow->size();

	m_pD3DSystem->setup(m_pWindow->handle(), m_pWindow->fullscreen(), m_pWindow->width(), m_pWindow->height(), 1);
	m_pRenderer->d3d11system(m_pD3DSystem);
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
			m_pInput->keyHandler(currentKey)(this);
		}
	}

	// podepnij bufory obiektów itp.
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

	Hikari::EngineHandle = NULL;
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
			return EngineHandle->MessageHandler(WindowHandle, message, wParam, lParam);
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
		throw new Exception("m_pWindow is not initialized in Engine::window(void)", "NullPointerException");
	}

	return m_pWindow;
}

void Hikari::Engine::window(Hikari::Window* pWindow)
{
	if(pWindow == NULL)
	{
		throw new Exception("Can't set new window to a NULL pointer in Engine::window(Window*)", "NullPointerException");
	}

	WinAPIWindow* newWindow = dynamic_cast<WinAPIWindow*>(pWindow);

	if(newWindow == NULL)
	{
		throw new Exception("Can't dynamically cast window parameter to WinAPIWindow in Engine::window(Window*)", "InvalidTypeException");
	}

	m_pWindow = newWindow;
}

Hikari::Application* Hikari::Engine::application(void)
{
	if(m_pApplication == NULL)
	{
		throw new Exception("m_pApplication is not initialized in Engine::application(void)", "NullPointerException");
	}

	return m_pApplication;
}

void Hikari::Engine::application(Hikari::Application* application)
{
	if(application == NULL)
	{
		throw new Exception("Can't set new application to a NULL pointer in Engine::application(Application*)", "NullPointerException");
	}

	m_pApplication = application;
}

Hikari::Renderer* Hikari::Engine::renderer(void)
{
	if(m_pRenderer == NULL)
	{
		throw new Exception("m_pRenderer is not initialized in Engine::renderer(void)", "NullPointerException");
	}

	return m_pRenderer;
}

void Hikari::Engine::renderer(Hikari::Renderer* pRenderer)
{
	if(pRenderer == NULL)
	{
		throw new Exception("Can't set new renderer to NULL in Engine::renderer(Renderer*)", "NullPointerException");
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
		throw new Exception("m_pInput is not initialized in Engine::input(void)", "NullPointerException");
	}

	return m_pInput;
}

void Hikari::Engine::input(Hikari::WinAPIInput* pInput)
{
	if(pInput == NULL)
	{
		throw new Exception("Can't set new input handler to a NULL pointer in Engine::input(WinAPIInput*)", "NullPointerException");
	}

	m_pInput = pInput;
}
