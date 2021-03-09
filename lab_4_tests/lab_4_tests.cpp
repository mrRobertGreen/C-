#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_4/utils.h"
#include <exception>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab4tests
{
	TEST_CLASS(lab4tests)
	{
	public:

		TEST_METHOD(length_test)
		{
			int len1 = 3;
			Array a1(len1);
			Assert::AreEqual(a1.length(), len1);

			int len2 = 0;
			Array a2(len2);
			Assert::AreEqual(a2.length(), len2);
		}
		TEST_METHOD(operator_plus_test)
		{
			int len1 = 3;
			Array a1(len1, 3), b1(len1, 4), res1(len1, 7);
			Assert::IsTrue(are_equal_arrs(a1 + b1, res1));

			auto func = [] {
				int len_a = 3;
				int len_b = 4;
				Array a(len_a, 3), b(len_b, 4);
				Array res = a + b;
			};
			Assert::ExpectException<std::exception>(func);

			int len2 = 3;
			Array a2(len2, 3), res2(len2, 7);
			int x = 4;
			Assert::IsTrue(are_equal_arrs(a2 + x, res2));
		}
		TEST_METHOD(operator_plus_equally_test)
		{
			int len1 = 3;
			Array a1(len1, 3), b1(len1, 4), res1(len1, 7);
			a1 += b1;
			Assert::IsTrue(are_equal_arrs(a1, res1));

			auto func = [] {
				int len_a = 3;
				int len_b = 4;
				Array a(len_a, 3), b(len_b, 4);
				a += b;
			};
			Assert::ExpectException<std::exception>(func);
		}
		TEST_METHOD(operator_equally_test)
		{
			int len1 = 3;
			Array a1(len1, 3), b1(len1, 4);
			a1 = b1;
			Assert::IsTrue(are_equal_arrs(a1, b1));

			int len2 = 5;
			Array a2(len2, 3);
			a2 = a2;
			Assert::IsTrue(are_equal_arrs(a2, a2));
		}
		TEST_METHOD(operator_taker_test)
		{
			int len1 = 3;
			Array a1(len1, 3);
			Assert::AreEqual(a1[0], 3);
			a1[0] = 4;
			Assert::AreEqual(a1[0], 4);
		}
		TEST_METHOD(find_index_test)
		{
			int len1 = 3;
			Array a1(len1, 2);
			Assert::AreEqual(a1.find_index(2), 0);
			a1[2] = 3;
			Assert::AreEqual(a1.find_index(3), 2);
			a1[0] = 1;
			Assert::AreEqual(a1.find_index(1), 0);
			Assert::AreEqual(a1.find_index(2), 1);

			auto func = [] {
				int len = 3;
				Array a(len, 3);
				a.find_index(10);
			};
			Assert::ExpectException<std::exception>(func);
		}
		TEST_METHOD(resize_test)
		{
			int len1 = 4, new_len1 = 3;
			Array a1(len1, 2), res1(new_len1, 2);
			a1.resize(new_len1);
			Assert::AreEqual(a1.length(), new_len1);
			Assert::IsTrue(are_equal_arrs(a1, res1));

			int new_len2 = 0;
			a1.resize(new_len2);
			Assert::AreEqual(a1.length(), new_len2);

			int new_len3 = 5;
			a1.resize(new_len3);
			Assert::AreEqual(a1.length(), new_len3);
		}
		TEST_METHOD(push_test)
		{
			int len1 = 3, x1 = 5, x2 = 6;
			Array a1(len1, 2);
			a1.push(x1);
			Assert::AreEqual(a1[len1], x1);

			a1.push(x2);
			Assert::AreEqual(a1[len1 + 1], x2);
		}
		TEST_METHOD(insert_test)
		{
			int len1 = 3, x1 = 1, x2 = 1, x3 = 3, idx1 = 0, idx2 = 1, idx3 = 2;
			Array a1(len1, 2);
			a1.insert(x1, idx1);
			Assert::AreEqual(a1[idx1], x1);

			a1.insert(x2, idx2);
			Assert::AreEqual(a1[idx2], x2);

			a1.insert(x3, idx3);
			Assert::AreEqual(a1[idx3], x3);
		}
		TEST_METHOD(remove_by_index_test)
		{
			int len1 = 4;
			Array a1(len1), res1(len1 - 1), res2(len1 - 2), res3(len1 - 3);
			a1[0] = 1;
			a1[1] = 2;
			a1[2] = 3;
			a1[3] = 4;

			res1[0] = 1;
			res1[1] = 2;
			res1[2] = 4;
			a1.remove_by_index(2);
			Assert::IsTrue(are_equal_arrs(a1, res1));

			res2[0] = 2;
			res2[1] = 4;
			a1.remove_by_index(0);
			Assert::IsTrue(are_equal_arrs(a1, res2));

			res3[0] = 2;
			a1.remove_by_index(1);
			Assert::IsTrue(are_equal_arrs(a1, res3));

			auto func = [] {
				int len = 3;
				Array a(len, 3);
				a.remove_by_index(10);
			};
			Assert::ExpectException<std::exception>(func);
		}
	};
}
