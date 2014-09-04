#ifndef __HIKARI_GRAPHICS_ASSETS_MATERIALHPP__
#define __HIKARI_GRAPHICS_ASSETS_MATERIALHPP__

#include "../../Helpers/ECS/Entity.hpp"
#include "Asset.hpp"
#include <vector>
#include <map>
#include <d3d11.h>

namespace Hikari
{
	namespace Assets
	{
		class Material : public Asset, public Entity, public Component
		{
			public:
				Material( void );
				Material( const std::string& AssetID );

				void AddComponent( Component *pComponent );
				bool RemoveComponent( const std::string& componentID );

				ErrorCode Load( const std::string& filename );

				ID3D11ShaderResourceView** GetShaderResources( void );
				unsigned int GetShaderResourceCount( void ) const;

			private:
				std::vector< ID3D11ShaderResourceView* > m_ShaderResources;
				std::map< std::string, unsigned int > m_ComponentPositions;
		};
	}
}

#endif