#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <utility>
#include <mutex>
#include <string>
#include <ctime>
#include <list>

namespace Hikari
{
	class Logger
	{
		public:
			static void addRecord(std::string record);
			static void dump(std::string filename);

		private:
			static std::list<std::pair<time_t, std::string> > m_Records;
			static std::mutex m_recordMutex;

	};
}

#endif // __LOGGER_HPP__