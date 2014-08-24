#ifndef __HIKARI_CORE_COMPONENTS_FLOATHPP__
#define __HIKARI_CORE_COMPONENTS_FLOATHPP__

#include "../../Helpers/ECS/Component.hpp"
#include "../../Helpers/ECS/ComponentTypeWrapper.hpp"

namespace Hikari
{
	namespace Components
	{
		class Float : public Component, public Helpers::ComponentTypeWrapper<float>
		{
			public:
				Float( const std::string& ComponentID );
				Float( const std::string& ComponentID, float defaultValue );

				float GetMinValue( void );
				float GetMaxValue( void );

				void SetMinValue( float minValue );
				void SetMaxValue( float maxValue );

			private:
				float	m_MinValue,
						m_MaxValue;
		};
	}
}

#endif