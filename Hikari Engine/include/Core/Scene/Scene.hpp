#ifndef __HIKARI_CORE_SCENE_SCENEHPP__
#define __HIKARI_CORE_SCENE_SCENEHPP__

#include "Node.hpp"
#include "../ErrorCode.hpp"
#include "../Cameras/Camera.hpp"
#include <string>

namespace Hikari
{
	class Scene
	{
		public:
			Scene( void );
			Scene( const std::string& sceneID );
			~Scene( void );

			void SetActiveCamera( Camera *pCamera );
			Camera* GetActiveCamera( void );

			void Add( const Object& object );
			int Add( const Object& object, const std::string& nodeName );

			void Add( const Node& node );
			int Add( const Node& node, const std::string& nodeName );

			int RemoveObject( const std::string& ObjectName );
			int RemoveNode( const std::string& NodeName );

			Node& GetRootNode( void );

			ErrorCode Load( const std::wstring& filename );

			const std::string& GetID( void ) const;
			void SetID( const std::string& newID );

		private:
			Camera *m_pActiveCamera;

			std::vector< Camera* > m_Cameras;

			Node m_Root;

			std::string m_ID;
	};
}

#endif