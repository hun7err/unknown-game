#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include <vector>
#include <string>
#include <mutex>
#include "Exception.hpp"

namespace Hikari
{
	template <typename TypeName> class Manager
	{
		public:
			static unsigned int add(TypeName* pObject)
			{
				unsigned int key;
				m_ItemMutex.lock();

				key = m_Items.size();
				m_Items.push_back(pObject);

				m_ItemMutex.unlock();

				return key;
			}

			static TypeName* get(int key)
			{
				m_ItemMutex.lock();
				if(key >= (int)m_Items.size() || key < 0)
				{
					m_ItemMutex.unlock();

					Exception e("Invalid key in Manager::get(int)", "InvalidKeyException");
					throw e;
				}

				TypeName* pMaterial = m_Items[key];
				m_ItemMutex.unlock();

				return pMaterial;
			}

			static TypeName* get(std::string name)
			{
				m_ItemMutex.lock();

				for(std::vector<TypeName*>::iterator currentItem = m_Items.begin(); currentItem != m_Items.end(); ++currentItem)
				{
					if((*currentItem)->name() == name)
					{
						m_ItemMutex.unlock();
						return *currentMaterial;
					}
				}

				m_ItemMutex.unlock();
				return NULL;
			}

			static void remove(std::string name)
			{
				m_ItemMutex.lock();

				for(std::vector<TypeName*>::iterator currentItem = m_Items.begin(); currentItem != m_Items.end(); ++currentItem)
				{
					if((*currentItem)->name() == name)
					{
						m_ItemMutex.unlock();
						m_Items.erase(currentItem);
						break;
					}
				}

				m_ItemMutex.unlock();

				Exception e("An element with given name could not be found in Hikari::Manager::remove(std::string)", "NoSuchElementException");
				throw e;
			}

			static void remove(int key)
			{
				m_ItemMutex.lock();
				if(key >= (int)m_Items.size() || key < 0)
				{
					m_ItemMutex.unlock();

					Exception e("Invalid key in Manager::remove(int)", "OutOfBoundsException");
					throw e;
				}

				m_Items.erase(m_Items.begin() + key);

				m_ItemMutex.unlock();
			}

			static bool isValidKey(int key)
			{
				bool valid = false;
				m_ItemMutex.lock();
				if(key < (int)m_Items.size() && key >= 0)
				{
					if(m_Items[key] != NULL)
					{
						valid = true;
					}
				}
				m_ItemMutex.unlock();

				return valid;
			}

		protected:
			static std::vector<TypeName*> m_Items;
			Manager() {}
			static std::mutex m_ItemMutex;
	};
}

#endif // __MANAGER_HPP__