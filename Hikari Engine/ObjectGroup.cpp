#include "ObjectGroup.hpp"

Hikari::ObjectGroup::ObjectGroup()
{
	m_pObjectGroups = new std::list<Hikari::ObjectGroup*>();
	m_pObjects = new std::list<Hikari::Object*>();
}

Hikari::ObjectGroup::ObjectGroup(Hikari::Object* pObject)
{
	m_pObjectGroups = new std::list<Hikari::ObjectGroup*>();
	m_pObjects = new std::list<Hikari::Object*>();
	m_pObjects->push_back(pObject);
}

Hikari::ObjectGroup::~ObjectGroup()
{
	delete m_pObjectGroups;
	delete m_pObjects;
}

std::string Hikari::ObjectGroup::name(void)
{
	return m_Name;
}

void Hikari::ObjectGroup::name(std::string name)
{
	m_Name = name;
}

int Hikari::ObjectGroup::add(Hikari::Object* pObject, std::string groupName = "")
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

		if( ! m_pObjectGroups->empty() )
		{
			for(auto currentGroup = m_pObjectGroups->begin(); currentGroup != m_pObjectGroups->end(); ++currentGroup)
			{
				if((*currentGroup)->add(pObject, groupName) == 0)	// +- DFS
				{
					return 0;
				}
			}
			return -1;
		}
	}
}

int Hikari::ObjectGroup::add(Hikari::ObjectGroup* pGroup, std::string groupName = "")
{
	if( groupName == "" )
	{
		m_pObjectGroups->push_back(pGroup);
		return 0;
	}
	else
	{
		if( m_Name == groupName )
		{
			m_pObjectGroups->push_back(pGroup);
			return 0;
		}

		if( ! m_pObjectGroups->empty() )
		{
			for(auto currentGroup = m_pObjectGroups->begin(); currentGroup != m_pObjectGroups->end(); ++currentGroup)
			{
				if((*currentGroup)->add(pGroup, groupName) == 0)	// +- DFS
				{
					return 0;
				}
			}
			return -1;
		}
	}
}


