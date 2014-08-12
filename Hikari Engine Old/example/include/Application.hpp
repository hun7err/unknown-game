#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

/**
	\file	Application.hpp
	\date	2014-07-21
	\author	Krzysztof 'hun7er' Marciniak
*/

/**
	\class	Application
	\brief	Pomocnicza klasa abstrakcyjna, która ma pozwalaæ na podmianê "w locie" uruchamianej aplikacji (wiem, trochê biedna, ale co zrobiæ)
*/
class Application
{
	public:
		virtual void run(void) = 0; ///< uruchamia aplikacje (ciê¿ko by³o siê domyœliæ, nie? :P)
};

#endif // __APPLICATION_HPP__