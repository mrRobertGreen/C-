#include <iostream>
#include <exception>
#include "utils.h"

using namespace std;

Measurer::Measurer(int m, int cm) {
	if (m < 0 || cm < 0)
		throw exception("invalid input");
	else 
	{
		this->m = m;
		this->cm = cm;
		this->to_normal();
	}
}
Measurer& Measurer::to_normal() {
	while (cm >= 100)
	{
		cm -= 100;
		++m;
	}
	return *this;
}
ostream& operator << (ostream& out, const Measurer& size) { // вывод в поток
	out << size.m << "m. " << size.cm << "cm.";
	return out;
}
istream& operator >> (istream& in, Measurer& size) { // ввод из потока
	int cm, m;
	cout << "Enter metres: ";
	in >> m;
	cout << "Enter centimetres: ";
	in >> cm;
	if (cm < 0 || m < 0)
		throw exception("invalid input");
	size.to_normal();
	return in;
}
int Measurer::to_centimetres() const {
	return cm + 100 * m;
}
bool Measurer::operator<(const Measurer& other) {
	return this->to_centimetres() < other.to_centimetres();
}
bool Measurer::operator==(const Measurer& other) {
	return this->to_centimetres() == other.to_centimetres();
}
Measurer& Measurer::operator+=(int cm) {
	this->cm += cm;
	this->to_normal();
	return *this;
}
Measurer Measurer::operator-(const Measurer& other) {
	int cm1 = this->to_centimetres();
	int cm2 = other.to_centimetres();
	if (cm1 < cm2)
		throw exception("can not be calculated");
	else
	{
		return Measurer(0, cm1 - cm2).to_normal();
	}
}