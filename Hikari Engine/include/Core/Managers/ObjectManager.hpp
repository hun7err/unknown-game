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
		\brief	Mened¿er obiektów: ka¿dy obiekt znajduj¹cy siê w nim zostanie wyrenderowany jeœli wywo³a siê metodê draw() na korzeniu (root). Dodanie obiektu (Object) bez podania nazwy docelowego wêz³a (Node) skutkowa³o bêdzie dodaniem go do korzenia - podobnie wygl¹da kwestia dodawania wêz³a. Na koniec, to jest przy wywo³aniu Hikari::Engine::cleanup(), wywo³ane zostaje cleanup() na wszystkich obiektach, a nastêpnie zostaj¹ one zwolnione wraz z korzeniem.
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