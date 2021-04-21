#include <iostream>
#include "utils.h"

using namespace std;

Book::Book(const Book& other) {
	name = other.name;
	author = other.author;
	const int dataLen = other.data.length();
	data = Array<History>(dataLen, History());
	for (int i = 0; i < dataLen; i++)
	{
		data[i] = other.data[i];
	}
}
string Book::getName() const {
	return name;
}
string Book::getAuthor() const {
	return author;
}
void Book::setName(string name) {
	this->name = name;
}
void Book::setAuthor(string author) {
	this->author = author;
}
double Book::averagePageCount() const {
	double pagesCountSum = 0;
	double editionsCount = data.length();
	for (int i = 0; i < editionsCount; i++)
	{
		pagesCountSum += data[i].pages;
	}
	return pagesCountSum / editionsCount;
}
bool Book::existEarlierEdition(int year) const {
	for (int i = 0; i < data.length(); i++)
	{
		if (data[i].year < year)
			return true;
	}
	return false;
}
Book Book::operator=(const Book& other) {
	if (this != &other)
	{
		this->author = other.author;
		this->name = other.name;
		this->data = other.data;
	}
	return *this;
}
bool Book::operator==(const Book& other) const {
	if (this->name != other.name)
		return false;
	if (this->author != other.author)
		return false;
	for (int i = 0; i < other.data.length(); i++)
	{
		if (this->data[i].pages != other.data[i].pages)
			return false;
		if (this->data[i].year != other.data[i].year)
			return false;
	}
	return true;
}
bool Book::operator>(const Book& other) const {
	return this->averagePageCount() > other.averagePageCount();
}
bool Book::operator<(const Book& other) const {
	return this->averagePageCount() < other.averagePageCount();
}
ostream& operator<<(ostream& out, const Book& book) {
	out << "Name: " << book.name << "\n";
	out << "Author: " << book.author << "\n";
	out << "Data:\n";
	for (int i = 0; i < book.data.length(); i++)
	{
		out << "Year: " << book.data[i].year << ", pages: " << book.data[i].pages << "\n";
	}
	return out;
}
istream& operator>>(istream& in, Book& book) {
	cout << "Enter book name: ";
	getline(in, book.name);
	cout << "Enter author of book: ";
	getline(in, book.author);
	int pages, year;
	Array<History> data = Array<History>(3, History());
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter count of pages: ";
		in >> pages;
		cout << "Enter year of edition: ";
		in >> year;
		data[i] = History(year, pages);
	}
	book.data = data;
	return in;
}
