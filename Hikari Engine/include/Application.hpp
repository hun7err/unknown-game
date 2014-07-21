#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

/**
	\class	Application
	\brief	Klasa abstrakcyjna, kt�ra ma pozwala� na podmian� "w locie" uruchamianej aplikacji (wiem, troch� biedna, ale co zrobi�)
*/
namespace Hikari
{
	class Application
	{
		public:
			virtual void run(void) = 0; ///< uruchamia aplikacje (ci�ko by�o si� domy�li�, nie? :P)
	};
}

#endif // __APPLICATION_HPP__