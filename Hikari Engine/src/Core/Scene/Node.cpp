#include "../../../include/Core/Scene/Node.hpp"
#include "../../../include/Core/Components/Transformation.hpp"

Hikari::Node::Node( void ) : Entity( )
{
	Init( );
}

Hikari::Node::Node( const std::string& nodeName ) : Entity( nodeName )
{
	Init( );
}

void Hikari::Node::Init( void )
{
	Components::Transformation *pTransformation = new Components::Transformation( );

	AddComponent( pTransformation );
}

void Hikari::Node::Add( const Object& objectToAdd )
{
	m_Objects.push_back( objectToAdd );
}

int Hikari::Node::Add( const Object& objectToAdd, const std::string& nodeName )
{
	if( GetID() == nodeName )
	{
		m_Objects.push_back( objectToAdd );
		return 0;
	}

	if( ! m_Nodes.empty() )
	{
		for( auto node = m_Nodes.begin(); node != m_Nodes.end(); ++node )
		{
			if( node->Add( objectToAdd, nodeName ) == 0 )	// +- DFS
			{
				return 0;
			}
		}
	}

	return -1;
}

void Hikari::Node::Add( const Node& nodeToAdd )
{
	m_Nodes.push_back( nodeToAdd );
}

int Hikari::Node::Add( const Node& nodeToAdd, const std::string& nodeName )
{
	if( GetID() == nodeName )
	{
		m_Nodes.push_back( nodeToAdd );
		return 0;
	}

	if( ! m_Nodes.empty() )
	{
		for( auto node = m_Nodes.begin(); node != m_Nodes.end(); ++node )
		{
			if( node->Add( nodeToAdd, nodeName ) == 0 )	// +- DFS
			{
				return 0;
			}
		}
	}

	return -1;
}

int Hikari::Node::RemoveObject( const std::string& objectID )
{
	for( auto object = m_Objects.begin(); object != m_Objects.end(); ++object )
	{
		if( object->GetID() == objectID )
		{
			m_Objects.erase( object );

			return 0;
		}
	}

	for( auto node = m_Nodes.begin(); node != m_Nodes.end(); ++node )
	{
		if( node->RemoveObject( objectID ) == 0 )
		{
			return 0;
		}
	}

	return -1;
}

int Hikari::Node::RemoveNode( const std::string& nodeID )
{
	for( auto node = m_Nodes.begin(); node != m_Nodes.end(); ++node )
	{
		if( node->GetID() == nodeID )
		{
			m_Nodes.erase( node );

			return 0;
		}
	}

	for( auto node = m_Nodes.begin(); node != m_Nodes.end(); ++node )
	{
		if( node->RemoveNode( nodeID ) == 0 )
		{
			return 0;
		}
	}

	return -1;
}

const std::vector< Hikari::Object >& Hikari::Node::GetChildrenObjects( void ) const
{
	return m_Objects;
}

const std::vector< Hikari::Node >& Hikari::Node::GetChildrenNodes( void ) const
{
	return m_Nodes;
}
