#include "Node.hpp"

Hikari::Node::Node()
{
	m_pNodes = new std::list<Hikari::Node*>();
	m_pObjects = new std::list<Hikari::Object*>();
}

Hikari::Node::Node(Hikari::Object* pObject)
{
	m_pNodes = new std::list<Hikari::Node*>();
	m_pObjects = new std::list<Hikari::Object*>();
	m_pObjects->push_back(pObject);
}

Hikari::Node::~Node()
{
	delete m_pNodes;
	delete m_pObjects;
}

std::list<Hikari::Node*>* Hikari::Node::nodes(void)
{
	return m_pNodes;
}

std::list<Hikari::Object*>* Hikari::Node::objects(void)
{
	return m_pObjects;
}

void Hikari::Node::draw(ID3D11DeviceContext* pDeviceContext)
{
}

std::string Hikari::Node::name(void)
{
	return m_Name;
}

void Hikari::Node::name(std::string name)
{
	m_Name = name;
}

int Hikari::Node::add(Hikari::Object* pObject, std::string groupName = "")
{
	if( groupName == "" )
	{
		m_pObjects->push_back(pObject);
		return 0;
	}
	else
	{
		if( m_Name == groupName )
		{
			m_pObjects->push_back(pObject);
			return 0;
		}

		if( ! m_pNodes->empty() )
		{
			for(auto currentGroup = m_pNodes->begin(); currentGroup != m_pNodes->end(); ++currentGroup)
			{
				if((*currentGroup)->add(pObject, groupName) == 0)	// +- DFS
				{
					return 0;
				}
			}
		}
		return -1;
	}
}

int Hikari::Node::add(Hikari::Node* pGroup, std::string groupName = "")
{
	if( groupName == "" )
	{
		m_pNodes->push_back(pGroup);
		return 0;
	}
	else
	{
		if( m_Name == groupName )
		{
			m_pNodes->push_back(pGroup);
			return 0;
		}

		if( ! m_pNodes->empty() )
		{
			for(auto currentGroup = m_pNodes->begin(); currentGroup != m_pNodes->end(); ++currentGroup)
			{
				if((*currentGroup)->add(pGroup, groupName) == 0)	// +- DFS
				{
					return 0;
				}
			}
		}
		return -1;
	}
}


