#ifndef __SYSTEMHPP__
#define __SYSTEMHPP__

#include <string>

namespace Hikari
{
	class Engine;

	class System
	{
		public:
			System( const std::string& ID );
			System( void );

			virtual void Init( Engine *pEngine ) = 0;
			virtual void Update( float dt ) = 0;

			const std::string& GetID( void ) const;
			void SetID( const std::string& ID );

			virtual ~System();

		private:
			std::string m_ID;
	};
}

#endif