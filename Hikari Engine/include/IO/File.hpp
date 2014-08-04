#ifndef __FILE_HPP__
#define __FILE_HPP__

#include <string>
//#include <fstream>

namespace Hikari
{
	namespace IO
	{
		class File
		{
			public:
				static bool exists(std::wstring filename);
				/*std::string readline(void);
				void open(std::string filename);
				void close(void);*/

			protected:
				//std::ifstream m_InputStream;
		};
	}
}

#endif // __FILE_HPP__