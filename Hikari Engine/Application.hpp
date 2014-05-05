#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

/**
	\class	Application
	\brief	Klasa abstrakcyjna, która ma pozwalaæ na podmianê "w locie" uruchamianej aplikacji (wiem, trochê biedna, ale co zrobiæ)
*/
namespace Hikari
{
	class Application
	{
		public:
			virtual void run(void) = 0; ///< uruchamia aplikacje (ciê¿ko by³o siê domyœliæ, nie? :P)
	};
}

#endif // __APPLICATION_HPP__