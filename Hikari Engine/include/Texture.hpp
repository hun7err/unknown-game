#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include <string>
#include <IL/il.h>

namespace Hikari
{
	class Texture
	{
		public:
			Texture();
			Texture(std::string name);
			~Texture();
			
			void bind(void);
			unsigned int width(void);
			unsigned int height(void);
			unsigned char *data(void);
			unsigned int size(void);
			
			ILuint ilImageName(void);
			void ilImageName(ILuint newILImageName);

			std::string name(void);
			void name(std::string name);

		private:
			void createImage(void);

			std::string m_Name;
			ILuint m_ilImageName;
	};
}

#endif // __TEXTURE_HPP__