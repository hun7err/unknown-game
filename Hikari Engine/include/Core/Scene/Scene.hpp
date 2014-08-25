#ifndef __HIKARI_CORE_SCENE_SCENEHPP__
#define __HIKARI_CORE_SCENE_SCENEHPP__

#include "Node.hpp"
#include "../ErrorCode.hpp"
#include <string>

namespace Hikari
{
	class Scene
	{
		public:
			Scene( void );
			Scene( const std::string& sceneID );
			~Scene( void );

			void Add( Object *pObject );
			int Add( Object *pObject, const std::string& nodeName );

			void Add( Node *pNode );
			int Add( Node *pNode, const std::string& nodeName );

			int RemoveObject( const std::string& ObjectName );
			int RemoveNode( const std::string& NodeName );

			Node *GetRootNode( void );

			ErrorCode Load( const std::wstring& filename );

			const std::string& GetID( void ) const;
			void SetID( const std::string& newID );

		private:
			Node *m_pRoot;

			std::string m_ID;
	};
}

#endif