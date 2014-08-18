#include "../../include/Windowing/Window.hpp"
//#include "../../include/Windowing/WinAPIWindowParameters.hpp"
// komponenty
//#include "../../include/Core/Components/Position.hpp"
//#include "../../include/Core/Components/Size.hpp"
//#include "../../include/Core/Components/String.hpp"
//#include "../../include/Core/Components/Bool.hpp"

Hikari::Window::Window( const char* title, unsigned int width, unsigned int height, unsigned int posX, unsigned int posY ) : m_Size( (float)width, (float)height ), m_Position( (float)posX, (float)posY ), m_Title( title ), m_Fullscreen(false)
{
	m_pWindowParameters = new WinAPIWindowParameters();
}

Hikari::Window::~Window()
{
	ShowCursor(true);

	if(m_Fullscreen == true)
	{
		ChangeDisplaySettings(nullptr, 0);
	}

	DestroyWindow(m_pWindowParameters->GetWindowHandle());

	UnregisterClass("HikariWindowClass", m_pWindowParameters->GetInstanceHandle());

	delete m_pWindowParameters;
}

void Hikari::Window::Create( void )
{
	WNDCLASSEX WindowClassEx;

	ZeroMemory(&WindowClassEx, sizeof(WNDCLASSEX));		// czyœcimy pamiêæ w miejscu struktury

	WindowClassEx.cbSize = sizeof(WNDCLASSEX);			// rozmiar struktury w bajtach
	WindowClassEx.style = CS_HREDRAW | CS_VREDRAW;		// styl/style okna
	WindowClassEx.lpfnWndProc = m_pWindowParameters->GetWndProcFunctionPtr();			// wskaŸnik do procedury obs³ugi okna
	WindowClassEx.hInstance = m_pWindowParameters->GetInstanceHandle();					// uchwyt aplikacji wykorzystuj¹cej okno
	WindowClassEx.hCursor = LoadCursor(nullptr, IDC_ARROW);	// uchwyt kursora
	WindowClassEx.hbrBackground = (HBRUSH)COLOR_WINDOW;	// uchwyt do brusha(pêdzla?) t³a
	WindowClassEx.lpszClassName = "HikariWindowClass";	// nazwa klasy okna

	RegisterClassEx(&WindowClassEx);

	RECT wr = {0, 0, (int)m_Size.GetX(), (int)m_Size.GetY()};
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	HWND WindowHandle;

	WindowHandle = CreateWindowEx(0,					/** Rozszerzony styl okna  */
									"HikariWindowClass",					/** Nazwa klasy okna  */
									m_Title.c_str(),						/** Nag³ówek okna  */
									WS_OVERLAPPEDWINDOW,					/** Styl okna  */
									(int)m_Position.GetX(),			/** Wspó³rzêdna X okna  */
									(int)m_Position.GetY(),			/** Wspó³rzêdna Y okna  */
									(int)m_Size.GetX(),				/** Szerokoœæ okna  */
									(int)m_Size.GetY(),				/** Wysokoœæ okna  */
									NULL,									/** Uchwyt okna-rodzica (parent window)  */
									NULL,									/** Uchwyt menu  */
									m_pWindowParameters->GetInstanceHandle(),	/** Uchwyt aplikacji  */
									NULL									/** WskaŸnik do wartoœci przekazanej do okna przez CREATESTRUCT  */);

	m_pWindowParameters->SetWindowHandle( WindowHandle );
	
	if(m_Fullscreen == true)
	{
		SetFullscreenProper( m_pWindowParameters->GetWindowHandle(), m_Fullscreen, m_pWindowParameters->GetVisibility(), m_Size.GetX(), m_Size.GetY(), m_Position.GetX(), m_Position.GetY() );
	}

	SetForegroundWindow( WindowHandle );
	SetFocus( WindowHandle );
	
	ShowWindow( WindowHandle, m_pWindowParameters->GetVisibility() );
	//ShowCursor(false);
}

void Hikari::Window::SetFullscreen( bool fullscreen )
{
	SetFullscreenProper( m_pWindowParameters->GetWindowHandle(), fullscreen, m_pWindowParameters->GetVisibility(), m_Size.GetX(), m_Size.GetY(), m_Position.GetX(), m_Position.GetY() );
}

// daæ mo¿liwoœæ wyboru w SetFullscreenProper miêdzy natywn¹ rozdzielczoœci¹ (GetSystemMetrics() ) a podan¹ przez usera

void Hikari::Window::SetFullscreenProper( HWND WindowHandle, bool Fullscreen, int nCmdShow, float Width, float Height, float x, float y )
{
	DEVMODE dmScreenSettings;
	
	if(Fullscreen == true)
	{
		int screenWidth = GetSystemMetrics(SM_CXSCREEN),
			screenHeight = GetSystemMetrics(SM_CYSCREEN);

		ZeroMemory( &dmScreenSettings, sizeof(DEVMODE) );
		dmScreenSettings.dmSize = sizeof( dmScreenSettings );
		dmScreenSettings.dmPelsWidth = (unsigned long)screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings( &dmScreenSettings, CDS_FULLSCREEN );

		SetWindowPos( WindowHandle, nullptr, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );
	}
	else
	{
		ZeroMemory( &dmScreenSettings, sizeof(DEVMODE) );
		dmScreenSettings.dmSize = sizeof( dmScreenSettings );
		dmScreenSettings.dmPelsWidth = (unsigned long)Width;
		dmScreenSettings.dmPelsHeight = (unsigned long)Height;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		SetWindowPos( WindowHandle, nullptr, (int)x, (int)y, 0, 0, 0);

		ChangeDisplaySettings( &dmScreenSettings, 0 );
	}

	ShowWindow( WindowHandle, nCmdShow );
}

void Hikari::Window::ChangeVisibility( int nCmdShow )
{
	ShowWindow( m_pWindowParameters->GetWindowHandle(), nCmdShow );
	m_pWindowParameters->SetVisibility( nCmdShow );
}

bool Hikari::Window::IsFullscreen( void ) const
{
	return m_Fullscreen;
}

const Hikari::Vector2D& Hikari::Window::GetPosition( void ) const
{
	return m_Position;
}

void Hikari::Window::SetPosition( const Vector2D& newPosition )
{
	m_Position = newPosition;
}

const Hikari::Vector2D& Hikari::Window::GetSize( void ) const
{
	return m_Size;
}

void Hikari::Window::Resize( const Vector2D& newSize )
{
	m_Size = newSize;
	// coœ zrobiæ, ¿eby zmieni³o rozmiar
}

Hikari::WinAPIWindowParameters* Hikari::Window::GetWinAPIWindowParameters( void )
{
	return m_pWindowParameters;
}
