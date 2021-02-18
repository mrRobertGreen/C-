#include "pch.h"
#include "CppUnitTest.h"
#include <exception>
#include "../lab_1/utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab1tests
{
	TEST_CLASS(lab1tests)
	{
	public:

		TEST_METHOD(listLengthTest)
		{
			const int len1 = 3;
			int arr1[len1] = { 1, 2, 3 };
			listptr list1 = arrToList(arr1, len1);
			Assert::AreEqual(listLength(list1), len1);

			const int len2 = 5;
			int arr2[len2] = { 1, 2, 3, 5, 7 };
			listptr list2 = arrToList(arr2, len2);
			Assert::AreEqual(listLength(list2), len2);

			const int len3 = 1;
			int arr3[len3] = { 1 };
			listptr list3 = arrToList(arr3, len3);
			Assert::AreEqual(listLength(list3), len3);
		}
		TEST_METHOD(countOfTest)
		{
			const int len1 = 3;
			int arr1[len1] = { 3, 2, 2 };
			listptr list1 = arrToList(arr1, len1);
			Assert::AreEqual(countOf(list1, 3), 1);

			const int len2 = 5;
			int arr2[len2] = { 1, 3, 3, 5, 3 };
			listptr list2 = arrToList(arr2, len2);
			Assert::AreEqual(countOf(list2, 3), 3);

			const int len3 = 1;
			int arr3[len3] = { 1 };
			listptr list3 = arrToList(arr3, len3);
			Assert::AreEqual(countOf(list3, 3), 0);
		}
		TEST_METHOD(listItemsSumTest)
		{
			const int len1 = 3;
			int arr1[len1] = { 3, 2, 2 };
			listptr list1 = arrToList(arr1, len1);
			Assert::AreEqual(listItemsSum(list1), 7);

			const int len2 = 5;
			int arr2[len2] = { 1, 0, 0, 0, 3 };
			listptr list2 = arrToList(arr2, len2);
			Assert::AreEqual(listItemsSum(list2), 4);

			listptr list3 = nullptr;
			Assert::AreEqual(listItemsSum(list3), 0);
		}
		TEST_METHOD(countOfRecursionTest)
		{
			const int len1 = 3;
			int arr1[len1] = { 3, 3, 2 };
			listptr list1 = arrToList(arr1, len1);
			Assert::AreEqual(countOfRecursion(list1, 3), 2);

			const int len2 = 5;
			int arr2[len2] = { 1, 0, 0, 0, 3 };
			listptr list2 = arrToList(arr2, len2);
			Assert::AreEqual(countOfRecursion(list2, 3), 1);

			listptr list3 = nullptr;
			Assert::AreEqual(countOfRecursion(list3, 3), 0);
		}
		TEST_METHOD(maxItemByValueTest)
		{
			const int len1 = 3;
			int arr1[len1] = { 3, 3, 2 };
			listptr list1 = arrToList(arr1, len1);
			Assert::AreEqual(maxItemByValue(list1), 3);

			const int len2 = 5;
			int arr2[len2] = { 1, 0, 0, 0, 3 };
			listptr list2 = arrToList(arr2, len2);
			Assert::AreEqual(maxItemByValue(list2), 3);

			auto func = [] {
				listptr list3 = nullptr;
				maxItemByValue(list3);
			};
			Assert::ExpectException<std::exception>(func);
		}
		TEST_METHOD(insertAfterTest)
		{
			const int len1 = 3;
			const int res_len1 = 4;
			int arr1[len1] = { 1, 3, 4 };
			int res_arr1[res_len1] = { 1, 2, 3, 4 };
			listptr list1 = arrToList(arr1, len1);
			listptr res_list1 = arrToList(res_arr1, res_len1);
			insertAfter(2, list1, 1);
			Assert::IsTrue(isEqual(list1, res_list1));

			const int len2 = 3;
			const int res_len2 = 4;
			int arr2[len2] = { 1, 2, 3 };
			int res_arr2[res_len2] = { 1, 2, 3, 4 };
			listptr list2 = arrToList(arr2, len2);
			listptr res_list2 = arrToList(res_arr2, res_len2);
			insertAfter(4, list2, 3);
			Assert::IsTrue(isEqual(list2, res_list2));

			auto func = [] {
				const int len3 = 3;
				const int res_len3 = 4;
				int arr3[len3] = { 1, 2, 3 };
				int res_arr3[res_len3] = { 1, 2, 3, 4 };
				listptr list3 = arrToList(arr3, len3);
				listptr res_list3 = arrToList(res_arr3, res_len3);
				insertAfter(4, list3, 10);
			};
			Assert::ExpectException<std::exception>(func);
		}
	};
}
