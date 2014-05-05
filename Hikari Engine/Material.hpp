#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__

#include <string>

namespace Hikari
{
	class Material
	{
		public:
			Material();
			Material(std::string name);

			virtual ~Material();

			std::string name(void);
			void name(std::string name);

		private:
			std::string m_Name;
		// placeholder
	};
}

#endif // __MATERIAL_HPP__