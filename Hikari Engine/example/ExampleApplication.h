#ifndef __EXAMPLEAPPLICATION_H__
#define __EXAMPLEAPPLICATION_H__

#include "Application.h"
#include <Windows.h>

class ExampleApplication : public Application {
	public:
		void run(void);
		void setup(HINSTANCE hInstance, LPSTR lpCmdLine, int nCmdShow);

		ExampleApplication();
		~ExampleApplication();
	private:
		HINSTANCE m_hInstance;
		LPSTR m_lpCmdLine;
		int m_nCmdShow;
};

#endif // __EXAMPLEAPPLICATION_H__