#include "pch.h"
#include "CppUnitTest.h"
#include "../indiv_1/utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace indiv1test
{
	TEST_CLASS(indiv1test)
	{
	public:
		
		TEST_METHOD(getNameTest)
		{
			string name = "name";
			Book book = Book(name, "qwe", Array<History>());
			Assert::AreEqual(book.getName(), name);
		}
		TEST_METHOD(setNameTest)
		{
			string name = "Book";
			Book book = Book();
			book.setName(name);
			Assert::AreEqual(book.getName(), name);
		}
		TEST_METHOD(setAuthorTest)
		{
			string author = "Dima";
			Book book = Book();
			book.setAuthor(author);
			Assert::AreEqual(book.getAuthor(), author);
		}
		TEST_METHOD(averagePageCountTest)
		{
			const int p1 = 723, p2 = 235, p3 = 74;
			const double res = (p1 + p2 + p3) / 3.;
			History h1 = History(3, p1);
			History h2 = History(3, p2);
			History h3 = History(3, p3);
			Array<History> data = Array<History>(3, History());
			data[0] = h1;
			data[1] = h2;
			data[2] = h3;
			Book book = Book("name", "author", data);
			Assert::AreEqual(book.averagePageCount(), res);
		}
		TEST_METHOD(existEarlierEditionTest)
		{
			const int y1 = 2001, y2 = 2005, y3 = 2020, year = 2000;
			const bool res = y1 < year;
			History h1 = History(y1, 3);
			History h2 = History(y2, 3);
			History h3 = History(y3, 3);
			Array<History> data = Array<History>(3, History());
			data[0] = h1;
			data[1] = h2;
			data[2] = h3;
			Book book = Book("name", "author", data);
			Assert::AreEqual(book.existEarlierEdition(year), res);
		}
		TEST_METHOD(operatorsTest)
		{
			const int p1 = 723, p2 = 235, p3 = 74;
			const double res = (p1 + p2 + p3) / 3;
			History h1 = History(3, p1);
			History h2 = History(3, p2);
			History h3 = History(3, p3);
			History h4 = History(3, p3 + 1);
			Array<History> data1 = Array<History>(3, History());
			Array<History> data2 = Array<History>(3, History());
			data1[0] = h1;
			data1[1] = h2;
			data1[2] = h3;
			data2[0] = h1;
			data2[1] = h2;
			data2[2] = h3;
			Book book1 = Book("name", "author", data1);
			Book book2 = Book("name", "author", data2);
			//Assert::IsTrue(book1 == book2);
			data2[2] = h4;
			Book book3 = Book("name", "author", data2);
			//Assert::IsFalse(book1 == book3);
			Assert::IsTrue(book1 < book3);
			Assert::IsFalse(book1 > book3);
			book1 = book3;
			Assert::IsTrue(book1 == book3);
		}
	};
}
