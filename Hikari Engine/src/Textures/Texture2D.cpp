#include "../../include/Textures/Texture2D.hpp"
#include "../../include/Engine.hpp"
#include "../../include/Exception.hpp"
#include <IL/ilu.h>

Hikari::Texture2D::Texture2D()
{
	m_pRenderTargetView = nullptr;
	m_pTexture = nullptr;
}

void Hikari::Texture2D::create(int width, int height, D3D11_SUBRESOURCE_DATA *pInitialData)
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

	if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateTexture2D( &description, pInitialData, &m_pTexture)))	// access violation
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
		throw Exception("Could not create texture in Hikari::Texture2D::create(int, int)", "TextureCreationException");
	}

	D3D11_RENDER_TARGET_VIEW_DESC renderTargetViewDescription;
	renderTargetViewDescription.Format = description.Format;
	renderTargetViewDescription.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	renderTargetViewDescription.Texture2D.MipSlice = 0;

	if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateRenderTargetView(m_pTexture, &renderTargetViewDescription, &m_pRenderTargetView)))
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
		m_pRenderTargetView->Release();
		m_pRenderTargetView = nullptr;
		throw Exception("Could not create render target view in Hikari::Texture2D::create(int, int)", "TextureCreationException");
	}

	D3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDescription;

	shaderResourceViewDescription.Format = description.Format;
	shaderResourceViewDescription.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	shaderResourceViewDescription.Texture2D.MostDetailedMip = 0;
	shaderResourceViewDescription.Texture2D.MipLevels = 1;

	if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateShaderResourceView(m_pTexture, &shaderResourceViewDescription, &m_pShaderResourceView)))
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
		m_pRenderTargetView->Release();
		m_pRenderTargetView = nullptr;
		m_pShaderResourceView->Release();
		m_pShaderResourceView = nullptr;
		throw Exception("Could not create shader resource view in Hikari::Texture2D::create(int, int)", "TextureCreationException");
	}
}

void Hikari::Texture2D::create(D3D11_TEXTURE2D_DESC *pDescription, D3D11_SUBRESOURCE_DATA *pInitialData, D3D11_RENDER_TARGET_VIEW_DESC *pRenderTargetViewDescription, D3D11_SHADER_RESOURCE_VIEW_DESC *pShaderResourceViewDescription)
{
	if(pDescription == nullptr)
	{
		throw Exception("pDescription cannot be nullptr in Hikari::Texture2D::create(D3D11_TEXTURE2D_DESC*,D3D11_RENDER_TARGET_VIEW_DESC*,D3D11_SHADER_RESOURCE_VIEW_DESC*)", "TextureCreationException");
	}

	if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateTexture2D( pDescription, pInitialData, &m_pTexture)))
	{
		m_pTexture->Release();
		m_pTexture = nullptr;
		throw Exception("Could not create texture in Hikari::Texture2D::create(D3D11_TEXTURE2D_DESC*,D3D11_RENDER_TARGET_VIEW_DESC*,D3D11_SHADER_RESOURCE_VIEW_DESC*)", "TextureCreationException");
	}

	if(pRenderTargetViewDescription != nullptr)
	{
		if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateRenderTargetView(m_pTexture, pRenderTargetViewDescription, &m_pRenderTargetView)))
		{
			m_pTexture->Release();
			m_pTexture = nullptr;
			m_pRenderTargetView->Release();
			m_pRenderTargetView = nullptr;
			throw Exception("Could not create render target view in Hikari::Texture2D::create(D3D11_TEXTURE2D_DESC*,D3D11_RENDER_TARGET_VIEW_DESC*,D3D11_SHADER_RESOURCE_VIEW_DESC*)", "TextureCreationException");
		}
	}
	else
	{
		D3D11_RENDER_TARGET_VIEW_DESC renderTargetViewDescription;
		renderTargetViewDescription.Format = pDescription->Format;
		renderTargetViewDescription.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
		renderTargetViewDescription.Texture2D.MipSlice = 0;

		if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateRenderTargetView(m_pTexture, &renderTargetViewDescription, &m_pRenderTargetView)))
		{
			m_pTexture->Release();
			m_pTexture = nullptr;
			m_pRenderTargetView->Release();
			m_pRenderTargetView = nullptr;
			throw Exception("Could not create render target view in Hikari::Texture2D::create(D3D11_TEXTURE2D_DESC*,D3D11_RENDER_TARGET_VIEW_DESC*,D3D11_SHADER_RESOURCE_VIEW_DESC*)", "TextureCreationException");
		}
	}

	if(pShaderResourceViewDescription != nullptr)
	{
		if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateShaderResourceView(m_pTexture, pShaderResourceViewDescription, &m_pShaderResourceView)))
		{
			m_pTexture->Release();
			m_pTexture = nullptr;
			m_pRenderTargetView->Release();
			m_pRenderTargetView = nullptr;
			m_pShaderResourceView->Release();
			m_pShaderResourceView = nullptr;
			throw Exception("Could not create shader resource view in Hikari::Texture2D::create(D3D11_TEXTURE2D_DESC*,D3D11_RENDER_TARGET_VIEW_DESC*,D3D11_SHADER_RESOURCE_VIEW_DESC*)", "TextureCreationException");
		}
	}
	else
	{
		D3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDescription;

		shaderResourceViewDescription.Format = pDescription->Format;
		shaderResourceViewDescription.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		shaderResourceViewDescription.Texture2D.MostDetailedMip = 0;
		shaderResourceViewDescription.Texture2D.MipLevels = 1;

		if(FAILED(Hikari::Engine::d3dsystem()->device()->CreateShaderResourceView(m_pTexture, &shaderResourceViewDescription, &m_pShaderResourceView)))
		{
			m_pTexture->Release();
			m_pTexture = nullptr;
			m_pRenderTargetView->Release();
			m_pRenderTargetView = nullptr;
			m_pShaderResourceView->Release();
			m_pShaderResourceView = nullptr;
			throw Exception("Could not create shader resource view in Hikari::Texture2D::create(D3D11_TEXTURE2D_DESC*,D3D11_RENDER_TARGET_VIEW_DESC*,D3D11_SHADER_RESOURCE_VIEW_DESC*)", "TextureCreationException");
		}
	}
}

ID3D11Texture2D *Hikari::Texture2D::dxTexture(void)
{
	return m_pTexture;
}

ID3D11RenderTargetView *Hikari::Texture2D::renderTargetView(void)
{
	return m_pRenderTargetView;
}

#include <Windows.h>
void Hikari::Texture2D::load(std::string filename)
{
	iluInit();

	ilGenImages(1, &m_ilImageName);	// generujemy nowy obraz ResILa
	ilBindImage(m_ilImageName);	// podpinamy go
	
	ILboolean result = ilLoadImage(filename.c_str());
	//ILboolean result = ilLoad(IL_JPG, filename.c_str());

	if(result == IL_FALSE)
	{
		std::string message("Could not load image file \"");
		message.append(filename);
		message.append("\" in Hikari::Texture2D::load(std::string), DevIL error: ");
		ILenum error;
		do
		{
			error = ilGetError();
			message.append(iluErrorString(error));
			message.append("("+std::to_string(error)+")");
		} while(error != IL_NO_ERROR);

		char* cmessage = new char[message.size()+1];
		ZeroMemory(cmessage, message.size()+1);
		CopyMemory(cmessage, message.c_str(), message.size()+1);

		ilDeleteImages(1, &m_ilImageName);	// sprz¹tamy po sobie

		throw Exception(cmessage, "ResILException");
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

	create(width, height, &textureImageData);

	ilDeleteImages(1, &m_ilImageName);	// sprz¹tamy po sobie
	delete [] floatData;
}

void Hikari::Texture2D::cleanup(void)
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
