#ifndef __WRONGARGUMENTEXCEPTION_HPP__
#define __WRONGARGUMENTEXCEPTION_HPP__

#include "Exception.hpp"

class WrongArgumentException : public Exception {
	public:
		WrongArgumentException(char* message): Exception(message, "WrongArgumentException") {}
};

#endif // __WRONGARGUMENTEXCEPTION_HPP__