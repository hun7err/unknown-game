#ifndef __WINAPI_INPUT_HPP__
#define __WINAPI_INPUT_HPP__

#include <functional>
#include "Engine.hpp"

namespace Hikari {
	class WinAPIInput {
		public:
			WinAPIInput();
			WinAPIInput(const WinAPIInput& other);
			~WinAPIInput();

			void setup();

			void keyDown(unsigned int key);
			void keyUp(unsigned int key);

			bool isKeyDown(unsigned int key);
			std::function<void(Hikari::Engine*)> keyHandler(unsigned int key);
			void keyHandler(unsigned int key, std::function<void(Hikari::Engine*)> keyHandler);

		private:
			std::pair<bool, std::function<void(void)> > m_Keys[256];
	};
}

#endif // __WINAPI_INPUT_HPP__