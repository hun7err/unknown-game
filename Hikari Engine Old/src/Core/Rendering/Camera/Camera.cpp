#include "../../../../include/Core/Rendering/Camera/Camera.hpp"

Hikari::Camera::Camera()
{
	m_Position.x = m_Position.y = m_Position.z;
	m_Position.w = 1.0f;
}

DirectX::XMFLOAT4X4 Hikari::Camera::projectionMatrix(void)
{
	return m_ProjectionMatrix;
}

void Hikari::Camera::projectionMatrix(DirectX::XMFLOAT4X4 newProjectionMatrix)
{
	m_ProjectionMatrix = newProjectionMatrix;
}

DirectX::XMFLOAT4X4 Hikari::Camera::viewMatrix(void)
{
	return m_ViewMatrix;
}

void Hikari::Camera::viewMatrix(DirectX::XMFLOAT4X4 newViewMatrix)
{
	m_ViewMatrix = newViewMatrix;
}

DirectX::XMFLOAT4 Hikari::Camera::position(void)
{
	return m_Position;
}

void Hikari::Camera::moveTo(DirectX::XMFLOAT4 newPosition)
{
	m_Position = newPosition;
}

void Hikari::Camera::moveTo(float x, float y, float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
	m_Position.w = 1.0f;
}

void Hikari::Camera::moveBy(float dx, float dy, float dz)
{
	m_Position.x += dx;
	m_Position.y += dy;
	m_Position.z += dz;
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
