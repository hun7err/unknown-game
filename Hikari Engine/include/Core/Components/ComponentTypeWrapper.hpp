#ifndef __COMPONENTTYPEWRAPPERHPP__
#define __COMPONENTTYPEWRAPPERHPP__

namespace Hikari
{
	namespace Helpers
	{
		template < typename TypeName > class ComponentTypeWrapper
		{
			public:
				const TypeName& GetValue( void ) const
				{
					return m_Value;
				}

				void SetValue( const TypeName& newValue )
				{
					m_Value = newValue;
				}

			protected:
				TypeName m_Value;
		};
	}
}

#endif