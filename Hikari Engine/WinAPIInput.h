#ifndef __WINAPI_INPUT_H__
#define __WINAPI_INPUT_H__

namespace Hikari {
	class WinAPIInput {
		public:
			WinAPIInput();
			WinAPIInput(const WinAPIInput& other);
			~WinAPIInput();

			void Setup();

			void KeyDown(unsigned int key);
			void KeyUp(unsigned int key);

			bool isKeyDown(unsigned int key);

		private:
			bool m_Keys[256];
	};
}

#endif // __WINAPI_INPUT_H__