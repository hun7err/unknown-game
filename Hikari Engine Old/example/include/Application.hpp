#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

/**
	\file	Application.hpp
	\date	2014-07-21
	\author	Krzysztof 'hun7er' Marciniak
*/

/**
	\class	Application
	\brief	Pomocnicza klasa abstrakcyjna, kt�ra ma pozwala� na podmian� "w locie" uruchamianej aplikacji (wiem, troch� biedna, ale co zrobi�)
*/
class Application
{
	public:
		virtual void run(void) = 0; ///< uruchamia aplikacje (ci�ko by�o si� domy�li�, nie? :P)
};

#endif // __APPLICATION_HPP__