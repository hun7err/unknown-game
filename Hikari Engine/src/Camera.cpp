#include "../include/Camera.hpp"

DirectX::XMMATRIX Hikari::Camera::projectionMatrix(void)
{
	return m_ProjectionMatrix;
}

void Hikari::Camera::projectionMatrix(DirectX::XMMATRIX *newProjectionMatrix)
{
	m_ProjectionMatrix = *newProjectionMatrix;
}
