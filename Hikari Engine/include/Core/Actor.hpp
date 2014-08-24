#ifndef __HIKARI_CORE_ACTORHPP__
#define __HIKARI_CORE_ACTORHPP__

#include "../Helpers/ECS/Entity.hpp"
#include <string>

namespace Hikari
{
	class Actor : public Entity
	{
		public:
			Actor( void );
			Actor( const std::string& ActorID );

			virtual ~Actor();

		private:
			void Init( void );
	};
}

#endif