#ifndef __HIKARI_CORE_OBJECTS_NODEHPP__
#define __HIKARI_CORE_OBJECTS_NODEHPP__

#include "Object.hpp"
#include "../../Helpers/ECS/Entity.hpp"
#include <list>

namespace Hikari
{
	class Node : public Entity
	{
		public:
			Node( void );
			Node( const std::string& nodeName );

			void Add( Object *pObject );
			int Add( Object *pObject, const std::string& nodeName );

			void Add( Node *pNode );
			int Add( Node *pNode, const std::string& nodeName );

			int RemoveObject( const std::string& objectID );
			int RemoveNode( const std::string& nodeID );

		private:
			std::list<Object*> m_Objects;
			std::list<Node*> m_Nodes;

			void Init( void );
	};
}

#endif