#include <fstream>
#include "../include/File.hpp"

bool Hikari::File::exists(std::wstring filename)
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