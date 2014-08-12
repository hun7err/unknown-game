#include "../../../include/Helpers/ECS/Entity.hpp"

Hikari::Entity::Entity( void )
{
}

Hikari::Entity::Entity( const std::string& ID ) : m_ID(ID)
{
}

Hikari::Entity::~Entity( void )
{
	for( auto currentComponent = m_Components.begin(); currentComponent != m_Components.end(); ++currentComponent )
	{
		delete *currentComponent;
		*currentComponent = nullptr;
	}
}

const std::string& Hikari::Entity::GetID( void ) const
{
	return m_ID;
}

void Hikari::Entity::SetID( const std::string& newID )
{
	m_ID = newID;
}

Hikari::Component* Hikari::Entity::GetComponent( const std::string& componentID )
{
	for( auto currentComponent = m_Components.begin(); currentComponent != m_Components.end(); ++currentComponent )
	{
		if( (*currentComponent)->GetID() == componentID )
		{
			return *currentComponent;
		}
	}
	// nie znaleziono
	return nullptr;
}

void Hikari::Entity::AddComponent( Hikari::Component *pComponent )
{
	m_Components.push_back(pComponent);
}

bool Hikari::Entity::RemoveComponent( const std::string& componentID )	// sprawdziæ czy dzia³a!
{
	for( auto currentComponent = m_Components.begin(); currentComponent != m_Components.end(); ++currentComponent )
	{
		if( (*currentComponent)->GetID() == componentID )
		{
			m_Components.erase(currentComponent);
			return true;
		}
	}

	return false;
}
