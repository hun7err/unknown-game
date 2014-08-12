#include "../../../include/Core/Engine/Engine.hpp"
#include "../../../include/Helpers/Exception.hpp"
#include "../../../include/Core/Rendering/SimpleRenderer.hpp"
#include "../../../include/Core/Managers/Managers.hpp"
#include "../../../include/Core/Engine/EventHandlers/KeyPressHandler.hpp"

#include <windowsx.h>
#include <IL/il.h>

bool Hikari::Engine::m_Running = false;
HINSTANCE Hikari::Engine::m_hInstance;
HWND Hikari::Engine::m_hwnd;
int Hikari::Engine::m_nCmdShow;
Hikari::IO::WinAPIInput *Hikari::Engine::m_pInput = nullptr;
Hikari::WinAPIWindow *Hikari::Engine::m_pWindow = nullptr;
Hikari::Renderer *Hikari::Engine::m_pRenderer = nullptr;
Hikari::D3D11System *Hikari::Engine::m_pD3DSystem = nullptr;
std::mutex Hikari::Engine::inputMutex;
std::mutex Hikari::Engine::runningMutex;
std::mutex Hikari::Engine::d3dsystemMutex;
Hikari::Engine *Hikari::Engine::m_pInstance = nullptr;
Hikari::Camera *Hikari::Engine::m_pCamera = nullptr;
Hikari::EventHandlerManager *Hikari::Engine::m_pEventHandlerManager = nullptr;
	
const char Hikari::Engine::buildDate[] = __DATE__;
const char Hikari::Engine::buildTime[] = __TIME__;

Hikari::Engine::Engine(void)
{
	m_pInstance = this;
	m_pRenderer = nullptr;
	m_pD3DSystem = nullptr;
	m_pInput = nullptr;
	m_Running = false;
}

Hikari::Engine::Engine(const Hikari::Engine& rOther)
{
}

Hikari::Engine::~Engine()
{
}

void Hikari::Engine::initialize(HINSTANCE hApplicationInstance, int nCmdShow)
{
	ilInit();

	m_hInstance = hApplicationInstance;
	m_nCmdShow = nCmdShow;

	m_pEventHandlerManager = new Hikari::EventHandlerManager();

	inputMutex.lock();
	m_pInput = new Hikari::IO::WinAPIInput();
	inputMutex.unlock();

	d3dsystemMutex.lock();
	m_pD3DSystem = new Hikari::D3D11System();
	d3dsystemMutex.unlock();

	m_pInput->setup();
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

void Hikari::Engine::run(void)
{
	/*if(m_pCamera == nullptr)
	{
		throw Exception("Camera is not set in Hikari::Engine::run(void)", "NullPointerException");
	}*/

	Vector2D windowSize = m_pWindow->size();

	m_pRenderer->setup(m_pWindow->width(), m_pWindow->height());

	MSG eventMessage;
	ZeroMemory(&eventMessage, sizeof(MSG));

	runningMutex.lock();
	m_Running = true;
	runningMutex.unlock();

	while(true)
	{
		if(PeekMessage(&eventMessage, nullptr, 0, 0, PM_REMOVE))
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

		m_pCamera->tick();

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

	// podepnij bufory obiektów itp.
	m_pRenderer->render();
}

void Hikari::Engine::cleanup(void)
{
	// mutex
	m_pRenderer->cleanup();
	delete m_pRenderer;
	m_pRenderer = nullptr;

	m_pD3DSystem->cleanup();

	delete m_pInput;
	m_pInput = nullptr;

	Hikari::ObjectManager::cleanup();	// nie dzia³a ;_;
	// chodzi o to, ¿eby w mened¿erze (np. tekstur) zwalniaæ tekstury ³adowane dynamicznie przez TextureManager::load (to samo z obiektami dynamicznie za³adowanymi)

	delete m_pEventHandlerManager;
	m_pEventHandlerManager = nullptr;

	//Hikari::EngineHandle = nullptr;
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

			Hikari::EventHandlers::KeyPressHandler* pEventHandler = nullptr;

			std::vector<Hikari::EventHandler*>* pEventHandlers = m_pEventHandlerManager->eventHandlers(Hikari::Event::KeyPress);
			for(std::vector<Hikari::EventHandler*>::iterator currentHandler = pEventHandlers->begin(); currentHandler != pEventHandlers->end(); ++currentHandler)
			{
				if(*currentHandler == nullptr)
					continue;

				pEventHandler = dynamic_cast<Hikari::EventHandlers::KeyPressHandler*>(*currentHandler);

				if(pEventHandler != nullptr)
				{
					pEventHandler->keyCode((int)wParam);
					pEventHandler->process();
				}
			}

			return 0;
		}
		case WM_KEYUP:
		{
			m_pInput->keyUp((unsigned int)wParam);

			Hikari::EventHandlers::KeyPressHandler* pEventHandler = nullptr;

			std::vector<Hikari::EventHandler*>* pEventHandlers = m_pEventHandlerManager->eventHandlers(Hikari::Event::KeyRelease);
			for(std::vector<Hikari::EventHandler*>::iterator currentHandler = pEventHandlers->begin(); currentHandler != pEventHandlers->end(); ++currentHandler)
			{
				if(*currentHandler == nullptr)
					continue;

				pEventHandler = dynamic_cast<Hikari::EventHandlers::KeyPressHandler*>(*currentHandler);

				if(pEventHandler != nullptr)
				{
					pEventHandler->keyCode((int)wParam);
					pEventHandler->process();
				}
			}

			return 0;
		}
		case WM_MOUSEMOVE:
		{
			Hikari::EventHandlers::MouseMoveHandler* pEventHandler = nullptr;

			std::vector<Hikari::EventHandler*>* pEventHandlers = m_pEventHandlerManager->eventHandlers(Hikari::Event::KeyRelease);
			for(std::vector<Hikari::EventHandler*>::iterator currentHandler = pEventHandlers->begin(); currentHandler != pEventHandlers->end(); ++currentHandler)
			{
				if(*currentHandler == nullptr)
					continue;

				pEventHandler = dynamic_cast<Hikari::EventHandlers::MouseMoveHandler*>(*currentHandler);

				if(pEventHandler != nullptr)
				{
					int x = GET_X_LPARAM(lParam),
						y = GET_Y_LPARAM(lParam);
					pEventHandler->cursorPosition(x, y);
					pEventHandler->process();
				}
			}

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
	if(m_pWindow == nullptr)
	{
		throw Exception("m_pWindow is not initialized in Engine::window(void)", "NullPointerException");
	}

	return m_pWindow;
}

void Hikari::Engine::window(Hikari::Window* pWindow, unsigned int sampleCount)
{
	if(pWindow == nullptr)
	{
		throw Exception("Can't set new window to a nullptr pointer in Engine::window(Window*)", "NullPointerException");
	}

	WinAPIWindow* newWindow = dynamic_cast<WinAPIWindow*>(pWindow);

	if(newWindow == nullptr)
	{
		throw Exception("Can't dynamically cast window parameter to WinAPIWindow in Engine::window(Window*,uint)", "InvalidTypeException");
	}

	m_pWindow = newWindow;
	m_pWindow->setup(m_hInstance, m_nCmdShow);
	m_pD3DSystem->setup(m_pWindow->handle(), m_pWindow->fullscreen(), m_pWindow->width(), m_pWindow->height(), sampleCount);
}

Hikari::Renderer* Hikari::Engine::renderer(void)
{
	#ifdef _DEBUG
	if(m_pRenderer == nullptr)
	{
		throw Exception("m_pRenderer is not initialized in Engine::renderer(void)", "NullPointerException");
	}
	#endif

	return m_pRenderer;
}

void Hikari::Engine::renderer(Hikari::Renderer* pRenderer)
{
	#ifdef _DEBUG
	if(pRenderer == nullptr)
	{
		throw Exception("Can't set new renderer to nullptr in Engine::renderer(Renderer*)", "NullPointerException");
	}
	#endif

	if(m_pRenderer != nullptr)
	{
		delete m_pRenderer;
	}

	m_pRenderer = pRenderer;
}

Hikari::Camera* Hikari::Engine::camera(void)
{
	#ifdef _DEBUG
	if(m_pCamera == nullptr)
	{
		throw Exception("m_pCamera is not initialized in Engine::camera(void)", "NullPointerException");
	}
	#endif

	return m_pCamera;
}

void Hikari::Engine::camera(Hikari::Camera* pNewCamera)
{
	#ifdef _DEBUG
	if(pNewCamera == nullptr)
	{
		throw Exception("Can't set m_pCamera to nullptr in Hikari::Engine::camera(Camera*)", "NullPointerException");
	}
	#endif

	if(m_pCamera != nullptr)
	{
		m_pCamera->disableBindigs();
	}
	m_pCamera = pNewCamera;
	m_pCamera->setBindings();
}

Hikari::EventHandlerManager* Hikari::Engine::eventHandlers(void)
{
	return m_pEventHandlerManager;
}

Hikari::IO::WinAPIInput* Hikari::Engine::input(void)
{
	#ifdef _DEBUG
	if(m_pInput == nullptr)
	{
		throw Exception("m_pInput is not initialized in Engine::input(void)", "NullPointerException");
	}
	#endif

	return m_pInput;
}

void Hikari::Engine::input(Hikari::IO::WinAPIInput* pInput)
{
	#ifdef _DEBUG
	if(pInput == nullptr)
	{
		throw Exception("Can't set new input handler to a nullptr pointer in Engine::input(WinAPIInput*)", "NullPointerException");
	}
	#endif

	m_pInput = pInput;
}

Hikari::D3D11System *Hikari::Engine::d3dsystem(void)
{
	return m_pD3DSystem;
}
