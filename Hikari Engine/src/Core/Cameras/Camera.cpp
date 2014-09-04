#include "../../../include/Core/Cameras/Camera.hpp"

Hikari::Camera::Camera( void ) : Actor( )
{
	m_Matrices.ProjectionMatrix = DirectX::XMMatrixIdentity( );
}

Hikari::Camera::Camera( const std::string& ID ) : Actor( ID )
{
	m_Matrices.ViewMatrix = DirectX::XMMatrixIdentity( );
}

const DirectX::XMMATRIX& Hikari::Camera::GetProjectionMatrix( void ) const
{
	return m_Matrices.ProjectionMatrix;
}

void Hikari::Camera::SetProjectionMatrix( const DirectX::XMMATRIX& projectionMatrix )
{
	m_Matrices.ProjectionMatrix = projectionMatrix;
}

const DirectX::XMMATRIX& Hikari::Camera::GetViewMatrix( void ) const
{
	return m_Matrices.ViewMatrix;
}

void Hikari::Camera::SetViewMatrix( const DirectX::XMMATRIX& viewMatrix )
{
	m_Matrices.ViewMatrix = viewMatrix;
}
