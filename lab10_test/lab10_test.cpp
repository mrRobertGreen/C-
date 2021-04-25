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
			while (++iter != list.end()) {}
			Assert::AreEqual(*iter, 3);
		}
	};
}
