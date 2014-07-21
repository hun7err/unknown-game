#ifndef __HSHADER_HPP__
#define __HSHADER_HPP__

#include "ShaderManager.hpp"
#include "Handle.hpp"

namespace Hikari
{
	class HShader : public Handle<D3D11ShaderProgram>
	{
		public:
			D3D11ShaderProgram* operator->(void) const
			{
				return ShaderManager::get(m_ItemKey);
			}

			bool isValid(void)
			{
				return ShaderManager::isValidKey(m_ItemKey);
			}
	};
}

#endif