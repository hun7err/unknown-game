#ifndef __HIKARI_CORE_WORLDHPP__
#define __HIKARI_CORE_WORLDHPP__

#include "Managers/AssetManager.hpp"
#include "Scene/Scene.hpp"
#include "ErrorCode.hpp"
#include <mutex>
#include <list>

namespace Hikari
{
	class World
	{
		public:
			World( void );
			~World( void );

			AssetManager *GetAssetManager( void );

			void AddScene( Scene* scene );
			Scene *GetScene( const std::string& sceneID );
			void RemoveScene( const std::string& sceneID, bool freeRemovedElement = true );
			ErrorCode LoadScene( const std::wstring& filename );

			ErrorCode SetActiveScene( const std::string& sceneID );
			Scene* GetActiveScene( void );

		private:
			AssetManager *m_pAssetManager;
			std::list<Scene*> m_Scenes;	// zastanowiæ siê, czy nie lepiej std::map

			std::mutex	m_SceneMutex,
						m_AssetManagerMutex;
			Scene *m_pActiveScene;
	};
}

#endif