#ifndef __D3D11_SYSTEM_HPP__
#define __D3D11_SYSTEM_HPP__

#include <d3d11.h>
#include <d3d10.h>
#include <dxgi.h>	// do IDXGISwapChain

namespace Hikari
{
	class D3D11System
	{
		public:
			void setup(HWND windowHandle, bool fullscreen, int width, int height, int sampleCount);
			void cleanup(void);

			IDXGISwapChain* swapChain(void);
			void swapChain(IDXGISwapChain* pSwapChain);

			ID3D11Device* device(void);
			void device(ID3D11Device* pDevice);

			ID3D11DeviceContext* deviceContext(void);
			void deviceContext(ID3D11DeviceContext* pDeviceContext);
		private:
			IDXGISwapChain *m_pSwapChain;
			ID3D11Device *m_pDevice;
			ID3D11DeviceContext *m_pDeviceContext;
	};
}

#endif // __D3D11_SYSTEM_HPP__