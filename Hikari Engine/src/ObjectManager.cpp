#include "../include/ObjectManager.hpp"

std::vector<Hikari::Node*> Hikari::Manager<Hikari::Node>::m_Items;
std::mutex Hikari::Manager<Hikari::Node>::m_ItemMutex;
Hikari::Node* Hikari::ObjectManager::m_pRoot = new Hikari::Node();

Hikari::ObjectManager::ObjectManager()
{
}

Hikari::ObjectManager::~ObjectManager()
{
	delete m_pRoot;
}

void Hikari::ObjectManager::add(Hikari::Object *pObject)
{
	if(m_Items.empty())
	{
		m_pRoot = new Node();
	}
	pObject->setup();
	m_pRoot->add(pObject);
}

int Hikari::ObjectManager::add(Hikari::Object *pObject, std::string nodeName)
{
	pObject->setup();
	return m_pRoot->add(pObject, nodeName);
}

void Hikari::ObjectManager::add(Hikari::Node *pNode)
{
	pNode->setup();
	m_pRoot->add(pNode);
}

int Hikari::ObjectManager::add(Hikari::Node *pNode, std::string nodeName)
{
	pNode->setup();
	return m_pRoot->add(pNode, nodeName);
}

Hikari::Node *Hikari::ObjectManager::root(void)
{
	return m_pRoot;
}
