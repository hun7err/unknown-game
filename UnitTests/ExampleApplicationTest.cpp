#include "ExampleApplicationTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( ExampleApplicationTest );


void ExampleApplicationTest::setUp()
{
	example_application = new ExampleApplication();
}


void ExampleApplicationTest::tearDown()
{
	delete example_application;
}


void ExampleApplicationTest::testSetupArgumentOneIsNULL()
{
	example_application->setup(NULL, (LPSTR)"test", 1);
	//CPPUNIT_FAIL( "not implemented" );
}

void ExampleApplicationTest::testSetupArgumentTwoIsNULL()
{
	example_application->setup((HINSTANCE)2, NULL, 1);
	//CPPUNIT_FAIL( "not implemented" );
}

void ExampleApplicationTest::testSetupArgumentThreeIsInvalid()
{
	example_application->setup((HINSTANCE)2, (LPSTR)"test", 100000);
	//CPPUNIT_FAIL( "not implemented" );
}

