#include "Engine.hpp"
#include "Exception.hpp"
#include "SimpleRenderer.hpp"

Hikari::Engine::Engine(void)
{
	m_pRenderer = NULL;
	m_pObjectManager = NULL;
	m_pMaterialManager = NULL;
	m_pD3DSystem = NULL;
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

	// m_pRenderer = new Hikari::
	objectManagerMutex.lock();
	m_pObjectManager = new Hikari::Manager<Object>();
	objectManagerMutex.unlock();

	materialManagerMutex.lock();
	m_pMaterialManager = new Hikari::Manager<Material>();
	materialManagerMutex.unlock();

	// mutex
	m_pRenderer = new SimpleRenderer();
	
	inputMutex.lock();
	m_pInput = new Hikari::WinAPIInput();
	inputMutex.unlock();

	d3dsystemMutex.lock();
	m_pD3DSystem = new Hikari::D3D11System();
	d3dsystemMutex.unlock();

	m_pObjectManager->setup();
	m_pMaterialManager->setup();
	m_pInput->setup();
}

void Hikari::Engine::run(void)
{
	m_pWindow->setup(m_hInstance, m_nCmdShow);
	Vector2D windowSize = m_pWindow->size();

	m_pD3DSystem->setup(m_pWindow->handle(), m_pWindow->fullscreen(), m_pWindow->width(), m_pWindow->height(), 1);
	m_pRenderer->d3d11system(m_pD3DSystem);
	m_pRenderer->setup(windowSize.x(), windowSize.y());

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
			// ustaliæ czemu tutaj jest jakiœ b³¹d z abort() przy wyjœciu
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
		runningMutex.unlock();
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
	m_pRenderer->cleanup();
	m_pD3DSystem->cleanup();

	objectManagerMutex.lock();
	m_pObjectManager->cleanup();
	delete m_pObjectManager;
	m_pObjectManager = NULL;
	objectManagerMutex.unlock();

	materialManagerMutex.lock();
	m_pMaterialManager->cleanup();
	delete m_pMaterialManager;
	m_pMaterialManager = NULL;
	materialManagerMutex.unlock();

	// mutex
	m_pRenderer->cleanup();
	delete m_pRenderer;
	m_pRenderer = NULL;
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

Hikari::Manager<Hikari::Object>* Hikari::Engine::objectManager(void)
{
	objectManagerMutex.lock();
	if(m_pObjectManager == NULL)
	{
		objectManagerMutex.unlock();
		throw new Exception("m_pObjectManager is not initialized in Engine::objectManager(void)", "NullPointerException");
	}
	objectManagerMutex.unlock();

	return m_pObjectManager;
}

void Hikari::Engine::objectManager(Hikari::Manager<Hikari::Object>* pObjectManager)
{
	if(pObjectManager == NULL)
	{
		throw new Exception("Can't set new ObjectManager to a NULL pointer in Engine::objectManager(Manager<Object>*)", "NullPointerException");
	}

	m_pObjectManager = pObjectManager;
}

Hikari::Manager<Hikari::Material>* Hikari::Engine::materialManager(void)
{
	materialManagerMutex.lock();
	if(m_pObjectManager == NULL)
	{
		materialManagerMutex.unlock();
		throw new Exception("m_pObjectManager is not initialized in Engine::materialManager(void)", "NullPointerException");
	}
	materialManagerMutex.unlock();

	return m_pMaterialManager;
}

void Hikari::Engine::materialManager(Hikari::Manager<Hikari::Material>* pMaterialManager)
{
	if(pMaterialManager == NULL)
	{
		throw new Exception("Can't set new MaterialManager to a NULL pointer in Engine::objectManager(Manager<Material>*)", "NullPointerException");
	}

	m_pMaterialManager = pMaterialManager;
}

Hikari::Window* Hikari::Engine::window(void)
{
	if(m_pWindow == NULL)
	{
		throw new Exception("m_pWindow is not initialized in Engine::window(void)", "NullPointerException");
	}

	return m_pWindow;
}

void Hikari::Engine::window(Hikari::Window* window)
{
	if(window == NULL)
	{
		throw new Exception("Can't set new window to a NULL pointer in Engine::window(Window*)", "NullPointerException");
	}

	WinAPIWindow* newWindow = dynamic_cast<WinAPIWindow*>(window);

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

Hikari::WinAPIInput* Hikari::Engine::input(void)
{
	if(m_pInput == NULL)
	{
		throw new Exception("m_pInput is not initialized in Engine::input(void)", "NullPointerException");
	}

	return m_pInput;
}

void Hikari::Engine::input(Hikari::WinAPIInput* input)
{
	if(input == NULL)
	{
		throw new Exception("Can't set new input handler to a NULL pointer in Engine::input(WinAPIInput*)", "NullPointerException");
	}

	m_pInput = input;
}
