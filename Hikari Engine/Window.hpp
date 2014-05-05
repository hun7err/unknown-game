#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <string>
#include "Vector.hpp"

namespace Hikari {
	class Window {
		public:
			Window(const char* title, unsigned int width = 800, unsigned int height = 600, unsigned int posX = 0, unsigned int posY = 0): m_Title(std::string(title)), m_Width(width), m_Height(height), m_PosX(posX), m_PosY(posY), m_Fullscreen(false) {}
			Window(std::string title, unsigned int width = 800, unsigned int height = 600, unsigned int posX = 0, unsigned int posY = 0): m_Title(title), m_Width(width), m_Height(height), m_PosX(posX), m_PosY(posY), m_Fullscreen(false) {}

			void position(int x, int y);
			void position(Vector2D& point);
			Vector2D position(void);
			std::string title(void);
			void title(const char* title);
			void title(std::string title);
			void size(unsigned int width, unsigned int height);
			Vector2D size(void);

			virtual void fullscreen(bool fullscreen);
			virtual bool fullscreen(void);

			virtual ~Window();

		protected:
			std::string m_Title;
			unsigned int m_PosX, m_PosY;
			unsigned int m_Width, m_Height;
			bool m_Fullscreen;
	};
}

#endif // __WINDOW_HPP__