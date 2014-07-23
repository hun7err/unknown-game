#ifndef __TEXTUREMANAGER_HPP__
#define __TEXTUREMANAGER_HPP__

#include "Manager.hpp"
#include "Texture.hpp"
#include "HTexture.hpp"

namespace Hikari
{
	class TextureManager : public Manager<Texture>
	{
		public:
			HTexture add(Texture *pTexture);
	};

	//typedef Manager<Texture> TextureManager;

}

#endif