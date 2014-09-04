#include "../../../include/Graphics/Renderers/BasicRenderer.hpp"
#include "../../../include/Graphics/Assets/Geometry/Geometry.hpp"
#include "../../../include/Graphics/Assets/Material.hpp"
#include "../../../include/Graphics/Assets/ShaderProgram.hpp"
#include "../../../include/Core/Components/Transformation.hpp"

#include "../../../include/Graphics/Shaders/ComputeShader.hpp"
#include "../../../include/Graphics/Shaders/DomainShader.hpp"
#include "../../../include/Graphics/Shaders/GeometryShader.hpp"
#include "../../../include/Graphics/Shaders/HullShader.hpp"
#include "../../../include/Graphics/Shaders/PixelShader.hpp"
#include "../../../include/Graphics/Shaders/VertexShader.hpp"

#include "../../../include/Graphics/Shaders/Input/ModelViewProjection.hpp"
#include <DirectXMath.h>

Hikari::BasicRenderer::BasicRenderer( void )
{
	m_RenderTargetCount = 1;

	m_pRenderTargetViews = new ID3D11RenderTargetView*  [ m_RenderTargetCount ];
	m_pViewports = new D3D11_VIEWPORT  [ m_RenderTargetCount ];
	m_pTextures = new Assets::Textures::Texture2D  [ m_RenderTargetCount ];

	m_pTextures[0].Asset::SetID("BackBuffer");
}

Hikari::BasicRenderer::~BasicRenderer( void )
{
	delete [] m_pRenderTargetViews;
	m_pRenderTargetViews = nullptr;
	delete [] m_pTextures;
	m_pTextures = nullptr;
	delete [] m_pViewports;
	m_pViewports = nullptr;
}

int Hikari::BasicRenderer::Init( ID3D11Device *pDevice, unsigned int width, unsigned int height )
{
	m_pTextures[0].Create( pDevice, width, height );
	
	ZeroMemory(m_pViewports, sizeof(D3D11_VIEWPORT));
	m_pViewports[0].TopLeftX = 0;
	m_pViewports[0].TopLeftY = 0;
	m_pViewports[0].Height = (float)height;
	m_pViewports[0].Width = (float)width;

	m_pRenderTargetViews[0] = m_pTextures[0].GetRenderTargetView();

	return 0;
}

void Hikari::BasicRenderer::Render( ID3D11DeviceContext *pDeviceContext, IDXGISwapChain *pSwapChain, Scene *pScene )
{
	pDeviceContext->OMSetRenderTargets( m_RenderTargetCount, m_pRenderTargetViews, nullptr );
	pDeviceContext->RSSetViewports( m_RenderTargetCount, m_pViewports );

	for( unsigned int currentRenderTarget = 0; currentRenderTarget < m_RenderTargetCount; ++currentRenderTarget )
	{
		pDeviceContext->ClearRenderTargetView( m_pRenderTargetViews[ currentRenderTarget ], m_pTextures[ currentRenderTarget ].GetClearColor() );
	}

	DirectX::XMMATRIX transformation = DirectX::XMMatrixIdentity( );

	std::vector<Node> nodes = pScene->GetRootNode().GetChildrenNodes();

	m_pActiveCamera = pScene->GetActiveCamera( );
	Draw( pDeviceContext, nodes, transformation );

	//std::vector<Object> objects = pScene->GetRootNode().GetChildrenObjects();

	/*for( auto object = objects.begin(); object != objects.end(); ++object )
	{
		
	}*/

	// tutaj draw() obiektów, czyli draw() na root node

	pSwapChain->Present( 0, 0 );
}

void Hikari::BasicRenderer::Draw( ID3D11DeviceContext *pDeviceContext, const std::vector< Node >& nodes, DirectX::XMMATRIX& transformation )
{
	for( auto node = nodes.begin(); node != nodes.end(); ++node )
	{
		const std::vector< Object >& childrenObjects = node->GetChildrenObjects();

		for( auto object = childrenObjects.begin(); object != childrenObjects.end(); ++object )
		{
			Draw( pDeviceContext, *object, transformation );
		}

		const std::vector< Node >& childrenNodes = node->GetChildrenNodes();

		if( ! childrenNodes.empty() )
		{
			Components::Transformation *pTransformation = ( Components::Transformation* )node->GetComponent("Transformation");
			
			DirectX::XMMATRIX nodeTransformation = pTransformation->GetTransformationMatrix();

			transformation *= nodeTransformation;

			Draw( pDeviceContext, childrenNodes, transformation );
		}
		

	}
}

void Hikari::BasicRenderer::Draw( ID3D11DeviceContext *pDeviceContext, const Object& object, const DirectX::XMMATRIX& transformation )
{
	Assets::Geometry *pGeometry;
	Assets::Material *pMaterial;
	Assets::ShaderProgram *pShaderProgram;
	
	Shaders::ComputeShader *pComputeShader;
	Shaders::DomainShader *pDomainShader;
	Shaders::GeometryShader *pGeometryShader;
	Shaders::HullShader *pHullShader;
	Shaders::PixelShader *pPixelShader;
	Shaders::VertexShader *pVertexShader;
	Components::Transformation *pTransformation;

	pGeometry = ( Assets::Geometry* ) ( object.GetComponent("Geometry") );
	pMaterial = ( Assets::Material* ) ( object.GetComponent("Material") );
		
	if( pGeometry != nullptr && pMaterial != nullptr )
	{
		pShaderProgram = ( Assets::ShaderProgram* )pMaterial->GetComponent("ShaderProgram");

		pComputeShader = ( Shaders::ComputeShader* )pShaderProgram->GetComponent( "ComputeShader" );
		pDomainShader = ( Shaders::DomainShader* )pShaderProgram->GetComponent( "DomainShader" );
		pGeometryShader = ( Shaders::GeometryShader* )pShaderProgram->GetComponent( "GeometryShader" );
		pHullShader = ( Shaders::HullShader* )pShaderProgram->GetComponent( "HullShader" );
		pPixelShader = ( Shaders::PixelShader* )pShaderProgram->GetComponent( "PixelShader" );
		pVertexShader = ( Shaders::VertexShader* )pShaderProgram->GetComponent( "VertexShader" );
		
		pTransformation = ( Components::Transformation* )object.GetComponent("Transformation");
		DirectX::XMMATRIX objectTransformation = pTransformation->GetTransformationMatrix() * transformation;

		unsigned int offset, stride;

		offset = 0;
		stride = sizeof(Vertex);

		pDeviceContext->IASetVertexBuffers(
											0,
											1,
											pGeometry->GetVertexBufferPointer(),
											&stride,
											&offset
										);
		pDeviceContext->IASetIndexBuffer(
											pGeometry->GetIndexBuffer(),
											DXGI_FORMAT_R32_UINT,
											0
										);
		pDeviceContext->IASetPrimitiveTopology( pGeometry->GetPrimitiveTopology() );

		if( pComputeShader != nullptr )
		{
			pDeviceContext->CSSetShader( pComputeShader->GetShaderPointer(), nullptr, 0 );
			
			// CSSetSamplers
			// CSSetShaderResources
			// CSSetConstantBuffers
		}

		if( pDomainShader != nullptr )
		{
			pDeviceContext->DSSetShader( pDomainShader->GetShaderPointer(), nullptr, 0 );
		}

		if( pGeometryShader != nullptr )
		{
			pDeviceContext->GSSetShader( pGeometryShader->GetShaderPointer(), nullptr, 0 );
		}

		if( pHullShader != nullptr )
		{
			pDeviceContext->HSSetShader( pHullShader->GetShaderPointer(), nullptr, 0 );
		}

		if( pPixelShader != nullptr )
		{
			pDeviceContext->PSSetShader( pPixelShader->GetShaderPointer(), nullptr, 0 );
			// PSSetSamplers
			// PSSetShaderResources
			// PSSetConstantBuffers
		}

		if( pVertexShader != nullptr )
		{
			Shaders::Input::ModelViewProjection *pMVP = ( Shaders::Input::ModelViewProjection* ) pVertexShader->GetShaderInput( )->GetComponent( "ModelViewProjection" );
			
			if( pMVP != nullptr )
			{
				D3D11_MAPPED_SUBRESOURCE mappedSubResource;
				Shaders::Input::MVP_Type* dataPtr;
				unsigned int cBufferId = 0;
				ID3D11Buffer *pMatrixBuffer = pMVP->GetMatrixBuffer( );

				pDeviceContext->Map(
					pMatrixBuffer,
					0,
					D3D11_MAP_WRITE_DISCARD,
					0,
					&mappedSubResource
				);

				dataPtr = ( Shaders::Input::MVP_Type* ) mappedSubResource.pData;

				dataPtr->ModelMatrix = pTransformation->GetTransformationMatrix( ) * transformation;
				dataPtr->ProjectionMatrix = m_pActiveCamera->GetProjectionMatrix( );
				dataPtr->ViewMatrix = m_pActiveCamera->GetViewMatrix( );

				pDeviceContext->Unmap( pMatrixBuffer, 0 );

				pDeviceContext->VSSetConstantBuffers( cBufferId, 1, &pMatrixBuffer );
			}

			pDeviceContext->VSSetShader( pVertexShader->GetShaderPointer(), nullptr, 0 );
			pDeviceContext->IASetInputLayout( pVertexShader->GetShaderInput()->GetInputLayout() );
		}

		//

		pDeviceContext->DrawIndexed( pGeometry->GetIndexCount(), 0, 0 );
	}
}
