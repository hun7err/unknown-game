#ifndef __ENGINEHPP__
#define __ENGINEHPP__

#include "../Helpers/ECS/System.hpp"
#include "World.hpp"
#include <vector>
#include <string>
#include <Windows.h>

/*
	doczyta�:
		www.randygaul.net/2013/05/20/component-based-engine-design/

	to-do:
	
	- akcje + bindowanie dzi�ki akcjom przycisk�w do callback�w ( function<void(Message*)> ), wychodzenie na ESC i poruszanie mysz� (to do kamery w sumie, ale co tam)

	!!!!!!!!!
	- renderer -> czyszczenie okna kolorem, render targets itp.
	- kamera -> entity z r�nymi komponentami w tym z listenerem na akcje z WindowingSystem (mousemove), sprawdzi� czy mousemove w og�le dzia�a
	- modele (m.in. Sponza, s� w Downloads/ na PC)
	!!!!!!!!!

	- jaki� �adny system budowania shader�w
	- informacje o GPU, monitorach, rozdzielczo�ciach itp. -> jakie� Entity zarz�dzaj�ce tym, pobieranie listy rozdzielczo�ci nieposortowanej i posortowanej
	- paper o voxel cone tracing -> Jen96 o cone tracingu + doczyta� od punktu 4. wzwy� [+ zrozumie� to co rozpisane na kartce z 3.]
	- deep g-buffer radiosity (PC pulpit)
*/

namespace Hikari
{
	class Engine
	{
		public:
			Engine( void );
			~Engine( void );

			void Update( float dt );
			void MainLoop( void );
			void Stop( void );
			void Add( System *pSystem );

			void Initialize( HINSTANCE InstanceHandle, int nCmdShow, LPSTR lpCmdLine );

			void SetInstanceHandle( HINSTANCE InstanceHandle );
			void SetVisibility( int nCmdShow );
			void SetCommandLineArguments( LPSTR lpCmdLine );

			HINSTANCE GetInstanceHandle( void ) const;
			int GetVisibility( void ) const;
			LPSTR GetCommandLineArguments( void ) const;

			System *GetSystem( const std::string& ID );

			World *GetWorld( void );

		private:
			World *m_pWorld;

			void InitializeSystems( void );

			std::vector<System*> m_Systems;
			bool m_Running;
			HINSTANCE m_InstanceHandle;
			int m_nCmdShow;
			LPSTR m_lpCmdLine;
	};
}

#endif