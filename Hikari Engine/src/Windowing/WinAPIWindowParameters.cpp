#include "../../include/Windowing/WinAPIWindowParameters.hpp"

Hikari::WinAPIWindowParameters::WinAPIWindowParameters( void )
{
}

HWND Hikari::WinAPIWindowParameters::GetWindowHandle( void ) const
{
	return m_WindowHandle;
}

void Hikari::WinAPIWindowParameters::SetWindowHandle( HWND WindowHandle )
{
	m_WindowHandle = WindowHandle;
}

HINSTANCE Hikari::WinAPIWindowParameters::GetInstanceHandle( void ) const
{
	return m_InstanceHandle;
}

void Hikari::WinAPIWindowParameters::SetInstanceHandle( HINSTANCE InstanceHandle )
{
	m_InstanceHandle = InstanceHandle;
}

WNDCLASSEX Hikari::WinAPIWindowParameters::GetWindowClassEx( void ) const
{
	return m_WindowClassEx;
}

void Hikari::WinAPIWindowParameters::SetWindowClassEx( WNDCLASSEX WindowClassEx )
{
	m_WindowClassEx = WindowClassEx;
}

WNDPROC Hikari::WinAPIWindowParameters::GetWndProcFunctionPtr( void ) const
{
	return m_lpfnWndProc;
}

void Hikari::WinAPIWindowParameters::SetWndProcFunctionPtr( WNDPROC lpfnWndProc )
{
	m_lpfnWndProc = lpfnWndProc;
}

int Hikari::WinAPIWindowParameters::GetVisibility( void ) const
{
	return m_Visibility;
}

void Hikari::WinAPIWindowParameters::SetVisibility( int visibility )
{
	m_Visibility = visibility;
}
