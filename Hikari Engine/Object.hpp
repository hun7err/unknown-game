#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <string>

namespace Hikari {
	class Object {
		public:
			std::string name(void);
			void name(std::string name);

		protected:
			std::string m_Name;
	};
}

#endif // __OBJECT_HPP__