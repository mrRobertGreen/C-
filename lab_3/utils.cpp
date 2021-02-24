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

std::ostream& operator << (std::ostream& os, const Fract& fr) {
	os << fr.numen << " / " << fr.denom;
	return os;
}