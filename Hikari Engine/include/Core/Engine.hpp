#ifndef __ENGINEHPP__
#define __ENGINEHPP__

#include "../Helpers/ECS/System.hpp"
#include <vector>
#include <string>
#include <Windows.h>

/*
	doczytaæ:
		www.randygaul.net/2013/05/20/component-based-engine-design/

	to-do:
	
	- akcje + bindowanie dziêki akcjom przycisków do callbacków ( function<void(Message*)> ), wychodzenie na ESC i poruszanie mysz¹ (to do kamery w sumie, ale co tam)

	- wybór systemu z silnika po nazwie
	- inicjalizacja DX11, czyszczenie okna kolorem itp.
	- modele (m.in. Sponza, s¹ w Downloads/ na PC)
	- porz¹dna hierarchia katalogów - zacz¹tek jest, teraz rozbudowaæ i powrzucaæ pliki (+ w src zrobiæ)

	- jakiœ ³adny system budowania shaderów
	- informacje o GPU, monitorach, rozdzielczoœciach itp. -> jakieœ Entity zarz¹dzaj¹ce tym, pobieranie listy rozdzielczoœci nieposortowanej i posortowanej
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