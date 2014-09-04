#include "../../include/Core/Engine.hpp"
#include "../../include/Windowing/WindowingSystem.hpp"
#include "../../include/Graphics/GraphicsSystem.hpp"

#include "../../include/Graphics/Assets/Geometry/Triangle.hpp"
#include "../../include/Graphics/Assets/Textures/Texture2D.hpp"
#include "../../include/Graphics/Assets/Material.hpp"

#include "../../include/Graphics/Assets/ShaderProgram.hpp"
#include "../../include/Graphics/Shaders/VertexShader.hpp"
#include "../../include/Graphics/Shaders/PixelShader.hpp"

#include "../../include/Graphics/Shaders/Input/ModelViewProjection.hpp"
#include "../../include/Graphics/Shaders/Input/Texture.hpp"
#include "../../include/Graphics/Shaders/Input/Position.hpp"

int WINAPI WinMain( HINSTANCE InstanceHandle, HINSTANCE PreviousInstanceHandle, LPSTR lpCmdLine, int nCmdShow )
{
	Hikari::Engine *pEngine = new Hikari::Engine();
	pEngine->Initialize( InstanceHandle, nCmdShow, lpCmdLine );

	Hikari::WindowingSystem *pWindowingSystem = new Hikari::WindowingSystem();
	Hikari::GraphicsSystem *pGraphicsSystem = new Hikari::GraphicsSystem();

	// wyrzuciæ namespace'y jak Assets:: albo Components:: i zamiast tego daæ np. Vector4Component itp.
	// kamery
	// sprawdziæ wszystko
	// position do VertexPosition w Input
	Hikari::Assets::Textures::Texture2D *pTexture = new Hikari::Assets::Textures::Texture2D( "Marble" );
	pTexture->Component::SetID( "DiffuseTexture" );
	pTexture->Load( "resources/textures/black_marble.jpg" );

	Hikari::Assets::Material *pMaterial = new Hikari::Assets::Material( );
	pMaterial->AddComponent( pTexture );

	Hikari::Assets::ShaderProgram *pShaderProgram = new Hikari::Assets::ShaderProgram( "SimplestEver" );
	Hikari::Shaders::VertexShader VS;
	Hikari::Shaders::PixelShader PS;

	Hikari::Shaders::Input::Texture texture( "DiffuseTexture" );
	Hikari::Shaders::Input::Position position;
	Hikari::Shaders::Input::ModelViewProjection mvp;

	VS.GetShaderInput()->AddComponent( &position );
	VS.GetShaderInput()->AddComponent( &mvp );

	PS.GetShaderInput()->AddComponent( &texture );

	pShaderProgram->AddComponent( &VS );
	pShaderProgram->AddComponent( &PS );
	
	// w którym momencie jest kompilowane shaderprogram?

	pMaterial->AddComponent( pShaderProgram );

	Hikari::Geometry::Triangle *pTriangleGeometry = new Hikari::Geometry::Triangle(
			"triangle",
			Hikari::Vector3( 0.0f, 0.5f, 1.0f ),
			Hikari::Vector3( 0.55f, -0.5f, 1.0f ),
			Hikari::Vector3( -0.55f, -0.5f, 1.0f )
		);

	Hikari::Object *pTriangle = new Hikari::Object( "triangle" );
	pTriangle->AddComponent( pTriangleGeometry );

	pEngine->GetWorld()->GetActiveScene()->Add( *pTriangle );	// zmieniæ referencjê na Object*

	pEngine->Add(pWindowingSystem);
	pEngine->Add(pGraphicsSystem);

	pEngine->MainLoop();
	
	delete pTexture;	// potrzebne?
	delete pWindowingSystem;
	delete pGraphicsSystem;
	delete pEngine;

	return 0;
}
