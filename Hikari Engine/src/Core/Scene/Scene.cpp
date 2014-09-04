#include "../../../include/Core/Scene/Scene.hpp"

Hikari::Scene::Scene( void ) : m_Root( "Root" ), m_pActiveCamera( nullptr )
{
}

Hikari::Scene::Scene( const std::string& sceneID ) : m_ID( sceneID ), m_Root( "Root" ), m_pActiveCamera( nullptr )
{
}

Hikari::Scene::~Scene( void )
{
}

void Hikari::Scene::SetActiveCamera( Camera *pCamera )
{
	m_pActiveCamera = pCamera;
}

Hikari::Camera* Hikari::Scene::GetActiveCamera( void )
{
	return m_pActiveCamera;
}

void Hikari::Scene::Add( const Object& object )
{
	m_Root.Add( object );
}

int Hikari::Scene::Add( const Object& object, const std::string& nodeName )
{
	return m_Root.Add( object, nodeName );
}

void Hikari::Scene::Add( const Node& node )
{
	m_Root.Add( node );
}

int Hikari::Scene::Add( const Node& node, const std::string& nodeName )
{
	return m_Root.Add( node, nodeName );
}

int Hikari::Scene::RemoveObject( const std::string& ObjectName )
{
	return m_Root.RemoveObject( ObjectName );
}

int Hikari::Scene::RemoveNode( const std::string& NodeName )
{
	return m_Root.RemoveNode( NodeName );
}

Hikari::Node& Hikari::Scene::GetRootNode( void )
{
	return m_Root;
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
