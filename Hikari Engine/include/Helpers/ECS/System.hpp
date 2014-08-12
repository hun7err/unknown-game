#ifndef __SYSTEMHPP__
#define __SYSTEMHPP__

namespace Hikari
{
	class Engine;

	class System
	{
		public:
			virtual void Init( Engine *pEngine ) = 0;
			virtual void Update( float dt ) = 0;
			//virtual void SendMessage( void* pMsg ) = 0; // bo i tak bêdzie Listener-Messanger

			virtual ~System() {}
	};
}

#endif