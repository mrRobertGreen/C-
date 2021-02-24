#include <iostream>
#include <exception>
#include "utils.h"

using namespace std;

Fract Fract::operator+(const Fract& other) {
	Fract temp;
	temp.denom = this->denom * other.denom;
	temp.numen = this->denom * other.numen + other.denom * this->numen;
	return temp;
}
Fract Fract::operator-(const Fract& other) {
	Fract temp;
	temp.denom = this->denom * other.denom;
	temp.numen = this->denom * other.numen - other.denom * this->numen;
	return temp;
}
std::ostream& operator << (std::ostream& os, const Fract& fr) {
	os << fr.numen << " / " << fr.denom;
	return os;
}
std::istream& operator >> (std::istream& stream, Fract& fr) {
	cout << "Enter numerator: ";
	stream >> fr.numen;
	cout << "Enter denominator: ";
	stream >> fr.denom;
	return stream;
}
Fract Fract::operator*(const Fract& other) {
	Fract temp;
	temp.denom = this->denom * other.denom;
	temp.numen = this->denom * other.denom;
	return temp;
}
Fract Fract::operator/(const Fract& other) {
	Fract temp;
	temp.numen = this->numen * other.denom;
	temp.denom = this->denom * other.numen;
	return temp;
}