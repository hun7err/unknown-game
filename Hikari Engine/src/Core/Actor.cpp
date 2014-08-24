#include "../../include/Core/Actor.hpp"
#include "../../include/Core/Components/Transformation.hpp"
#include "../../include/Core/Components/Vector4.hpp"
#include "../../include/Core/Messaging/Listener.hpp"
//#include "../../include/Core/Messaging/Messenger.hpp"

Hikari::Actor::Actor( void ) : Entity( )
{
	Init( );
}

Hikari::Actor::Actor( const std::string& ActorID ) : Entity( ActorID )
{
	Init( );
}

Hikari::Actor::~Actor( )
{
}

void Hikari::Actor::Init( void )
{
	Components::Transformation *pTransformation = new Components::Transformation( );
	Components::Vector4 *pPosition = new Components::Vector4( "Position", 0.0f, 0.0f, 0.0f, 1.0f );
	//Messenger *pMessenger = new Messenger( );
	Listener *pListener = new Listener( );

	AddComponent( pTransformation );
	AddComponent( pPosition );
	AddComponent( pListener );
}
