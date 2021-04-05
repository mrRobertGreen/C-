#pragma once
#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

struct History {
	int year;
	int pages;
	History(int year, int pages) {
		if (year < 0)
		{
			this->year = 1;
			cout << "Year value is incorrect. Field was filled with a default value.";
		}
		else {
			this->year = year;
		}
		if (pages < 0)
		{
			this->pages = 1;
			cout << "Pages value is incorrect. Field was filled with a default value.";
		}
		else {
			this->pages = pages;
		}
	};
	History() : year(1), pages(1) {};
};

class Book {
private:
	string name;
	string author;
	
public:
	Array<History> data;
	Book(string name, string author, Array<History> data)
		: name(name), author(author), data(data) {};
	Book() : name("noname"), author("unknown"), data(Array<History>(3, History(0, 0))) {};
	Book(const Book& other);
	string getName() const;
	string getAuthor() const;
	void setName(string name);
	void setAuthor(string author);
	double averagePageCount() const;
	bool existEarlierEdition(int year) const;

	Book operator=(const Book& other);
	bool operator==(const Book& other) const;
	bool operator>(const Book& other) const;
	bool operator<(const Book& other) const;
};