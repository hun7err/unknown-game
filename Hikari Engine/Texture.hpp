#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include <string>

namespace Hikari
{
	class Texture
	{
		public:
			Texture();
			Texture(std::string name);

			std::string name(void);
			void name(std::string name);

		private:
			std::string m_Name;
	};
}

#endif // __TEXTURE_HPP__