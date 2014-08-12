#include <fstream>
#include "../../include/IO/File.hpp"

bool Hikari::IO::File::exists(std::wstring filename)
{
	std::ifstream file(filename.c_str());
    if (file.good()) {
        file.close();
        return true;
    } else {
        file.close();
        return false;
    }
}