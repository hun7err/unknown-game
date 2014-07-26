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
			void setup(HWND windowHandle, bool fullscreen, int width, int height, int sampleCount);	///< przygotowuje system Direct3D 11 - alokuje zasoby, przygotowuje swapChain, urz�dzenie D3D11 i jego kontekst; je�li nie uda si� stworzy� urz�dzenia, kontekstu i swapChaina w wyniku wykonania D3D11CreateDeviceAndSwapChain (test makrem FAILED), to zostanie rzucony wyj�tek typu NullPointerException
			void cleanup(void);	///< sprz�ta, czyli wykonuje Release() na obiektach COM + zwalnia zasoby i zeruje wska�niki do przysz�ego u�ycia

			IDXGISwapChain* swapChain(void);			///< zwraca wska�nik na swapChain lub rzuca wyj�tek Exception typu NullPointerException gdy m_pSwapChain jest nullptrem
			void swapChain(IDXGISwapChain* pSwapChain);	///< ustawia nowy swapChain gdy pSwapChain nie jest nullptrem, lub rzuca wyj�tek Exception typu NullPointerException w przeciwnym wypadku

			ID3D11Device* device(void);			///< zwraca wska�nik na urz�dzenie
			void device(ID3D11Device* pDevice);

			ID3D11DeviceContext* deviceContext(void);
			void deviceContext(ID3D11DeviceContext* pDeviceContext);
		private:
			IDXGISwapChain *m_pSwapChain;			///< swapChain (odpowiada za podmian� bufor�w przy prezentacji)
			ID3D11Device *m_pDevice;				///< urz�dzenie D3D11
			ID3D11DeviceContext *m_pDeviceContext;	///< Kontekst urz�dzenia
	};
}

#endif // __D3D11_SYSTEM_HPP__