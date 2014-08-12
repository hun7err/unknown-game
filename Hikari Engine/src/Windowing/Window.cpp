#include "../../include/Windowing/Window.hpp"
#include "../../include/Windowing/WinAPIWindowParameters.hpp"
// komponenty
#include "../../include/Core/Components/Position.hpp"
#include "../../include/Core/Components/Size.hpp"
#include "../../include/Core/Components/String.hpp"
#include "../../include/Core/Components/Bool.hpp"

Hikari::Entities::Window::Window( const char* title, unsigned int width, unsigned int height, unsigned int posX, unsigned int posY ) : Entity("Window")
{
	Components::Position *pPositionComponent = new Components::Position((float)posX, (float)posY);
	Components::Size *pSizeComponent = new Components::Size((float)width, (float)height);
	Components::String *pTitleComponent = new Components::String("Title", title);
	Components::Bool *pFullscreenComponent = new Components::Bool("IsFullscreen", false);	// zastanowiæ siê, czy na pewno potrzebne; fullscreen i tak jest robiony (chyba) od strony DirectXa
	Components::WinAPIWindowParameters *pWindowParameters = new Components::WinAPIWindowParameters();

	AddComponent(pPositionComponent);
	AddComponent(pSizeComponent);
	AddComponent(pTitleComponent);
	AddComponent(pFullscreenComponent);
	AddComponent(pWindowParameters);
}

void Hikari::Entities::Window::Create( void )
{
	Component *pWindowParametersComponent = GetComponent("WinAPIWindowParameters"),
				*pTitleComponent = GetComponent("Title"),
				*pSizeComponent = GetComponent("Size"),
				*pPositionComponent = GetComponent("Position"),
				*pFullscreenComponent = GetComponent("IsFullscreen");

	Components::WinAPIWindowParameters *pWindowParameters = (Components::WinAPIWindowParameters*)(pWindowParametersComponent);
	Components::String *pTitle = (Components::String*)(pTitleComponent);
	Components::Size *pSize = (Components::Size*)(pSizeComponent);
	Components::Position *pPosition = (Components::Position*)(pPositionComponent);
	Components::Bool *pIsFullscreen = (Components::Bool*)(pFullscreenComponent);


	WNDCLASSEX WindowClassEx;

	ZeroMemory(&WindowClassEx, sizeof(WNDCLASSEX));		// czyœcimy pamiêæ w miejscu struktury

	WindowClassEx.cbSize = sizeof(WNDCLASSEX);			// rozmiar struktury w bajtach
	WindowClassEx.style = CS_HREDRAW | CS_VREDRAW;		// styl/style okna
	WindowClassEx.lpfnWndProc = pWindowParameters->GetWndProcFunctionPtr();			// wskaŸnik do procedury obs³ugi okna
	WindowClassEx.hInstance = pWindowParameters->GetInstanceHandle();					// uchwyt aplikacji wykorzystuj¹cej okno
	WindowClassEx.hCursor = LoadCursor(nullptr, IDC_ARROW);	// uchwyt kursora
	WindowClassEx.hbrBackground = (HBRUSH)COLOR_WINDOW;	// uchwyt do brusha(pêdzla?) t³a
	WindowClassEx.lpszClassName = "HikariWindowClass";	// nazwa klasy okna

	RegisterClassEx(&WindowClassEx);

	RECT wr = {0, 0, (int)pSize->GetValue().GetX(), (int)pSize->GetValue().GetY()};
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	HWND WindowHandle;

	WindowHandle = CreateWindowEx(0,					/** Rozszerzony styl okna  */
									"HikariWindowClass",					/** Nazwa klasy okna  */
									pTitle->GetValue().c_str(),						/** Nag³ówek okna  */
									WS_OVERLAPPEDWINDOW,					/** Styl okna  */
									(int)pPosition->GetValue().GetX(),			/** Wspó³rzêdna X okna  */
									(int)pPosition->GetValue().GetY(),			/** Wspó³rzêdna Y okna  */
									(int)pSize->GetValue().GetX(),				/** Szerokoœæ okna  */
									(int)pSize->GetValue().GetY(),				/** Wysokoœæ okna  */
									NULL,									/** Uchwyt okna-rodzica (parent window)  */
									NULL,									/** Uchwyt menu  */
									pWindowParameters->GetInstanceHandle(),	/** Uchwyt aplikacji  */
									NULL									/** WskaŸnik do wartoœci przekazanej do okna przez CREATESTRUCT  */);

	pWindowParameters->SetWindowHandle( WindowHandle );
	
	if(pIsFullscreen->GetValue() == true)
	{
		SetFullscreenProper( pWindowParameters->GetWindowHandle(), pIsFullscreen->GetValue(), pWindowParameters->GetVisibility(), pSize->GetValue().GetX(), pSize->GetValue().GetY(), pPosition->GetValue().GetX(), pPosition->GetValue().GetY() );
	}

	SetForegroundWindow( WindowHandle );
	SetFocus( WindowHandle );
	
	ShowWindow( WindowHandle, pWindowParameters->GetVisibility() );
	//ShowCursor(false);
}

void Hikari::Entities::Window::SetFullscreen( bool fullscreen )
{
	Component *pWindowParametersComponent = GetComponent("WinAPIWindowParameters"),
				*pSizeComponent = GetComponent("Size"),
				*pPositionComponent = GetComponent("Position");
	Components::WinAPIWindowParameters *pWindowParameters = (Components::WinAPIWindowParameters*)(pWindowParametersComponent);
	Components::Size *pSize = (Components::Size*)(pSizeComponent);
	Components::Position *pPosition = (Components::Position*)(pPositionComponent);
	
	SetFullscreenProper( pWindowParameters->GetWindowHandle(), fullscreen, pWindowParameters->GetVisibility(), pSize->GetValue().GetX(), pSize->GetValue().GetY(), pPosition->GetValue().GetX(), pPosition->GetValue().GetY() );
}

// daæ mo¿liwoœæ wyboru w SetFullscreenProper miêdzy natywn¹ rozdzielczoœci¹ (GetSystemMetrics() ) a podan¹ przez usera

void Hikari::Entities::Window::SetFullscreenProper( HWND WindowHandle, bool Fullscreen, int nCmdShow, float Width, float Height, float x, float y )
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

void Hikari::Entities::Window::ChangeVisibility( int nCmdShow )
{
	Component *pWindowParametersComponent = GetComponent("WinAPIWindowParameters");
	Components::WinAPIWindowParameters *pWindowParameters = (Components::WinAPIWindowParameters*)(pWindowParametersComponent);
	
	ShowWindow( pWindowParameters->GetWindowHandle(), nCmdShow );
	pWindowParameters->SetVisibility( nCmdShow );
}

Hikari::Entities::Window::~Window()
{
	ShowCursor(true);
	Component *pFullscreenComponent = GetComponent("IsFullscreen"),
				*pWindowParametersComponent = GetComponent("WinAPIWindowParameters");

	Components::Bool *pIsFullscreen = (Components::Bool*)(pFullscreenComponent);
	if(pIsFullscreen->GetValue() == true)
	{
		ChangeDisplaySettings(nullptr, 0);
	}

	Components::WinAPIWindowParameters *pWindowParameters = (Components::WinAPIWindowParameters*)(pWindowParametersComponent);

	DestroyWindow(pWindowParameters->GetWindowHandle());

	UnregisterClass("HikariWindowClass", pWindowParameters->GetInstanceHandle());
}
