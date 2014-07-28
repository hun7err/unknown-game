#ifndef __MATERIALMANAGER_HPP__
#define __MATERIALMANAGER_HPP__

/**
	\file	MaterialManager.hpp
	\author	Krzysztof 'hun7er' Marciniak
	\date	2014-07-23
*/

#include "../../Core/Materials/Material.hpp"
#include "../../Core/Managers/Interface/Manager.hpp"
#include "../../Core/Managers/Handles/HMaterial.hpp"

namespace Hikari
{
	/**
		\class	MaterialManager
		\brief	Mened¿er materia³ów, metoda add(Material*) zwraca uchwyt do dodanego materia³u (HMaterial)
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