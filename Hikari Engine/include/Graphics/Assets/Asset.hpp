#ifndef __HIKARI_GRAPHICS_ASSETS_ASSETHPP__
#define __HIKARI_GRAPHICS_ASSETS_ASSETHPP__

#include "../../Core/ErrorCode.hpp"
#include <string>

namespace Hikari
{
	class Asset
	{
		public:
			Asset( void );
			Asset( const std::string& ID );

			virtual ~Asset();

			const std::string& GetID( void ) const;
			void SetID( const std::string& newID );

			virtual ErrorCode Load( const std::string& filename ) = 0;

		protected:
			std::string m_ID;
	};
}

#endif