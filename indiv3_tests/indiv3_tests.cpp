#include "pch.h"
#include "CppUnitTest.h"
#include <exception>
#include "../indiv_3/header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace indiv3tests
{
	TEST_CLASS(indiv3tests)
	{
	public:

		TEST_METHOD(ones_test)
		{
			Matrix<int> m1 = Matrix<int>(3, 3).ones();
			for (int i = 0; i < m1.get_rows_count(); i++)
				for (int j = 0; j < m1.get_cols_count(); j++)
					Assert::AreEqual(m1(i, j), (i == j ? 1 : 0));

			auto func = [] {
				Matrix<int> m = Matrix<int>(3, 4).ones();
			};
			Assert::ExpectException<exception>(func);
		}
	};
}
