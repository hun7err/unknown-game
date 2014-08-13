#ifndef __HSHADER_HPP__
#define __HSHADER_HPP__

#include "../../../Core/Managers/Handles/Handle.hpp"
#include "../../../Core/Rendering/Shader/ShaderProgram.hpp"

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