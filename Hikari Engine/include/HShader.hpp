#ifndef __HSHADER_HPP__
#define __HSHADER_HPP__

#include "Handle.hpp"
#include "ShaderProgram.hpp"

namespace Hikari
{
	class HShader : public Handle<ShaderProgram>
	{
		public:
			HShader(int key = -1);

			ShaderProgram* operator->(void) const;
			bool isValid(void);
			void operator=(std::nullptr_t value);
	};
}

#endif