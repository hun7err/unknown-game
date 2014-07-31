#define _USE_MATH_DEFINES
#include <cmath>

#include "../../../../include/Core/Rendering/Camera/FirstPersonCamera.hpp"
#include "../../../../include/Core/Engine/Engine.hpp"

#include <DirectXMath.h>
#include <DirectXPackedVector.h>
using namespace DirectX;

Hikari::Cameras::FirstPersonCamera::FirstPersonCamera() : Camera()
{
	m_phEventHandler = new HEventHandler(Hikari::Event::MouseMove);

	m_moveLeftRight = 0.0f;
	m_moveBackForward = 0.0f;
	m_Yaw = 0.0f;
	m_Pitch = 0.0f;

	m_defaultForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	m_defaultRight = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	m_camForward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	m_camRight = XMVectorSet(1.0f,0.0f,0.0f,0.0f);
	m_camUp = XMVectorSet(0.0f,1.0f,0.0f,0.0f);
	m_Target = XMVectorSet(0.0f,0.0f,0.0f,0.0f);

	m_Position = XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);

	m_ProjectionMatrix = XMMatrixPerspectiveFovLH(0.4f * M_PI, (float)Engine::window()->width() / Engine::window()->height(), 1.0f, 1000.0f);
}

Hikari::Cameras::FirstPersonCamera::~FirstPersonCamera()
{
	delete m_phEventHandler;
}

void Hikari::Cameras::FirstPersonCamera::tick(void)
{
	m_camRotationMatrix = XMMatrixRotationRollPitchYaw(m_Pitch, m_Yaw, 0);
	m_Target = XMVector3TransformCoord(m_defaultForward, m_camRotationMatrix);
	m_Target = XMVector3Normalize(m_Target);

	XMMATRIX RotateYTempMatrix;
	RotateYTempMatrix = XMMatrixRotationY(m_Pitch);

	m_camRight = XMVector3TransformCoord(m_defaultRight, RotateYTempMatrix);
	m_camUp = XMVector3TransformCoord(m_camUp, RotateYTempMatrix);
	m_camForward = XMVector3TransformCoord(m_defaultForward, RotateYTempMatrix);

	m_Position += m_moveLeftRight * m_camRight;
	m_Position += m_moveBackForward * m_camForward;

	m_moveLeftRight = 0.0f;
	m_moveBackForward = 0.0f;

	m_Target = XMVectorAdd(m_Position, m_Target);

	m_ViewMatrix = XMMatrixLookAtLH(m_Position, m_Target, m_camUp);
}

void Hikari::Cameras::FirstPersonCamera::setBindings(void)
{
	m_mouseMoveHandler.handlerFunction([](int dx, int dy) {
		float yaw = Hikari::Engine::camera()->yaw(),
			pitch = Hikari::Engine::camera()->pitch();

		yaw += dx * 0.001f;
		pitch += dy * 0.001f;

		Hikari::Engine::camera()->yaw(yaw);
		Hikari::Engine::camera()->pitch(pitch);
	});
	*m_phEventHandler = Hikari::Engine::eventHandlers()->add(&m_mouseMoveHandler);
}

void Hikari::Cameras::FirstPersonCamera::disableBindigs(void)
{
	Hikari::Engine::eventHandlers()->remove(*m_phEventHandler);
}
