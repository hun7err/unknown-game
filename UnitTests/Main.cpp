#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main()
{
	CppUnit::TextUi::TestRunner runner;
	CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
	runner.addTest( suite );

	runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(), std::cerr ) );

	bool testResult = runner.run();

	return testResult ? 0 : 1;
}