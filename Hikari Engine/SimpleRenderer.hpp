#ifndef __SIMPLE_RENDERER_HPP__
#define __SIMPLE_RENDERER_HPP__

#include "Renderer.hpp"

namespace Hikari {
	class SimpleRenderer : public Renderer {
		public:
			void setup(unsigned int width, unsigned int height);
			void cleanup(void);

			void render(void);
	};
}

#endif // __SIMPLE_RENDERER_HPP__