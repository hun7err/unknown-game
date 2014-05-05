#include "D3D11System.hpp"
#include "Exception.hpp"

void Hikari::D3D11System::setup(HWND windowHandle, bool windowed, int sampleCount = 1)
{
	DXGI_SWAP_CHAIN_DESC swapChainDescription;
	ZeroMemory(&swapChainDescription, sizeof(DXGI_SWAP_CHAIN_DESC));

	swapChainDescription.BufferCount = 1;
	swapChainDescription.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDescription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDescription.OutputWindow = windowHandle;
	swapChainDescription.SampleDesc.Count = sampleCount;
	swapChainDescription.Windowed = windowed;

	D3D11CreateDeviceAndSwapChain(	NULL,
									D3D_DRIVER_TYPE_HARDWARE,
									NULL,
									NULL,
									NULL,
									NULL,
									D3D11_SDK_VERSION,
									&swapChainDescription,
									&m_pSwapChain,
									&m_pDevice,
									NULL,
									&m_pDeviceContext
								);
}

void Hikari::D3D11System::cleanup(void)
{
	m_pSwapChain->Release();
	m_pSwapChain = NULL;
	m_pDevice->Release();
	m_pDevice = NULL;
	m_pDeviceContext->Release();
	m_pDeviceContext = NULL;
}

IDXGISwapChain* Hikari::D3D11System::swapChain(void)
{
	if(m_pSwapChain == NULL)
	{
		throw new Exception("m_pSwapChain is not initialized in Hikari::D3D11System::swapChain(void)", "NullPointerException");
	}

	return m_pSwapChain;
}

void Hikari::D3D11System::swapChain(IDXGISwapChain* pSwapChain)
{
	if(m_pSwapChain == NULL)
	{
		throw new Exception("m_pSwapChain is not initialized in Hikari::D3D11System::swapChain(IDXGISwapChain*)", "NullPointerException");
	}

	if(pSwapChain == NULL)
	{
		throw new Exception("Can't set m_pSwapChain to a NULL pointer in Hikari::D3D11System::swapChain(IDXGISwapChain*)", "NullPointerException");
	}

	m_pSwapChain = pSwapChain;
}

ID3D11Device* Hikari::D3D11System::device(void)
{
	if(m_pDevice == NULL)
	{
		throw new Exception("m_pDevice is not initialized in Hikari::D3D11System::device(void)", "NullPointerException");
	}

	return m_pDevice;
}

void Hikari::D3D11System::device(ID3D11Device* pDevice)
{
	if(m_pDevice == NULL)
	{
		throw new Exception("m_pDevice is not initialized in Hikari::D3D11System::device(ID3D11Device*)", "NullPointerException");
	}

	if(pDevice == NULL)
	{
		throw new Exception("Can't set m_pDevice to a NULL pointer in Hikari::D3D11System::device(ID3D11Device*)", "NullPointerException");
	}

	m_pDevice = pDevice;
}

ID3D11DeviceContext* Hikari::D3D11System::deviceContext(void)
{
	if(m_pDeviceContext == NULL)
	{
		throw new Exception("m_pDeviceContext is not initialized in Hikari::D3D11System::deviceContext(void)", "NullPointerException");
	}

	return m_pDeviceContext;
}

void Hikari::D3D11System::deviceContext(ID3D11DeviceContext* pDeviceContext)
{
	if(m_pDeviceContext == NULL)
	{
		throw new Exception("m_pDeviceContext is not initialized in Hikari::D3D11System::deviceContext(ID3D11DeviceContext*)", "NullPointerException");
	}

	if(pDeviceContext == NULL)
	{
		throw new Exception("Can't set m_pDeviceContext to a NULL pointer in Hikari::D3D11System::device(ID3D11DeviceContext*)", "NullPointerException");
	}

	m_pDeviceContext = pDeviceContext;
}
