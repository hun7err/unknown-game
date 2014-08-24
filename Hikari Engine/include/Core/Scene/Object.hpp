#ifndef __HIKARI_CORE_OBJECTS_OBJECTHPP__
#define __HIKARI_CORE_OBJECTS_OBJECTHPP__

#include "../Actor.hpp"
#include <string>

namespace Hikari
{
	class Object : public Actor
	{
		public:
			Object( void );
			Object( const std::string& ObjectID );

		private:
	};
}

#endif