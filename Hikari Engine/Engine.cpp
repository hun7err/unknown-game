#include "Engine.h"
#include "Exception.h"

Hikari::Engine::Engine()
{
	m_Input = m_Graphics = NULL;
}

Hikari::Engine::Engine(const Engine& engine)
{
}

Hikari::Engine::~Engine()
{
}

void Hikari::Engine::Setup()
{
	int screenWidth, screenHeight;

	screenWidth = screenHeight = 0;

	InitializeWindows(screenWidth, screenHeight);

	m_Input = new WinAPIInput;
	if(!m_Input)
	{
		throw new Exception("Could not initialize WinAPI input", "EngineInitializationException");
	}

	m_Graphics->Initialize(screenWidth, screenHeight, m_hwnd);
}

void Hikari::Engine::Shutdown()
{
	if(m_Graphics)
	{
		m_Graphics->Shutdown();
		delete m_Graphics;
		m_Graphics = NULL;
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

	result = m_Graphics->Frame(); // zamieniæ na Renderer->render();
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

// InitializeWindows
