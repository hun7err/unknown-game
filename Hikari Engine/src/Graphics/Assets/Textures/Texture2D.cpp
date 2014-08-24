#include "../../../../include/Graphics/Assets/Textures/Texture2D.hpp"
#include <DirectXColors.h>
//#include <IL/ilu.h>

Hikari::Assets::Textures::Texture2D::Texture2D()
{
	m_pRenderTargetView = nullptr;
	m_pTexture = nullptr;
	m_ClearColor = DirectX::Colors::Black;
}

Hikari::Assets::Textures::Texture2D::~Texture2D(void)
{
	if(m_pTexture)
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
	}

	if(m_pShaderResourceView)
	{
		m_pShaderResourceView->Release();
		m_pShaderResourceView = nullptr;
	}
	
	if(m_pRenderTargetView)
	{
		m_pRenderTargetView->Release();
		m_pRenderTargetView = nullptr;
	}
}

Hikari::ErrorCode Hikari::Assets::Textures::Texture2D::Create( ID3D11Device *pDevice, int width, int height, D3D11_SUBRESOURCE_DATA *pInitialData )
{
	D3D11_TEXTURE2D_DESC description;
	ZeroMemory(&description, sizeof(description));

	description.Width = width;
	description.Height = height;
	description.MipLevels = 1;
	description.ArraySize = 1;
	description.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	description.SampleDesc.Count = 1;
	description.Usage = D3D11_USAGE_DEFAULT;
	description.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;

	if(FAILED(pDevice->CreateTexture2D( &description, pInitialData, &m_pTexture)))	// access violation
	{
		m_pTexture->Release();
		m_pTexture = nullptr;

		return ErrorCode::TEXTURE2D_CREATE_TEXTURE2D_FAILED;
	}

	D3D11_RENDER_TARGET_VIEW_DESC renderTargetViewDescription;
	renderTargetViewDescription.Format = description.Format;
	renderTargetViewDescription.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	renderTargetViewDescription.Texture2D.MipSlice = 0;

	if(FAILED(pDevice->CreateRenderTargetView(m_pTexture, &renderTargetViewDescription, &m_pRenderTargetView)))
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
		m_pRenderTargetView->Release();
		m_pRenderTargetView = nullptr;
		
		return ErrorCode::TEXTURE2D_CREATE_RENDER_TARGET_VIEW_FAILED;
	}

	D3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDescription;

	shaderResourceViewDescription.Format = description.Format;
	shaderResourceViewDescription.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	shaderResourceViewDescription.Texture2D.MostDetailedMip = 0;
	shaderResourceViewDescription.Texture2D.MipLevels = 1;

	if(FAILED(pDevice->CreateShaderResourceView(m_pTexture, &shaderResourceViewDescription, &m_pShaderResourceView)))
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
		m_pRenderTargetView->Release();
		m_pRenderTargetView = nullptr;
		m_pShaderResourceView->Release();
		m_pShaderResourceView = nullptr;

		return ErrorCode::TEXTURE2D_CREATE_SHADER_RESOURCE_VIEW_FAILED;
	}

	return ErrorCode::SUCCESS;
}

Hikari::ErrorCode Hikari::Assets::Textures::Texture2D::Create(ID3D11Device *pDevice, D3D11_TEXTURE2D_DESC *pDescription, D3D11_SUBRESOURCE_DATA *pInitialData, D3D11_RENDER_TARGET_VIEW_DESC *pRenderTargetViewDescription, D3D11_SHADER_RESOURCE_VIEW_DESC *pShaderResourceViewDescription)
{
	if(pDescription == nullptr)
	{
		return ErrorCode::TEXTURE2D_PDESCRIPTION_IS_NULL;
	}

	if(FAILED(pDevice->CreateTexture2D( pDescription, pInitialData, &m_pTexture)))
	{
		m_pTexture->Release();
		m_pTexture = nullptr;

		return ErrorCode::TEXTURE2D_CREATE_TEXTURE2D_FAILED;
	}

	if(pRenderTargetViewDescription != nullptr)
	{
		if(FAILED(pDevice->CreateRenderTargetView(m_pTexture, pRenderTargetViewDescription, &m_pRenderTargetView)))
		{
			m_pTexture->Release();
			m_pTexture = nullptr;
			m_pRenderTargetView->Release();
			m_pRenderTargetView = nullptr;
			
			return ErrorCode::TEXTURE2D_CREATE_RENDER_TARGET_VIEW_FAILED;
		}
	}
	else
	{
		D3D11_RENDER_TARGET_VIEW_DESC renderTargetViewDescription;
		renderTargetViewDescription.Format = pDescription->Format;
		renderTargetViewDescription.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
		renderTargetViewDescription.Texture2D.MipSlice = 0;

		if(FAILED(pDevice->CreateRenderTargetView(m_pTexture, &renderTargetViewDescription, &m_pRenderTargetView)))
		{
			m_pTexture->Release();
			m_pTexture = nullptr;
			m_pRenderTargetView->Release();
			m_pRenderTargetView = nullptr;
			
			return ErrorCode::TEXTURE2D_CREATE_RENDER_TARGET_VIEW_FAILED;
		}
	}

	if(pShaderResourceViewDescription != nullptr)
	{
		if(FAILED(pDevice->CreateShaderResourceView(m_pTexture, pShaderResourceViewDescription, &m_pShaderResourceView)))
		{
			m_pTexture->Release();
			m_pTexture = nullptr;
			m_pRenderTargetView->Release();
			m_pRenderTargetView = nullptr;
			m_pShaderResourceView->Release();
			m_pShaderResourceView = nullptr;
			
			return ErrorCode::TEXTURE2D_CREATE_SHADER_RESOURCE_VIEW_FAILED;
		}
	}
	else
	{
		D3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDescription;

		shaderResourceViewDescription.Format = pDescription->Format;
		shaderResourceViewDescription.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		shaderResourceViewDescription.Texture2D.MostDetailedMip = 0;
		shaderResourceViewDescription.Texture2D.MipLevels = 1;

		if(FAILED(pDevice->CreateShaderResourceView(m_pTexture, &shaderResourceViewDescription, &m_pShaderResourceView)))
		{
			m_pTexture->Release();
			m_pTexture = nullptr;
			m_pRenderTargetView->Release();
			m_pRenderTargetView = nullptr;
			m_pShaderResourceView->Release();
			m_pShaderResourceView = nullptr;
			
			return ErrorCode::TEXTURE2D_CREATE_SHADER_RESOURCE_VIEW_FAILED;
		}
	}

	return ErrorCode::SUCCESS;
}

ID3D11Texture2D *Hikari::Assets::Textures::Texture2D::GetTexturePointer(void)
{
	return m_pTexture;
}

ID3D11RenderTargetView *Hikari::Assets::Textures::Texture2D::GetRenderTargetView(void)
{
	return m_pRenderTargetView;
}

Hikari::ErrorCode Hikari::Assets::Textures::Texture2D::Load(const std::string& filename)
{
	//iluInit();

	ilGenImages(1, &m_ilImageName);	// generujemy nowy obraz ResILa
	ilBindImage(m_ilImageName);	// podpinamy go
	
	ILboolean result = ilLoadImage(filename.c_str());
	//ILboolean result = ilLoad(IL_JPG, filename.c_str());

	if(result == IL_FALSE)
	{
		ilDeleteImages(1, &m_ilImageName);	// sprz¹tamy po sobie

		return ErrorCode::TEXTURE2D_IL_LOAD_IMAGE_FAILED;
	}

	unsigned int width = ilGetInteger(IL_IMAGE_WIDTH),
				 height = ilGetInteger(IL_IMAGE_HEIGHT);
	
	result = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

	unsigned char* data = ilGetData();
	float* floatData = new float[4 * width * height];

	// przeliczamy char (0-255) na float (0-1)
	for(unsigned long currentPixel = 0; currentPixel < width*height*4; currentPixel++)
	{
		floatData[currentPixel] = (float)data[currentPixel]/255.0f;
	}

	D3D11_SUBRESOURCE_DATA textureImageData;

	textureImageData.pSysMem = floatData;
	textureImageData.SysMemPitch = width*4*sizeof(float);	// d³ugoœæ wiersza
	textureImageData.SysMemSlicePitch = 0;	// dotyczy tylko tekstur 3D, d³ugoœæ jednego poziomu (tekstury 2D)

	Create(m_pDevice, width, height, &textureImageData);

	ilDeleteImages(1, &m_ilImageName);	// sprz¹tamy po sobie
	delete [] floatData;

	return ErrorCode::SUCCESS;
}

void Hikari::Assets::Textures::Texture2D::SetDevicePointer( ID3D11Device *pDevice )
{
	m_pDevice = pDevice;
}

const DirectX::XMVECTORF32& Hikari::Assets::Textures::Texture2D::GetClearColor( void ) const
{
	return m_ClearColor;
}

void Hikari::Assets::Textures::Texture2D::SetClearColor( const DirectX::XMVECTORF32& newClearColor )
{
	m_ClearColor = newClearColor;
}
