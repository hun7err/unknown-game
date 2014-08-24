#ifndef __HIKARI_CORE_MANAGERS_ASSETMANAGERHPP__
#define __HIKARI_CORE_MANAGERS_ASSETMANAGERHPP__

#include "Manager.hpp"
#include "../../Graphics/Assets/Asset.hpp"

namespace Hikari
{
	class AssetManager;

	class HAsset
	{
		public:
			HAsset( AssetManager *pManager );

			Asset* operator->( void ) const;
			Asset* operator*( void );
			bool IsValid( void );

			friend class AssetManager;

		private:
			int m_Key;
			unsigned int m_Magic;
			AssetManager *m_pManager;
	};

	class AssetManager : public Manager< Asset >
	{
		public:
			HAsset Add( Asset *pAsset );
			ErrorCode Remove( const HAsset& asset );
			Asset *Get( const HAsset& hAsset );

		private:
	};
}

#endif