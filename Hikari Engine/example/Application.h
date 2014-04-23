#ifndef __APPLICATION_H__
#define __APPLICATION_H__

/**
	\class	Application
	\brief	Klasa abstrakcyjna, kt�ra ma pozwala� na podmian� "w locie" uruchamianej aplikacji (wiem, troch� biedna, ale co zrobi�)
*/

class Application {
	public:
		virtual void run(void) = 0; ///< uruchamia aplikacje (ci�ko by�o si� domy�li�, nie? :P)
};

#endif // __APPLICATION_H__