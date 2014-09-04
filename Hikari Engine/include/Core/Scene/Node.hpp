#ifndef __HIKARI_CORE_OBJECTS_NODEHPP__
#define __HIKARI_CORE_OBJECTS_NODEHPP__

#include "Object.hpp"
#include "../../Helpers/ECS/Entity.hpp"
#include <vector>

namespace Hikari
{
	class Node : public Entity
	{
		public:
			Node( void );
			Node( const std::string& nodeName );

			void Add( const Object& objectToAdd );
			int Add( const Object& objectToAdd, const std::string& nodeName );

			void Add( const Node& nodeToAdd );
			int Add( const Node& nodeToAdd, const std::string& nodeName );

			int RemoveObject( const std::string& objectID );
			int RemoveNode( const std::string& nodeID );

			const std::vector< Object >& GetChildrenObjects( void ) const;
			const std::vector< Node >& GetChildrenNodes( void ) const;

		private:
			std::vector< Object > m_Objects;
			std::vector< Node > m_Nodes;

			void Init( void );
	};
}

#endif