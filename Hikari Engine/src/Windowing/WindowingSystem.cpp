#include "../../include/Windowing/WindowingSystem.hpp"
#include "../../include/Windowing/WinAPIWindowParameters.hpp"

#include "../../include/Core/Messaging/Messages/KeyMessage.hpp"
#include "../../include/Core/Messaging/Events/KeyEvent.hpp"
#include "../../include/Core/Messaging/Events/MouseEvent.hpp"

#include <windowsx.h>

Hikari::WindowingSystem *Hikari::WindowingSystem::m_pInstance = nullptr;

Hikari::WindowingSystem::WindowingSystem( void )
{
	m_pInstance = this;
}

Hikari::WindowingSystem::~WindowingSystem()
{
	delete m_pMainWindow;
	delete m_pMessenger;
	delete m_pListener;
}

void Hikari::WindowingSystem::Init( Hikari::Engine *pEngine )
{
	m_pEngine = pEngine;
	m_pMainWindow = new Entities::Window("Hikari::Engine test application", 800, 600, 200, 200);
	Components::WinAPIWindowParameters *pWindowParameters = (Components::WinAPIWindowParameters*)(m_pMainWindow->GetComponent("WinAPIWindowParameters"));
	
	pWindowParameters->SetWndProcFunctionPtr( WndProc );
	pWindowParameters->SetInstanceHandle( m_pEngine->GetInstanceHandle() );
	pWindowParameters->SetVisibility( m_pEngine->GetVisibility() );

	m_pMainWindow->Create();

	const short int postedEvents[] = {
										Hikari::Events::KeyEvent::Press,
										Hikari::Events::KeyEvent::Release,
										Hikari::Events::MouseEvent::Move
									};
	m_pMessenger = new Hikari::Messenger(postedEvents);

	m_pListener = new Hikari::Listener();
	std::function<void(Message*)> keyPressCallback = std::bind(&WindowingSystem::SystemKeyPressHandler, this, std::placeholders::_1);
	m_pListener->Subscribe(m_pMessenger, Hikari::Events::KeyEvent::Press, keyPressCallback);
}

Hikari::Messenger* Hikari::WindowingSystem::GetMessenger( void )
{
	return m_pMessenger;
}

void Hikari::WindowingSystem::Update( float dt )
{
	static MSG eventMessage;
	ZeroMemory(&eventMessage, sizeof(MSG));

	if(PeekMessage(&eventMessage, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&eventMessage);
		DispatchMessage(&eventMessage);	// wywo³uje WndProc z tego co pamiêtam
	}

	if(eventMessage.message == WM_QUIT)
	{
		m_pEngine->Stop();
	}
}

LRESULT CALLBACK Hikari::WindowingSystem::WndProc( HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam )
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
			return m_pInstance->HandleInput( WindowHandle, message, wParam, lParam );
		}
	}
}

LRESULT CALLBACK Hikari::WindowingSystem::HandleInput( HWND WindowHandle, UINT message, WPARAM wParam, LPARAM lParam )
{
	switch(message)
	{
		case WM_KEYDOWN:
		{
			unsigned int key = (unsigned int)wParam;

			Messages::KeyPressMessage *pKeyMessage = new Messages::KeyPressMessage(key);
			m_pMessenger->Notify(pKeyMessage);
		}
		case WM_KEYUP:
		{
			unsigned int key = (unsigned int)wParam;

			Messages::KeyReleaseMessage *pKeyMessage = new Messages::KeyReleaseMessage(key);
			m_pMessenger->Notify(pKeyMessage);
		}
		case WM_MOUSEMOVE:
		{
			int	x = GET_X_LPARAM(lParam),
				y = GET_Y_LPARAM(lParam);

			// powiadom
		}
		default:
		{
			return DefWindowProc( WindowHandle, message, wParam, lParam );
		}
	}
}

void Hikari::WindowingSystem::SystemKeyPressHandler(Hikari::Message *pMessage)
{
	Hikari::Messages::KeyPressMessage *pKeyPressMessage = (Hikari::Messages::KeyPressMessage*)pMessage;

	if(pKeyPressMessage->GetKeyCode() == VK_ESCAPE)
	{
		m_pEngine->Stop();
	}
}
