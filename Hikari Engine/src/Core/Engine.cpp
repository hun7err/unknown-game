#include "../../include/Core/Engine.hpp"
#include <winbase.h>

Hikari::Engine::Engine() : m_Running(true)
{
}

void Hikari::Engine::Update( float dt )
{
	for(auto currentSystem = m_Systems.begin(); currentSystem != m_Systems.end(); ++currentSystem)
	{
		(*currentSystem)->Update( dt );
	}
}

void Hikari::Engine::InitializeSystems( void )
{
	for(auto currentSystem = m_Systems.begin(); currentSystem != m_Systems.end(); ++currentSystem)
	{
		(*currentSystem)->Init( this );
	}
}

void Hikari::Engine::MainLoop( void )
{
	InitializeSystems();

	const float fps = 60;	// celujemy w 60fps wstêpnie
	const float dt = 1 / fps;
	float accumulator = 0;

	float updateTime = (float)GetCurrentTime();

	// http://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-the-core-engine--gamedev-7493#timestepping
	do
	{
		const float currentTime = (float)GetCurrentTime();

		accumulator += currentTime - updateTime;

		updateTime = currentTime;

		if(accumulator > 0.2f)	// unikaj spirali œmierci
			accumulator = 0.2f;

		while(accumulator > dt)	// czy to w ogóle jest dobrze?
		{
			Update(dt);
			accumulator -= dt;
		}
		// pêtla g³ówna: timestepping itp.
	} while (m_Running);
}

void Hikari::Engine::Stop( void )
{
	m_Running = false;
}

void Hikari::Engine::Add( Hikari::System *pSystem )
{
	m_Systems.push_back(pSystem);
}

void Hikari::Engine::SetInstanceHandle( HINSTANCE InstanceHandle )
{
	m_InstanceHandle = InstanceHandle;
}

void Hikari::Engine::SetVisibility( int nCmdShow )
{
	m_nCmdShow = nCmdShow;
}

void Hikari::Engine::SetCommandLineArguments( LPSTR lpCmdLine )
{
	m_lpCmdLine = lpCmdLine;
}

void Hikari::Engine::Initialize( HINSTANCE InstanceHandle, int nCmdShow, LPSTR lpCmdLine )
{
	SetInstanceHandle( InstanceHandle );
	SetVisibility( nCmdShow );
	SetCommandLineArguments( lpCmdLine );
}

HINSTANCE Hikari::Engine::GetInstanceHandle( void ) const
{
	return m_InstanceHandle;
}

int Hikari::Engine::GetVisibility( void ) const
{
	return m_nCmdShow;
}

LPSTR Hikari::Engine::GetCommandLineArguments( void ) const
{
	return m_lpCmdLine;
}
