#include "../../../include/Core/Components/Transformation.hpp"
using namespace DirectX;

Hikari::Components::Transformation::Transformation( void ) : Component("Transformation")
{
	m_TransformationMatrix.value = XMMatrixIdentity();
}

void Hikari::Components::Transformation::Move( const DirectX::XMFLOAT3& translation )
{
	m_TransformationMatrix.value *= XMMatrixTranslation( translation.x, translation.y, translation.z );
}

void Hikari::Components::Transformation::Move( float x, float y, float z )
{
	m_TransformationMatrix.value *= XMMatrixTranslation( x, y, z );
}

void Hikari::Components::Transformation::Rotate( const DirectX::XMVECTOR& rotationAxis, float angle )
{
	m_TransformationMatrix.value *= XMMatrixRotationAxis( rotationAxis, angle );
}

void Hikari::Components::Transformation::RotateNormal( const DirectX::XMVECTOR& normalAxis, float angle )
{
	m_TransformationMatrix.value *= XMMatrixRotationNormal( normalAxis, angle );
}

void Hikari::Components::Transformation::RotateQuaternion( const DirectX::XMVECTOR& quaternion )
{
	m_TransformationMatrix.value *= XMMatrixRotationQuaternion( quaternion );
}

void Hikari::Components::Transformation::Scale( const DirectX::XMFLOAT3& vector )
{
	m_TransformationMatrix.value *= XMMatrixScaling( vector.x, vector.y, vector.z );
}

void Hikari::Components::Transformation::Scale( float x, float y, float z )
{
	m_TransformationMatrix.value *= XMMatrixScaling( x, y, z );
}

DirectX::XMMATRIX* Hikari::Components::Transformation::GetTransformationMatrixPointer( void )
{
	return & ( m_TransformationMatrix.value );
}

const DirectX::XMMATRIX& Hikari::Components::Transformation::GetTransformationMatrix( void ) const
{
	return m_TransformationMatrix.value;
}
