#ifndef __TEXTURE2D_HPP__
#define __TEXTURE2D_HPP__

#include "../Texture.hpp"
#include <IL/il.h>
#include <string>

namespace Hikari
{
	class Texture2D : public Texture
	{
		public:
			Texture2D();

			void create(int width, int height, D3D11_SUBRESOURCE_DATA *pInitialData = nullptr);
			void create(D3D11_TEXTURE2D_DESC *pDescription, D3D11_SUBRESOURCE_DATA* pInitialData = nullptr, D3D11_RENDER_TARGET_VIEW_DESC *pRenderTargetViewDescription = nullptr, D3D11_SHADER_RESOURCE_VIEW_DESC *pShaderResourceViewDescription = nullptr);

			void load(std::string filename);
			void cleanup(void);

			ID3D11Texture2D *dxTexture(void);
			ID3D11RenderTargetView *renderTargetView(void);

			int width(void);
			int height(void);

		private:
			ID3D11Texture2D *m_pTexture;
			ID3D11RenderTargetView *m_pRenderTargetView;
			ILuint m_ilImageName;
	};
}

#endif // __TEXTURE2D_HPP__