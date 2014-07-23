#ifndef __SHADERMANAGER_HPP__
#define __SHADERMANAGER_HPP__

#include "../Manager.hpp"
#include "../ShaderProgram.hpp"
#include "../HShader.hpp"

namespace Hikari
{
	class ShaderManager : public Manager<ShaderProgram>
	{
		public:
			static HShader add(ShaderProgram *pShader);
	};
}

#endif // __SHADERMANAGER_HPP__