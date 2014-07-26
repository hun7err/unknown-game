#ifndef __SHADERMANAGER_HPP__
#define __SHADERMANAGER_HPP__

/**
	\file	ShaderManager.hpp
	\author	Krzysztof 'hun7er' Marciniak
	\date	2014-07-23
*/

#include "../Manager.hpp"
#include "../ShaderProgram.hpp"
#include "../HShader.hpp"

namespace Hikari
{
	/**
		\class	ShaderManager
		\brief	Mened¿er shaderów - aby u¿yæ danego shadera nale¿y go najpierw dodaæ tutaj, poniewa¿ w przeciwnym wypadku nie zostanie on wykryty w uchwycie.
	*/
	class ShaderManager : public Manager<ShaderProgram>
	{
		public:
			static HShader add(ShaderProgram *pShader);
	};
}

#endif // __SHADERMANAGER_HPP__