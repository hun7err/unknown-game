#ifndef __TEXTUREMANAGER_HPP__
#define __TEXTUREMANAGER_HPP__

#include "../Manager.hpp"
#include "../Texture.hpp"
#include "../HTexture.hpp"

#include <string>

namespace Hikari
{
	class TextureManager : public Manager<Texture>
	{
		public:
			static HTexture add(Texture *pTexture);
			static HTexture load2D(std::string filename);

		private:
			TextureManager();
	};
}

#endif