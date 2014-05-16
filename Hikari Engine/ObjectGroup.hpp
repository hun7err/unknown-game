#ifndef __OBJECT_GROUP_HPP__
#define __OBJECT_GROUP_HPP__

#include "Object.hpp"
#include <list>

namespace Hikari
{
	class ObjectGroup
	{
		public:
			ObjectGroup();					/**  */
			ObjectGroup(Object* pObject);	/**  */

			std::string name(void);			/**  */
			void name(std::string name);	/**  */

			int add(Object* pObject, std::string groupName);		/**  */
			int add(ObjectGroup* pGroup, std::string groupName);	/**  */

			//void removeObject(std::string name);
			//void removeGroup(std::string name);

			// ewentualnie move, rotate itp. - zale¿y od tego, na co pozwala i DirectX i Assimp

			virtual ~ObjectGroup();

		private:
			std::list<Object*> * m_pObjects;
			std::list<ObjectGroup*> * m_pObjectGroups;
			std::string m_Name;
	};
}

#endif // __OBJECT_GROUP_HPP__