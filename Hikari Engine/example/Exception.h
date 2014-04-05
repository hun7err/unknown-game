#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

class Exception {
	public:
		char* message(void);
		char* type(void);

		Exception(char* pMessage, char* pType);
	private:
		char* m_pMessage;
		char* m_pType;
};

#endif // __EXCEPTION_H__