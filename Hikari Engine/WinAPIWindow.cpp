#include "WinAPIWindow.hpp"
#include "Exception.hpp"
#include "Engine.hpp"

void Hikari::WinAPIWindow::setup(HINSTANCE hInstance	/** \brief	Uchwyt aplikacji korzystaj¹cej z okna */, int nCmdShow	/** \brief	Tryb wyœwietlania okna */)
{
	m_hInstance = hInstance;

	ZeroMemory(&m_WindowClassEx, sizeof(WNDCLASSEX));		// czyœcimy pamiêæ w miejscu struktury

	m_WindowClassEx.cbSize = sizeof(WNDCLASSEX);			// rozmiar struktury w bajtach
	m_WindowClassEx.style = CS_HREDRAW | CS_VREDRAW;		// styl/style okna
	m_WindowClassEx.lpfnWndProc = Hikari::WndProc;			// wskaŸnik do procedury obs³ugi okna
	m_WindowClassEx.hInstance = hInstance;					// uchwyt aplikacji wykorzystuj¹cej okno
	m_WindowClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);	// uchwyt kursora
	m_WindowClassEx.hbrBackground = (HBRUSH)COLOR_WINDOW;	// uchwyt do brusha(pêdzla?) t³a
	m_WindowClassEx.lpszClassName = "HikariWindowClass";	// nazwa klasy okna

	RegisterClassEx(&m_WindowClassEx);		// zarejestruj klasê okna w systemie

	//RECT wr = {0, 0, m_Width, m_Height};
	//AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	m_WindowHandle = CreateWindowEx(NULL,					/** \brief	Rozszerzony styl okna  */
									"HikariWindowClass",	/** \brief	Nazwa klasy okna  */
									m_Title.c_str(),		/** \brief	Nag³ówek okna  */
									WS_OVERLAPPEDWINDOW,	/** \brief	Styl okna  */
									m_PosX,					/** \brief	Wspó³rzêdna X okna  */
									m_PosY,					/** \brief	Wspó³rzêdna Y okna  */
									m_Width,				/** \brief	Szerokoœæ okna  */
									m_Height,				/** \brief	Wysokoœæ okna  */
									NULL,					/** \brief	Uchwyt okna-rodzica (parent window)  */
									NULL,					/** \brief	Uchwyt menu  */
									hInstance,				/** \brief	Uchwyt aplikacji  */
									NULL					/** \brief	WskaŸnik do wartoœci przekazanej do okna przez CREATESTRUCT  */);

	this->visibility(nCmdShow);
	
	SetForegroundWindow(m_WindowHandle);
	SetFocus(m_WindowHandle);
	//ShowCursor(false);
}

void Hikari::WinAPIWindow::cleanup(void)
{
	ShowCursor(true);

	if(Hikari::Window::m_Fullscreen)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	DestroyWindow(m_WindowHandle);
	m_WindowHandle = NULL;

	UnregisterClass("HikariWindowClass", m_hInstance);
	m_hInstance = NULL;
}

void Hikari::WinAPIWindow::visibility(int nCmdShow)
{
	ShowWindow(m_WindowHandle, nCmdShow);
	m_Visibility = nCmdShow;
}

int Hikari::WinAPIWindow::visibility(void)
{
	return m_Visibility;
}

HWND Hikari::WinAPIWindow::handle(void)
{
	return m_WindowHandle;
}

void Hikari::WinAPIWindow::handle(HWND hWnd)
{
	m_WindowHandle = hWnd;
}

void Hikari::WinAPIWindow::fullscreen(bool fullscreen)
{
	Hikari::Window::fullscreen(fullscreen);

	DEVMODE dmScreenSettings;
	
	if(fullscreen == true)
	{
		int screenWidth = GetSystemMetrics(SM_CXSCREEN),
			screenHeight = GetSystemMetrics(SM_CYSCREEN);

		ZeroMemory(&dmScreenSettings, sizeof(DEVMODE));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		SetWindowPos(m_WindowHandle, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	}
	else
	{
		ZeroMemory(&dmScreenSettings, sizeof(DEVMODE));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)m_Width;
		dmScreenSettings.dmPelsHeight = (unsigned long)m_Height;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		SetWindowPos(m_WindowHandle, NULL, m_PosX, m_PosY, 0, 0, 0);

		ChangeDisplaySettings(&dmScreenSettings, 0);
	}

	this->visibility(m_Visibility);
}

bool Hikari::WinAPIWindow::fullscreen(void)
{
	return Hikari::Window::fullscreen();
}
