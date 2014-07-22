#ifndef __HSHADER_HPP__
#define __HSHADER_HPP__

#include "ShaderManager.hpp"
#include "Handle.hpp"

namespace Hikari
{
	class HShader : public Handle<ShaderProgram>
	{
		public:
			ShaderProgram* operator->(void) const
			{
				return ShaderManager::get(m_ItemKey);
			}

			bool isValid(void)
			{
				return ShaderManager::isValidKey(m_ItemKey);
			}
			
			void operator=(std::nullptr_t value)
			{
				m_ItemKey = -1;
			}
	};
}

#endif