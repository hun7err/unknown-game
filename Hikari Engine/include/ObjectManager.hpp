#ifndef __OBJECTMANAGER_HPP__
#define __OBJECTMANAGER_HPP__

#include "Manager.hpp"
#include "Node.hpp"

namespace Hikari
{
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

			// to mo�e by� kiepski workaround, kt�ry zepsuje domy�lne dzia�anie, wi�c daj� tu ten komentarz jako przestrog� dla siebie samego
			static std::vector<Hikari::Node*> m_Items;
			static std::mutex m_ItemMutex;
	};
}

#endif