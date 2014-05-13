#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <utility>
#include <string>
#include <ctime>
#include <list>

namespace Hikari
{
	class LoggerClass
	{
		public:
			static LoggerClass* getInstance();
			static void addRecord(std::string record);

		private:
			LoggerClass* m_pInstance;
			std::list<std::pair<time_t, std::string> > m_Records;

	};
}

#endif // __LOGGER_HPP__