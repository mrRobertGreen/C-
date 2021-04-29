#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_10/header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab10test
{
	TEST_CLASS(lab10test)
	{
	public:

		TEST_METHOD(delFirstTest)
		{
			List list;
			for (int i = 0; i < 5; ++i)
				list.addFirst(i);
			list.delFirst();
			Assert::AreEqual(*list.begin(), 3);
		}
		TEST_METHOD(delLastTest)
		{
			List list;
			for (int i = 0; i < 5; ++i)
				list.addLast(i);
			list.delLast();
			ListIterator iter = list.begin();
			while (iter + 1 != list.end())
				++iter;
			Assert::AreEqual(*iter, 3);
		}
		TEST_METHOD(for_each_test)
		{
			List list;
			for (int i = 0; i < 5; ++i)
				list.addLast(i);
			list.for_each(mult2);
			ListIterator iter = list.begin();
			for (int i = 0; i < 5; ++i)
			{
				Assert::AreEqual(*iter, i * 2);
				++iter;
			}
		}
		TEST_METHOD(countTest)
		{
			List list;
			for (int i = 0; i < 5; ++i)
				list.addLast(i);
			list.for_each(mult2);
			ListIterator iter = list.begin();
			for (int i = 0; i < 5; ++i)
			{
				Assert::AreEqual(*iter, i * 2);
				++iter;
			}
		}
		TEST_METHOD(iteratorOperatorPlusTest)
		{
			List list;
			for (int i = 0; i < 5; ++i)
				list.addLast(i);
			ListIterator iter = list.begin();
			Assert::AreEqual(*iter, 0);
			Assert::AreEqual(*(iter + 1), 1);
			Assert::AreEqual(*(iter + 2), 2);
			Assert::AreEqual(*(iter + 3), 3);
			Assert::AreEqual(*(iter + 4), 4);
		}
	};
}
