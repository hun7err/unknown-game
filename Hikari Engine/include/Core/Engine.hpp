#ifndef __ENGINEHPP__
#define __ENGINEHPP__

#include "../Helpers/ECS/System.hpp"
#include <vector>
#include <string>
#include <Windows.h>

/*
	doczyta�:
		www.randygaul.net/2013/05/20/component-based-engine-design/

	to-do:
	
	- akcje + bindowanie dzi�ki akcjom przycisk�w do callback�w ( function<void(Message*)> ), wychodzenie na ESC i poruszanie mysz� (to do kamery w sumie, ale co tam)

	- wyb�r systemu z silnika po nazwie
	- inicjalizacja DX11, czyszczenie okna kolorem itp.
	- modele (m.in. Sponza, s� w Downloads/ na PC)
	- porz�dna hierarchia katalog�w - zacz�tek jest, teraz rozbudowa� i powrzuca� pliki (+ w src zrobi�)

	- jaki� �adny system budowania shader�w
	- informacje o GPU, monitorach, rozdzielczo�ciach itp. -> jakie� Entity zarz�dzaj�ce tym, pobieranie listy rozdzielczo�ci nieposortowanej i posortowanej
	- paper o voxel cone tracing
	- deep g-buffer radiosity (PC pulpit)
*/

namespace Hikari
{
	class Engine
	{
		public:
			Engine();

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

		private:
			void InitializeSystems( void );

			std::vector<System*> m_Systems;
			bool m_Running;
			HINSTANCE m_InstanceHandle;
			int m_nCmdShow;
			LPSTR m_lpCmdLine;
	};
}

#endif