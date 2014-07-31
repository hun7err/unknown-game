#include "../../../../include/Core/Rendering/Camera/Camera.hpp"

Hikari::Camera::Camera()
{
	m_Position = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
}

DirectX::XMMATRIX Hikari::Camera::projectionMatrix(void)
{
	return m_ProjectionMatrix;
}

void Hikari::Camera::projectionMatrix(DirectX::XMMATRIX *pNewProjectionMatrix)
{
	m_ProjectionMatrix = *pNewProjectionMatrix;
}

DirectX::XMMATRIX Hikari::Camera::viewMatrix(void)
{
	return m_ViewMatrix;
}

void Hikari::Camera::viewMatrix(DirectX::XMMATRIX *pNewViewMatrix)
{
	m_ViewMatrix = *pNewViewMatrix;
}

DirectX::XMVECTOR Hikari::Camera::position(void)
{
	return m_Position;
}

void Hikari::Camera::move(DirectX::XMVECTOR *pNewPosition)
{
	m_Position = *pNewPosition;
}

void Hikari::Camera::move(float x, float y, float z)
{
	m_Position = DirectX::XMVectorSet(x, y, z, 1.0f);
}

float Hikari::Camera::pitch(void)
{
	return m_Pitch;
}

void Hikari::Camera::pitch(float pitch)
{
	m_Pitch = pitch;
}

float Hikari::Camera::yaw(void)
{
	return m_Yaw;
}

void Hikari::Camera::yaw(float yaw)
{
	m_Yaw = yaw;
}
