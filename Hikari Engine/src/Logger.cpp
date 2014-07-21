#include <fstream>
#include "../include/Logger.hpp"
#include "../include/Exception.hpp"

std::list<std::pair<time_t, std::string> > Hikari::Logger::m_Records;
std::mutex Hikari::Logger::m_recordMutex;

void Hikari::Logger::addRecord(std::string record)
{
	m_recordMutex.lock();

	time_t currentTime;
	time(&currentTime);
	m_Records.push_back(std::make_pair(currentTime, record));

	m_recordMutex.unlock();
}

void Hikari::Logger::dump(std::string filename)
{
	std::ofstream outFile;

	try
	{
		outFile.open(filename);
		
		m_recordMutex.lock();
		
		static time_t record_time;
		static char time_string[25];
		static struct tm timeinfo;

		for(auto currentRecord = m_Records.begin(); currentRecord != m_Records.end(); ++currentRecord)
		{
			record_time = currentRecord->first;
			localtime_s(&timeinfo, &record_time);
			memset(time_string, 0, 25);
			strftime(time_string, 25, "%Y-%m-%dT%H:%M:%SZ", &timeinfo);
			outFile << time_string << " " << currentRecord->second << std::endl;
		}

		m_recordMutex.unlock();

		outFile.close();
	}
	catch(std::ifstream::failure e)
	{
		std::string exceptionMessage("Could not open '" + filename + "' in Logger::dump(std::string) :  " + e.code().message() + "/" + e.what());
		throw Exception(const_cast<char*>(exceptionMessage.c_str()), "IOException");
	}
}