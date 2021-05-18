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
		TEST_METHOD(is_symmetric_test)
		{
			Matrix<int> m1 = Matrix<int>(2, 2);
			m1(0, 0) = 2;
			m1(0, 1) = 1;
			m1(1, 0) = 1;
			m1(1, 1) = 3;

			Assert::IsTrue(m1.is_symmetric());
			m1(0, 1) = 10;
			Assert::IsFalse(m1.is_symmetric());
		}
		TEST_METHOD(algebraic_complement_test)
		{
			Matrix<int> m1 = Matrix<int>(3, 3);
			int k = 1;
			for (int i = 0; i < m1.get_rows_count(); i++)
				for (int j = 0; j < m1.get_cols_count(); j++)
					m1(i, j) = k++;

			Assert::AreEqual(m1.algebraic_complement(0, 0), -3);
			Assert::AreEqual(m1.algebraic_complement(2, 0), -3);
			Assert::AreEqual(m1.algebraic_complement(0, 1), 6);
			Assert::AreEqual(m1.algebraic_complement(2, 1), 6);
		}
		TEST_METHOD(operator_plus_test)
		{
			Matrix<int> m1 = Matrix<int>(2, 2);
			Matrix<int> m2 = Matrix<int>(2, 2).ones();
			int k = 1;
			for (int i = 0; i < m1.get_rows_count(); i++)
				for (int j = 0; j < m1.get_cols_count(); j++)
					m1(i, j) = k++;

			Matrix<int> res = Matrix<int>(2, 2);
			res(0, 0) = 2;
			res(0, 1) = 2;
			res(1, 0) = 3;
			res(1, 1) = 5;

			Assert::IsTrue((m1 + m2) == res);
		}
		TEST_METHOD(operator_multiply_test)
		{
			Matrix<int> m1 = Matrix<int>(2, 2);
			Matrix<int> m2 = Matrix<int>(2, 2).ones();
			int k = 1;
			for (int i = 0; i < m1.get_rows_count(); i++)
				for (int j = 0; j < m1.get_cols_count(); j++)
					m1(i, j) = k++;

			Matrix<int> res = Matrix<int>(2, 2);
			res(0, 0) = 1;
			res(0, 1) = 0;
			res(1, 0) = 0;
			res(1, 1) = 4;

			Assert::IsTrue((m1 * m2) == res);
		}
		TEST_METHOD(operator_eqaul_test)
		{
			Matrix<int> m1 = Matrix<int>(2, 2).ones();
			Matrix<int> m2 = Matrix<int>(2, 2).ones();

			Assert::IsTrue(m1 == m2);

			m1(1, 0) = 3;

			Assert::IsFalse(m1 == m2);
		}
	};
}
