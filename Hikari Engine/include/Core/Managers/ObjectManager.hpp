#ifndef __OBJECTMANAGER_HPP__
#define __OBJECTMANAGER_HPP__

/**
	\file	ObjectManager.hpp
	\author	Krzysztof 'hun7er' Marciniak
	\date	2014-07-23
*/

#include "../../Core/Managers/Interface/Manager.hpp"
#include "../../Core/Objects/Node/Node.hpp"

namespace Hikari
{
	/**
		\class	ObjectManager
		\brief	Mened�er obiekt�w: ka�dy obiekt znajduj�cy si� w nim zostanie wyrenderowany je�li wywo�a si� metod� draw() na korzeniu (root). Dodanie obiektu (Object) bez podania nazwy docelowego w�z�a (Node) skutkowa�o b�dzie dodaniem go do korzenia - podobnie wygl�da kwestia dodawania w�z�a. Na koniec, to jest przy wywo�aniu Hikari::Engine::cleanup(), wywo�ane zostaje cleanup() na wszystkich obiektach, a nast�pnie zostaj� one zwolnione wraz z korzeniem.
	*/
	class ObjectManager : public Manager<Node>
	{
		public:
			static void add(Object *pObject);
			static int add(Object *pObject, std::string nodeName);
			static void add(Node *pNode);
			static int add(Node *pNode, std::string nodeName);
			static Node* root(void);

			~ObjectManager();
		private:
			ObjectManager();
			static Node* m_pRoot;
	};
}

#endif