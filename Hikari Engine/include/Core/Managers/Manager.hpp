#ifndef __HIKARI_CORE_MANAGERS_MANAGERHPP__
#define __HIKARI_CORE_MANAGERS_MANAGERHPP__

#include "../../Core/ErrorCode.hpp"
#include <vector>
#include <utility>
#include <mutex>

namespace Hikari
{
	template < typename ManagedType > class Manager
	{
		public:
			ManagedType *Get( int key )
			{
				m_ElementMutex.lock();

				if( key < 0 || key >= (int)m_Elements.size() )
				{
					m_ElementMutex.unlock();

					return nullptr;
				}

				ManagedType *pObject = m_Elements[ key ].first;

				m_ElementMutex.unlock();

				return pObject;
			}

			ManagedType *Get( const std::string& name )
			{
				m_ElementMutex.lock();
				
				ManagedType *pObject;
				
				for( auto element = m_Elements.begin(); element != m_Elements.end(); ++element )
				{
					if( ( *element ).first->GetID() == name )
					{
						pObject = ( *element ).first;
						m_ElementMutex.unlock();

						return pObject;
					}
				}
				
				m_ElementMutex.unlock();
				
				return nullptr;
			}

			bool IsValidKey( int key, unsigned int magic )
			{
				m_ElementMutex.lock();

				if( key < 0 || key >= (int)m_Elements.size() )
				{
					m_ElementMutex.unlock();

					return false;
				}

				unsigned int current_magic = m_Elements[ key ].second;

				if( current_magic != magic )
				{
					m_ElementMutex.unlock();

					return false;
				}

				m_ElementMutex.unlock();

				return true;
			}

		protected:
			unsigned int Add( ManagedType *pObject )
			{
				unsigned int key;

				m_ElementMutex.lock();

				if( !m_FreeSlots.empty() )
				{
					key = m_FreeSlots.back();
					m_FreeSlots.pop_back();

					m_Elements[ key ].second++;
					m_Elements[ key ].first = pObject;

					return key;
				}
				else
				{
					key = m_Elements.size();
					m_Elements.push_back( std::make_pair( pObject, 0 ) );
					
					m_ElementMutex.unlock();

					return key;
				}
			}

			void Remove( int key )
			{
				delete m_Elements[ key ].first;

				m_FreeSlots.push_back( key );
			}

			std::vector< std::pair< ManagedType*, unsigned int > > m_Elements;
			std::vector< unsigned int > m_FreeSlots;
			std::mutex m_ElementMutex;
	};
}

#endif