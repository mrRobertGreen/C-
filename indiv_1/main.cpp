#include <iostream>
#include "utils.h"
#include <string>

using namespace std;

int main() {
	/*Book book = Book(); // for testing
	cout << book;
	cin >> book;
	cout << book*/

	History h1_1 = History(2005, 35);
	History h1_2 = History(2010, 65);
	History h1_3 = History(2020, 1235);
	Array<History> data1 = Array<History>(3, History());
	data1[0] = h1_1;
	data1[1] = h1_2;
	data1[2] = h1_3;
	Book book1 = Book("Broken Heart", "Dimon", data1);

	History h2_1 = History(2007, 352);
	History h2_2 = History(2011, 653);
	History h2_3 = History(2021, 123);
	Array<History> data2 = Array<History>(3, History());
	data2[0] = h2_1;
	data2[1] = h2_2;
	data2[2] = h2_3;
	Book book2 = Book("Blue Sky", "Buega", data2);

	History h3_1 = History(2019, 1);
	History h3_2 = History(2020, 42);
	History h3_3 = History(2021, 123);
	Array<History> data3 = Array<History>(3, History());
	data3[0] = h3_1;
	data3[1] = h3_2;
	data3[2] = h3_3;
	Book book3 = Book("The Prettiest Girl", "Susen", data3);

	Array<Book> books = Array<Book>(3, Book());
	books[0] = book1;
	books[1] = book2;
	books[2] = book3;

	cout << "Books:\n";
	for (int i = 0; i < books.length(); i++)
	{
		cout << books[i];
	}

	cout << "Average pages count:\n";
	for (int i = 0; i < books.length(); i++)
	{
		cout << books[i].getAuthor() << ": " << books[i].averagePageCount() << "\n";
	}
	unsigned int year;
	cout << "Enter some year: ";
	cin >> year;
	cout << "List of authors, who has books, which were published earlier than " << year << " year:\n";
	for (int i = 0; i < books.length(); i++)
	{
		if (books[i].existEarlierEdition(year))
			cout << books[i].getAuthor() << "\n";
	}

	return EXIT_SUCCESS;
}