#include "../../include/Helpers/Exception.hpp"

Exception::Exception(char* pMessage, char* pType): m_pMessage(pMessage), m_pType(pType)
{
}

char* Exception::message(void)
{
	return m_pMessage;
}

char* Exception::type(void)
{
	return m_pType;
}
