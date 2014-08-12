#ifndef __MESSAGEHPP__
#define __MESSAGEHPP__

namespace Hikari
{
	class Message
	{
		public:
			Message( void );
			Message( short int ID );

			short int GetID( void ) const;
			void SetID( short int newID );

		private:
			short int m_ID;
	};
}

#endif