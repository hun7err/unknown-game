#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include <list>
#include <string>
#include <mutex>

namespace Hikari
{
	template <typename ManagedType> class Manager
	{
		public:
			Manager()
			{
				m_Objects = NULL;
			}

			Manager(const Manager& other) {}

			virtual ~Manager() {}
			
			void setup(void)
			{
				m_Objects = new std::list<Object*>();

				if(m_Objects == NULL)
				{
					throw new Exception("Could not initialize m_Objects pointer in Manager::setup()", "NullPointerException");
				}
			}

			void cleanup(void)
			{
				delete m_Objects;
				m_Objects = NULL;
			}

			void add(ManagedType* pObject)
			{
				m_ObjectOperationMutex.lock();
				m_Objects->push_back(pObject);
				m_ObjectOperationMutex.unlock();
			}

			ManagedType* get(std::string name)
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

			void remove(std::string name)
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

		private:
			std::list<ManagedType*>* m_Objects;
			std::mutex m_ObjectOperationMutex;
	};
}

#endif // __MANAGER_HPP__