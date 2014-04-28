#include "Engine.h"
#include "Exception.h"

Hikari::Engine::Engine()
{
	m_Input = m_Window = m_Renderer = NULL;
}

Hikari::Engine::Engine(const Engine& engine)
{
}

Hikari::Engine::~Engine()
{
}

Hikari::Engine& Hikari::Engine::Setup()
{
	int screenWidth, screenHeight;

	screenWidth = screenHeight = 0;

	InitializeWindows(screenWidth, screenHeight);

	m_Input = new WinAPIInput();
	if(!m_Input)
	{
		throw new Exception("Could not initialize WinAPI input", "EngineInitializationException");
	}

	m_Input->Setup();

	m_Window = new WinAPIWindow("tutaj przekazac title z Engine, dodac setter do tytulu");

	if(!m_Window)
	{
		throw new Exception("Could not create WinAPI window", "WindowCreationException");
	}

	m_Window->Setup(m_hwnd);

	return *this;
}

void Hikari::Engine::Shutdown()
{
	if(m_Window)
	{
		m_Window->Shutdown();
		delete m_Window;
		m_Window = NULL;
	}

	if(m_Input)
	{
		delete m_Input;
		m_Input = 0;
	}

	ShutdownWindows();
}

void Hikari::Engine::Run()
{
	MSG msg;
	bool done, result;

	ZeroMemory(&msg, sizeof(MSG));

	done = false;

	while(!done)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if(msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			result = Frame();

			if(!result)
			{
				done = true;
			}
		}
	}
}

bool Hikari::Engine::Frame()
{
	bool result;

	if(m_Input->IsKeyDown(VK_ESCAPE))
	{
		return false;
	}

	//result = m_Graphics->Frame(); // zamieniæ na Renderer->render();
	result = m_Renderer->render();

	if(!result)
	{
		return false;
	}

	return true;
}

LRESULT CALLBACK Hikari::Engine::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch(umsg)
	{
		case WM_KEYDOWN:
		{
			m_Input->KeyDown((unsigned int)wparam);
			return 0;
		}

		case WM_KEYUP:
		{
			m_Input->KeyUp((unsigned int)wparam);
			return 0;
		}

		default:
		{
			return DefWindowProc(hwnd, umsg, wparam, lparam);
		}
	}
}

Hikari::Engine& Hikari::Engine::setWindowTitle(const char *title)
{
	m_Window->setTitle(title);
}

Hikari::Engine& Hikari::Engine::setWindowSize(unsigned int width, unsigned int height)
{
	m_Window->setSize(width, height);
}

// InitializeWindows
