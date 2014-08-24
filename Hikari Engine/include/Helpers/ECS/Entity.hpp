#ifndef __HIKARI_HELPERS_ECS_ENTITYHPP__
#define __HIKARI_HELPERS_ECS_ENTITYHPP__

#include "Component.hpp"
#include <vector>
#include <string>

namespace Hikari
{
	class Entity
	{
		public:
			Entity( void );
			Entity( const std::string& ID );

			virtual ~Entity( void );

			const std::string& GetID( void ) const;
			void SetID( const std::string& newID );

			Component *GetComponent( const std::string& componentID );	// nullptr jak nie ma
			void AddComponent( Component *pComponent );
			bool RemoveComponent( const std::string& componentID );
			const std::vector<Component*>& GetComponentList( void ) const;

		protected:
			std::vector<Component*> m_Components;
			std::string m_ID;
	};
};

#endif