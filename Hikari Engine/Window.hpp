#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <string>
#include "Vector.hpp"

namespace Hikari {
	class Window {
		public:
			Window(const char* title, unsigned int width = 800, unsigned int height = 600, unsigned int posX = 0, unsigned int posY = 0): m_Title(std::string(title)), m_Width(width), m_Height(height), m_PosX(posX), m_PosY(posY) {}
			Window(std::string title, unsigned int width = 800, unsigned int height = 600, unsigned int posX = 0, unsigned int posY = 0): m_Title(title), m_Width(width), m_Height(height), m_PosX(posX), m_PosY(posY) {}

			Window& setPosition(int x, int y);
			Window& setPosition(Vector2D& point);
			Vector2D getPosition(void);
			std::string getTitle(void);
			Window& setTitle(const char* title);
			Window& setTitle(std::string title);
			Window& setSize(unsigned int width, unsigned int height);

			virtual ~Window();

		protected:
			std::string m_Title;
			unsigned int m_PosX, m_PosY;
			unsigned int m_Width, m_Height;
	};
}

#endif // __WINDOW_HPP__