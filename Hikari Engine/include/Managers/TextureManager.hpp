#ifndef __TEXTUREMANAGER_HPP__
#define __TEXTUREMANAGER_HPP__

/**
	\file	TextureManager.hpp
	\author	Krzysztof 'hun7er' Marciniak
	\date	2014-07-23
*/

#include "../Manager.hpp"
#include "../Texture.hpp"
#include "../HTexture.hpp"

#include <string>

namespace Hikari
{
	/**
		\class	TextureManager
		\brief	Mened¿er wszystkich tekstur: 1D, 2D, 3D i tablic tekstur. Dodanie nowego rodzaju tekstur wi¹¿e siê z rozszerzeniem klasy Texture. Poza dodatkow¹ metod¹ add zwracaj¹c¹ uchwyt do dodanej tekstury, mened¿er daje tak¿e mo¿liwoœæ za³adowania tekstury z pliku podanego jako argument metod¹ load2D zwracaj¹c przy tym, podobnie jak metoda add, uchwyt do dodanej tekstury.
	*/
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