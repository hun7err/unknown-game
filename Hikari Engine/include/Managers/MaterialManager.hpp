#ifndef __MATERIALMANAGER_HPP__
#define __MATERIALMANAGER_HPP__

/**
	\file	MaterialManager.hpp
	\author	Krzysztof 'hun7er' Marciniak
	\date	2014-07-23
*/

#include "../Material.hpp"
#include "../Manager.hpp"
#include "../HMaterial.hpp"

namespace Hikari
{
	/**
		\class	MaterialManager
		\brief	Mened�er materia��w, metoda add(Material*) zwraca uchwyt do dodanego materia�u (HMaterial)
	*/
	class MaterialManager : public Manager<Material>
	{
		public:
			static HMaterial add(Material *pMaterial);

		private:
			MaterialManager();
	};
}

#endif // __MATERIALMANAGER_HPP__