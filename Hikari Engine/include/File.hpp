#ifndef __FILE_HPP__
#define __FILE_HPP__

#include <string>

namespace Hikari
{
	class File
	{
		public:
			static bool exists(std::wstring filename);
	};
}

#endif // __FILE_HPP__