#ifndef __OBJECT_MANAGER_HPP__
#define __OBJECT_MANAGER_HPP__

#include <list>
#include <string>
#include <mutex>
#include "Object.hpp"

namespace Hikari {
	class ObjectManager {
		public:
			ObjectManager();
			ObjectManager(const ObjectManager& other);
			void setup(void);
			void cleanup(void);

			void add(Object* pObject);
			Object* get(std::string name);
			void remove(std::string name);

		private:
			std::list<Object*>* m_Objects;
			std::mutex m_ObjectOperationMutex;
	};
}

#endif // __OBJECT_MANAGER_HPP__