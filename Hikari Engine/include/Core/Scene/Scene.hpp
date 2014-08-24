#ifndef __HIKARI_CORE_SCENE_SCENEHPP__
#define __HIKARI_CORE_SCENE_SCENEHPP__

#include "Node.hpp"

namespace Hikari
{
	class Scene
	{
		public:
			Scene( void );
			~Scene( void );

			void Add( Object *pObject );
			int Add( Object *pObject, const std::string& nodeName );

			void Add( Node *pNode );
			int Add( Node *pNode, const std::string& nodeName );

			int RemoveObject( const std::string& ObjectName );
			int RemoveNode( const std::string& NodeName );

			Node *GetRootNode( void );

		private:
			Node *m_pRoot;
	};
}

#endif