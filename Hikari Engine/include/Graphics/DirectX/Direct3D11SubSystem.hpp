#ifndef __HIKARI_GRAPHICS_DIRECTX_DIRECT3D11SUBSYSTEMHPP__
#define __HIKARI_GRAPHICS_DIRECTX_DIRECT3D11SUBSYSTEMHPP__

#include <d3d11.h>
#include <d3d10.h>
#include <dxgi.h>
#include "../../Helpers/Math/Vector2D.hpp"

#define D3D11SUBSYSTEM_INITIALIZATION_FAILED	1

namespace Hikari
{
	class Direct3D11SubSystem
	{
		public:
			Direct3D11SubSystem( void );
			~Direct3D11SubSystem( void );

			int Init( int sampleCount = 1 );
			// void Refresh( void );	// powinno odœwie¿aæ ustawienia

			IDXGISwapChain *GetSwapChain( void );
			ID3D11Device *GetDevice( void );
			ID3D11DeviceContext *GetDeviceContext( void );

			void SetResolution( int width, int height );
			void SetResolution( const Vector2D& resolution);
			Vector2D GetResolution( void );

			void SetWindowHandle( HWND WindowHandle );
			HWND GetWindowHandle( void ) const;

			void SetFullscreen( bool isFullscreen );
			bool IsFullscreen( void ) const;

		private:
			IDXGISwapChain *m_pSwapChain;			///< swapChain (odpowiada za podmianê buforów przy prezentacji)
			ID3D11Device *m_pDevice;				///< urz¹dzenie D3D11
			ID3D11DeviceContext *m_pDeviceContext;	///< Kontekst urz¹dzenia
			HWND m_WindowHandle;
			bool m_Fullscreen;
			int m_Width,
				m_Height,
				m_SampleCount;
	};
}

#endif