#ifndef __OBJECTMANAGER_HPP__
#define __OBJECTMANAGER_HPP__

#include "Object.hpp"
#include "Manager.hpp"

namespace Hikari
{
	typedef Manager<Object> ObjectManager;

	std::vector<Object*> ObjectManager::m_Items;
	std::mutex ObjectManager::m_ItemMutex;
	/*
	class ObjectManager : public Manager<Node>
	{
		public:
			void add(Object* pObject)
			{
				if(m_Items.empty())
				{
					root = new Node();
				}
				root.add(pObject);
			}

			void add(Object* pObject, std::string nodeName)
			{
				// znajdŸ odpowiedni¹ grupê i dodaj tam pObject
			}

			~ObjectManager()
			{
				delete root;
			}
		private:
			Node* root;
	};
	*/
}

#endif