#ifndef MONEYTEST_H
#define MONEYTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../Hikari Engine/example/ExampleApplication.h"
#include "../Hikari Engine/WrongArgumentException.h"

class ExampleApplicationTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE( ExampleApplicationTest );
	CPPUNIT_TEST( testSetupArgumentOneIsNULL );
	CPPUNIT_TEST( testSetupArgumentTwoIsNULL );
	CPPUNIT_TEST( testSetupArgumentThreeIsInvalid );
	CPPUNIT_TEST_EXCEPTION( testSetupArgumentOneIsNULL, WrongArgumentException );
	CPPUNIT_TEST_EXCEPTION( testSetupArgumentTwoIsNULL, WrongArgumentException );
	CPPUNIT_TEST_EXCEPTION( testSetupArgumentThreeIsInvalid, WrongArgumentException );
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp();
		void tearDown();

		void testSetupArgumentOneIsNULL();
		void testSetupArgumentTwoIsNULL();
		void testSetupArgumentThreeIsInvalid();

	private:
		ExampleApplication* example_application;
};

#endif  // MONEYTEST_H