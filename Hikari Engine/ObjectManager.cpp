#include "ObjectManager.hpp"
#include "Exception.hpp"

Hikari::ObjectManager::ObjectManager()
{
	m_Objects = NULL;
}

void Hikari::ObjectManager::setup(void)
{
	m_Objects = new std::list<Object*>();

	if(m_Objects == NULL)
	{
		throw new Exception("Could not initialize m_Objects pointer in ObjectManager::setup()", "NullPointerException");
	}
}

void Hikari::ObjectManager::cleanup(void)
{
	delete m_Objects;
	m_Objects = NULL;
}

void Hikari::ObjectManager::add(Hikari::Object* pObject)
{
	m_ObjectOperationMutex.lock();
	m_Objects->push_back(pObject);
	m_ObjectOperationMutex.unlock();
}

Hikari::Object* Hikari::ObjectManager::get(std::string name)
{
	m_ObjectOperationMutex.lock();
	for(std::list<Hikari::Object*>::iterator currentObject = m_Objects->begin(); currentObject != m_Objects->end(); currentObject++)
	{
		if((*currentObject)->name() == name)
		{
			m_ObjectOperationMutex.unlock();
			return *currentObject;
		}
	}

	m_ObjectOperationMutex.unlock();

	std::string message("Could not find object of name '");
	message.append(name + "'");

	throw new Exception(const_cast<char*>(message.c_str()), "ObjectNotFoundException");
}

void Hikari::ObjectManager::remove(std::string name)
{
	m_ObjectOperationMutex.lock();
	bool found;

	for(std::list<Hikari::Object*>::iterator currentObject = m_Objects->begin(); currentObject != m_Objects->end(); currentObject++)
	{
		if((*currentObject)->name() == name)
		{
			m_Objects->erase(currentObject);
			m_ObjectOperationMutex.unlock();
			found = true;
			break;
		}
	}

	if(!found)
	{
		std::string message("Could not find object of name '");
		message.append(name + "'");

		throw new Exception(const_cast<char*>(message.c_str()), "ObjectNotFoundException");
	}
}
