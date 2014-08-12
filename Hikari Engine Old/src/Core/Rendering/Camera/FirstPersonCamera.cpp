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

	XMStoreFloat4(&m_defaultForward, XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f));
	XMStoreFloat4(&m_defaultRight, XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f));
	XMStoreFloat4(&m_camForward, XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f));
	XMStoreFloat4(&m_camRight, XMVectorSet(1.0f,0.0f,0.0f,0.0f));
	XMStoreFloat4(&m_camUp, XMVectorSet(0.0f,1.0f,0.0f,0.0f));
	XMStoreFloat4(&m_Target, XMVectorSet(0.0f,0.0f,0.0f,1.0f));
	XMStoreFloat4(&m_Position, XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f));

	//XMStoreFloat4x4(&m_ProjectionMatrix, XMMatrixIdentity());
	
	//XMStoreFloat4x4(&m_ProjectionMatrix, XMMatrixOrthographicLH(1.0f, 1.0f, 0.0f, 1.0f));
	// kiedy zmieniê na to, trójk¹t w ogóle siê nie wyœwietla

	XMStoreFloat4x4(&m_ProjectionMatrix, XMMatrixPerspectiveFovLH(0.4f * M_PI, (float)Engine::window()->width() / Engine::window()->height(), 0.1f, 1000.0f));
}

Hikari::Cameras::FirstPersonCamera::~FirstPersonCamera()
{
	delete m_phEventHandler;
}

void Hikari::Cameras::FirstPersonCamera::tick(void)
{
	XMStoreFloat4x4(&m_camRotationMatrix, XMMatrixRotationRollPitchYaw(m_Pitch, m_Yaw, 0));
	XMStoreFloat4(&m_Target, XMVector3TransformCoord(XMLoadFloat4(&m_defaultForward), XMLoadFloat4x4(&m_camRotationMatrix)));
	XMStoreFloat4(&m_Target, XMVector3Normalize(XMLoadFloat4(&m_Target)));

	XMMATRIX RotateYTempMatrix;
	RotateYTempMatrix = XMMatrixRotationY(m_Pitch);

	XMStoreFloat4(&m_camRight, XMVector3TransformCoord(XMLoadFloat4(&m_defaultRight), RotateYTempMatrix));
	XMStoreFloat4(&m_camUp, XMVector3TransformCoord(XMLoadFloat4(&m_camUp), RotateYTempMatrix));
	XMStoreFloat4(&m_camForward, XMVector3TransformCoord(XMLoadFloat4(&m_defaultForward), RotateYTempMatrix));

	XMFLOAT4 result;
	XMStoreFloat4(&result, m_moveLeftRight * XMLoadFloat4(&m_camRight));
	m_Position.x += result.x;
	m_Position.y += result.y;
	m_Position.z += result.z;
	XMStoreFloat4(&result, m_moveBackForward * XMLoadFloat4(&m_camForward));
	m_Position.x += result.x;
	m_Position.y += result.y;
	m_Position.z += result.z;

	m_moveLeftRight = 0.0f;
	m_moveBackForward = 0.0f;

	XMStoreFloat4(&m_Target, XMVectorAdd(XMLoadFloat4(&m_Position), XMLoadFloat4(&m_Target)));

	//XMStoreFloat4x4(&m_ViewMatrix, XMMatrixIdentity());
	XMStoreFloat4x4(&m_ViewMatrix, XMMatrixLookAtLH(XMLoadFloat4(&m_Position), XMLoadFloat4(&m_Target), XMLoadFloat4(&m_camUp)));
}

void Hikari::Cameras::FirstPersonCamera::setBindings(void)
{
	m_mouseMoveHandler.handlerFunction([](int dx, int dy) {
		float yaw = Hikari::Engine::camera()->yaw(),
			pitch = Hikari::Engine::camera()->pitch();

		yaw += dx * 0.01f;
		pitch += dy * 0.01f;

		Hikari::Engine::camera()->yaw(yaw);
		Hikari::Engine::camera()->pitch(pitch);
	});
	//*m_phEventHandler = Hikari::Engine::eventHandlers()->add(&m_mouseMoveHandler);
}

void Hikari::Cameras::FirstPersonCamera::disableBindigs(void)
{
	//Hikari::Engine::eventHandlers()->remove(*m_phEventHandler);
}
