#include "../../../include/Graphics/DirectX/Direct3D11SubSystem.hpp"

Hikari::Direct3D11SubSystem::Direct3D11SubSystem( void )
{
	m_pSwapChain = nullptr;
	m_pDevice = nullptr;
	m_pDeviceContext = nullptr;
}

Hikari::Direct3D11SubSystem::~Direct3D11SubSystem( void )
{
	m_pDevice->Release();
	m_pDeviceContext->Release();
	m_pSwapChain->Release();

	m_pSwapChain = nullptr;
	m_pDevice = nullptr;
	m_pDeviceContext = nullptr;
}

int Hikari::Direct3D11SubSystem::Init( int sampleCount )
{
	DXGI_SWAP_CHAIN_DESC swapChainDescription;
	ZeroMemory(&swapChainDescription, sizeof(DXGI_SWAP_CHAIN_DESC));

	swapChainDescription.BufferCount = 1;	// do ewentualnej poprawy, nie jestem pewien czy tak mo¿e byæ
	swapChainDescription.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDescription.BufferDesc.Width = m_Width;
	swapChainDescription.BufferDesc.Height = m_Height;
	swapChainDescription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDescription.OutputWindow = m_WindowHandle;
	swapChainDescription.SampleDesc.Count = sampleCount;
	swapChainDescription.Windowed = !m_Fullscreen;
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
		return -D3D11SUBSYSTEM_INITIALIZATION_FAILED;
	}

	return 0;
}

IDXGISwapChain *Hikari::Direct3D11SubSystem::GetSwapChain( void )
{
	return m_pSwapChain;
}

ID3D11Device *Hikari::Direct3D11SubSystem::GetDevice( void )
{
	return m_pDevice;
}

ID3D11DeviceContext *Hikari::Direct3D11SubSystem::GetDeviceContext( void )
{
	return m_pDeviceContext;
}

void Hikari::Direct3D11SubSystem::SetResolution( int width, int height )
{
	m_Width = width;
	m_Height = height;
}

void Hikari::Direct3D11SubSystem::SetResolution( const Hikari::Vector2& resolution)
{
	m_Width = (int)resolution.GetU();
	m_Height = (int)resolution.GetV();
}

Hikari::Vector2 Hikari::Direct3D11SubSystem::GetResolution( void )
{
	return Vector2((float)m_Width, (float)m_Height);
}

void Hikari::Direct3D11SubSystem::SetWindowHandle( HWND WindowHandle )
{
	m_WindowHandle = WindowHandle;
}

HWND Hikari::Direct3D11SubSystem::GetWindowHandle( void ) const
{
	return m_WindowHandle;
}

void Hikari::Direct3D11SubSystem::SetFullscreen( bool isFullscreen )
{
	m_Fullscreen = isFullscreen;
}

bool Hikari::Direct3D11SubSystem::IsFullscreen( void ) const
{
	return m_Fullscreen;
}
