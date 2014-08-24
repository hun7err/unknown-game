#include "../../../include/Core/Managers/AssetManager.hpp"

Hikari::HAsset::HAsset( Hikari::AssetManager *pManager ) : m_pManager( pManager )
{
}

Hikari::Asset* Hikari::HAsset::operator->( void ) const
{
	return m_pManager->Manager::Get( m_Key );
}

Hikari::Asset* Hikari::HAsset::operator*( void )
{
	return m_pManager->Manager::Get( m_Key );
}

bool Hikari::HAsset::IsValid( void )
{
	return m_pManager->IsValidKey( m_Key, m_Magic );
}

Hikari::HAsset Hikari::AssetManager::Add( Hikari::Asset *pAsset )
{
	int key = Manager::Add( pAsset );

	HAsset handle( this );
	handle.m_Key = key;

	m_ElementMutex.lock();

	int magic = m_Elements[ key ].second;

	m_ElementMutex.unlock();

	handle.m_Magic = magic;

	return handle;
}

Hikari::ErrorCode Hikari::AssetManager::Remove( const Hikari::HAsset& asset )
{
	m_ElementMutex.lock();

	if( asset.m_Key < 0 || asset.m_Key >= (int)m_Elements.size() )
	{
		m_ElementMutex.unlock();

		return ErrorCode::MANAGER_INVALID_KEY;
	}

	if( asset.m_Magic != m_Elements[ asset.m_Key ].second )
	{
		m_ElementMutex.unlock();

		return ErrorCode::MANAGER_OUTDATED_HANDLE;
	}

	Manager::Remove( asset.m_Key );

	m_ElementMutex.unlock();

	return ErrorCode::SUCCESS;
}

Hikari::Asset *Hikari::AssetManager::Get( const Hikari::HAsset& hAsset )
{
	m_ElementMutex.lock();

	if( hAsset.m_Key < 0 || hAsset.m_Key >= (int)m_Elements.size() )
	{
		m_ElementMutex.unlock();

		return nullptr;
	}

	if( hAsset.m_Magic != m_Elements[ hAsset.m_Key ].second )
	{
		m_ElementMutex.unlock();

		return nullptr;
	}

	Asset *pAsset = m_Elements[ hAsset.m_Key ].first;

	m_ElementMutex.unlock();

	return pAsset;
}
