#include "../../include/Windowing/WinAPIWindowParameters.hpp"

Hikari::Components::WinAPIWindowParameters::WinAPIWindowParameters( void ) : Component("WinAPIWindowParameters")
{
}

HWND Hikari::Components::WinAPIWindowParameters::GetWindowHandle( void ) const
{
	return m_WindowHandle;
}

void Hikari::Components::WinAPIWindowParameters::SetWindowHandle( HWND WindowHandle )
{
	m_WindowHandle = WindowHandle;
}

HINSTANCE Hikari::Components::WinAPIWindowParameters::GetInstanceHandle( void ) const
{
	return m_InstanceHandle;
}

void Hikari::Components::WinAPIWindowParameters::SetInstanceHandle( HINSTANCE InstanceHandle )
{
	m_InstanceHandle = InstanceHandle;
}

WNDCLASSEX Hikari::Components::WinAPIWindowParameters::GetWindowClassEx( void ) const
{
	return m_WindowClassEx;
}

void Hikari::Components::WinAPIWindowParameters::SetWindowClassEx( WNDCLASSEX WindowClassEx )
{
	m_WindowClassEx = WindowClassEx;
}

WNDPROC Hikari::Components::WinAPIWindowParameters::GetWndProcFunctionPtr( void ) const
{
	return m_lpfnWndProc;
}

void Hikari::Components::WinAPIWindowParameters::SetWndProcFunctionPtr( WNDPROC lpfnWndProc )
{
	m_lpfnWndProc = lpfnWndProc;
}

int Hikari::Components::WinAPIWindowParameters::GetVisibility( void ) const
{
	return m_Visibility;
}

void Hikari::Components::WinAPIWindowParameters::SetVisibility( int visibility )
{
	m_Visibility = visibility;
}
