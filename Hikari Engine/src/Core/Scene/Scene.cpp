#include "../../../include/Core/Scene/Scene.hpp"

Hikari::Scene::Scene( void )
{
	m_pRoot = new Node( "Root" );
}

Hikari::Scene::Scene( const std::string& sceneID ) : m_ID( sceneID )
{
	m_pRoot = new Node( "Root" );
}

Hikari::Scene::~Scene( void )
{
	delete m_pRoot;
}

void Hikari::Scene::Add( Object *pObject )
{
	m_pRoot->Add( pObject );
}

int Hikari::Scene::Add( Object *pObject, const std::string& nodeName )
{
	return m_pRoot->Add( pObject, nodeName );
}

void Hikari::Scene::Add( Node *pNode )
{
	m_pRoot->Add( pNode );
}

int Hikari::Scene::Add( Node *pNode, const std::string& nodeName )
{
	return m_pRoot->Add( pNode, nodeName );
}

int Hikari::Scene::RemoveObject( const std::string& ObjectName )
{
	return m_pRoot->RemoveObject( ObjectName );
}

int Hikari::Scene::RemoveNode( const std::string& NodeName )
{
	return m_pRoot->RemoveNode( NodeName );
}

Hikari::Node *Hikari::Scene::GetRootNode( void )
{
	return m_pRoot;
}

Hikari::ErrorCode Hikari::Scene::Load( const std::wstring& filename )
{
	return ErrorCode::NOT_IMPLEMENTED_YET;
}

const std::string& Hikari::Scene::GetID( void ) const
{
	return m_ID;
}

void Hikari::Scene::SetID( const std::string& newID )
{
	m_ID = newID;
}
