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
	return other.averagePageCount() == this->averagePageCount();
}
bool Book::operator>(const Book& other) const {
	return this->averagePageCount() > other.averagePageCount();
}
bool Book::operator<(const Book& other) const {
	return this->averagePageCount() < other.averagePageCount();
}
