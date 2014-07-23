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
	};
}

#endif