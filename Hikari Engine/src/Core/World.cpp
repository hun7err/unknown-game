#include "../../include/Core/World.hpp"

Hikari::World::World( void ) : m_pAssetManager( nullptr )
{
	m_AssetManagerMutex.lock( );
	Scene *pDefaultScene = new Scene("Default");

	m_pActiveScene = pDefaultScene;

	m_SceneMutex.lock( );
	m_Scenes.push_back( pDefaultScene );
	m_SceneMutex.unlock( );

	AssetManager *pAssetManager = new AssetManager( );

	m_pAssetManager = pAssetManager;
	m_AssetManagerMutex.unlock( );
}

Hikari::World::~World( void )
{
	for( auto scene = m_Scenes.begin(); scene != m_Scenes.end(); ++scene )
	{
		delete *scene;
	}

	delete m_pAssetManager;
}

Hikari::AssetManager *Hikari::World::GetAssetManager( void )
{
	return m_pAssetManager;
}

void Hikari::World::AddScene( Scene* scene )
{
	m_SceneMutex.lock( );
	m_Scenes.push_back( scene );
	m_SceneMutex.unlock( );
}

Hikari::Scene *Hikari::World::GetScene( const std::string& sceneID )
{
	m_SceneMutex.lock();

	for( auto scene = m_Scenes.begin(); scene != m_Scenes.end(); ++scene )
	{
		if( ( *scene )->GetID() == sceneID )
		{
			m_SceneMutex.unlock( );
			return *scene;
		}
	}

	m_SceneMutex.unlock( );

	return nullptr;
}

void Hikari::World::RemoveScene( const std::string& sceneID, bool freeRemovedElement )
{
	m_SceneMutex.lock();

	for( auto scene = m_Scenes.begin(); scene != m_Scenes.end(); ++scene )
	{
		if( ( *scene )->GetID() == sceneID )
		{
			if( freeRemovedElement )
			{
				delete *scene;
			}

			m_Scenes.erase( scene );

			break;
		}
	}

	m_SceneMutex.unlock( );
}

Hikari::ErrorCode Hikari::World::LoadScene( const std::wstring& filename )
{
	Scene *pScene = new Scene();

	ErrorCode errorCode = pScene->Load( filename );

	if( errorCode == ErrorCode::SUCCESS )
	{
		m_Scenes.push_back( pScene );
	}

	return errorCode;
}

Hikari::ErrorCode Hikari::World::SetActiveScene( const std::string& sceneID )
{
	ErrorCode errorCode = ErrorCode::WORLD_SCENE_NOT_FOUND;

	m_SceneMutex.lock( );

	for( auto scene = m_Scenes.begin(); scene != m_Scenes.end(); ++scene )
	{
		if( (*scene)->GetID() == sceneID )
		{
			m_pActiveScene = *scene;
			errorCode = ErrorCode::SUCCESS;

			break;
		}
	}

	m_SceneMutex.unlock();

	return errorCode;
}

Hikari::Scene* Hikari::World::GetActiveScene( void )
{
	return m_pActiveScene;
}

