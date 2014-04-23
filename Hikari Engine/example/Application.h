#ifndef __APPLICATION_H__
#define __APPLICATION_H__

/**
	\class	Application
	\brief	Klasa abstrakcyjna, która ma pozwalaæ na podmianê "w locie" uruchamianej aplikacji (wiem, trochê biedna, ale co zrobiæ)
*/

class Application {
	public:
		virtual void run(void) = 0; ///< uruchamia aplikacje (ciê¿ko by³o siê domyœliæ, nie? :P)
};

#endif // __APPLICATION_H__