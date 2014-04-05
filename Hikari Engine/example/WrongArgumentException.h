#ifndef __WRONGARGUMENTEXCEPTION_H__
#define __WRONGARGUMENTEXCEPTION_H__

#include "Exception.h"

class WrongArgumentException : public Exception {
	public:
		WrongArgumentException(char* message): Exception(message, "WrongArgumentException") {}
};

#endif // __WRONGARGUEMNTEXCEPTION_H__