#ifndef __COMPONENTHPP__
#define __COMPONENTHPP__

#include <string>

namespace Hikari
{
	class Component
	{
		public:
			Component( void );
			Component( std::string ID );

			virtual ~Component( void );

			const std::string& GetID( void ) const;
			void SetID( const std::string& newID );

		protected:
			std::string m_ID;
	};
}

#endif