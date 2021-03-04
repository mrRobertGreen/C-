#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_3/utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab3tests
{
	TEST_CLASS(lab3tests)
	{
	public:
		
		TEST_METHOD(add_days_test)
		{
			Date d1(1, MONTH::JANUARY, 2020);
			d1.add_days(5);
		}
	};
}
