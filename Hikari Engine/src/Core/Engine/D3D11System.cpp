#include "../../../include/Core/Engine/D3D11System.hpp"
#include "../../../include/Helpers/Exception.hpp"

void Hikari::D3D11System::setup(HWND windowHandle, bool fullscreen, int width, int height, int sampleCount = 1)
{
	DXGI_SWAP_CHAIN_DESC swapChainDescription;
	ZeroMemory(&swapChainDescription, sizeof(DXGI_SWAP_CHAIN_DESC));

	swapChainDescription.BufferCount = 1;	// do ewentualnej poprawy, nei jestem pewien czy tak mo¿e byæ
	swapChainDescription.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDescription.BufferDesc.Width = width;
	swapChainDescription.BufferDesc.Height = height;
	swapChainDescription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDescription.OutputWindow = windowHandle;
	swapChainDescription.SampleDesc.Count = sampleCount;
	swapChainDescription.Windowed = !fullscreen;
	swapChainDescription.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	/*D3D_FEATURE_LEVEL featureLevels[]={
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_9_3,
    };
    unsigned int featuresSize = ARRAYSIZE(featureLevels);*/

	// to-do:
	// opisaæ tutaj parametry D3D11CreateDeviceAndSwapChain

	if(FAILED(D3D11CreateDeviceAndSwapChain(	nullptr,
									D3D_DRIVER_TYPE_HARDWARE,
									nullptr,
									0,
									nullptr,//featureLevels,
									0,//featuresSize,
									D3D11_SDK_VERSION,
									&swapChainDescription,
									&m_pSwapChain,
									&m_pDevice,
									nullptr,
									&m_pDeviceContext
								)))
	{
		throw Exception("D3D11CreateDeviceAndSwapChain failed in D3D11System::setup()", "NullPointerException");
	}
}

void Hikari::D3D11System::cleanup(void)
{
	m_pSwapChain->Release();
	m_pSwapChain = nullptr;
	m_pDevice->Release();
	m_pDevice = nullptr;
	m_pDeviceContext->Release();
	m_pDeviceContext = nullptr;
}

IDXGISwapChain* Hikari::D3D11System::swapChain(void)
{
	if(m_pSwapChain == nullptr)
	{
		throw Exception("m_pSwapChain is not initialized in Hikari::D3D11System::swapChain(void)", "NullPointerException");
	}

	return m_pSwapChain;
}

void Hikari::D3D11System::swapChain(IDXGISwapChain* pSwapChain)
{
	if(m_pSwapChain == nullptr)
	{
		throw Exception("m_pSwapChain is not initialized in Hikari::D3D11System::swapChain(IDXGISwapChain*)", "NullPointerException");
	}

	if(pSwapChain == nullptr)
	{
		throw Exception("Can't set m_pSwapChain to a nullptr pointer in Hikari::D3D11System::swapChain(IDXGISwapChain*)", "NullPointerException");
	}

	m_pSwapChain = pSwapChain;
}

ID3D11Device* Hikari::D3D11System::device(void)
{
	if(m_pDevice == nullptr)
	{
		throw Exception("m_pDevice is not initialized in Hikari::D3D11System::device(void)", "NullPointerException");
	}

	return m_pDevice;
}

void Hikari::D3D11System::device(ID3D11Device* pDevice)
{
	if(m_pDevice == nullptr)
	{
		throw Exception("m_pDevice is not initialized in Hikari::D3D11System::device(ID3D11Device*)", "NullPointerException");
	}

	if(pDevice == nullptr)
	{
		throw Exception("Can't set m_pDevice to a nullptr pointer in Hikari::D3D11System::device(ID3D11Device*)", "NullPointerException");
	}

	m_pDevice = pDevice;
}

ID3D11DeviceContext* Hikari::D3D11System::deviceContext(void)
{
	if(m_pDeviceContext == nullptr)
	{
		throw Exception("m_pDeviceContext is not initialized in Hikari::D3D11System::deviceContext(void)", "NullPointerException");
	}

	return m_pDeviceContext;
}

void Hikari::D3D11System::deviceContext(ID3D11DeviceContext* pDeviceContext)
{
	if(m_pDeviceContext == nullptr)
	{
		throw Exception("m_pDeviceContext is not initialized in Hikari::D3D11System::deviceContext(ID3D11DeviceContext*)", "NullPointerException");
	}

	if(pDeviceContext == nullptr)
	{
		throw Exception("Can't set m_pDeviceContext to a nullptr pointer in Hikari::D3D11System::device(ID3D11DeviceContext*)", "NullPointerException");
	}

	m_pDeviceContext = pDeviceContext;
}
