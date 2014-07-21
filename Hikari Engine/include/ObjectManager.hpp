#ifndef __OBJECTMANAGER_HPP__
#define __OBJECTMANAGER_HPP__

#include "Manager.hpp"
#include "Node.hpp"

namespace Hikari
{
	class ObjectManager : public Manager<Node>
	{
		public:
			static void add(Object* pObject)
			{
				if(m_Items.empty())
				{
					root = new Node();
				}
				root->add(pObject);
			}

			static int add(Object* pObject, std::string nodeName)
			{
				return root->add(pObject, nodeName);
			}

			static void add(Node *pNode)
			{
				root->add(pNode);
			}

			static int add(Node *pNode, std::string nodeName)
			{
				return root->add(pNode, nodeName);
			}

			~ObjectManager()
			{
				delete root;
			}
		private:
			ObjectManager() {}
			static Node* root;
	};

	std::vector<Node*> ObjectManager::m_Items;
	std::mutex ObjectManager::m_ItemMutex;
	Hikari::Node* Hikari::ObjectManager::root = new Hikari::Node();
}

#endif