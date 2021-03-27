#include "header.h"
#include <string>
#include <cmath>

using namespace std;

BigNum::BigNum() {
	is_negative = false;
	digits = Array(1);
}
BigNum::BigNum(int n) {
	is_negative = (n < 0);
	digits = Array(0);
	n = abs(n);
	while (n >= 1)
	{
		digits.push(n % 10);
		n = n / 10;
	}
}
BigNum::BigNum(const string str) {
	if (str.size() == 0) {
		is_negative = false;
		digits = Array(1, 0);
		return;
	}
	int start = 0;
	if (str[0] == '-') {
		is_negative = true;
		++start;
	}
	digits = Array(0);
	for (int i = start; i < str.size(); i++)
	{
		digits.insert(str[i] - '0', 0);
	}
}
BigNum::BigNum(const BigNum& other) {
	is_negative = other.is_negative;
	digits = Array(other.digits);
}
bool BigNum::get_is_negative() {
	return is_negative;
}
Array BigNum::get_digits() {
	return digits;
}
ostream& operator << (ostream& out, const BigNum& num) {
	if (num.is_negative)
		out << "-";
	for (int i = num.digits.length() - 1; i >= 0; --i)
		out << num.digits[i];
	return out;
}
istream& operator >> (istream& in, BigNum& num) { // переделать на string и getline
	char str[100];
	cout << "Enter number: ";
	in >> str;
	num = BigNum(str);
	return in;
}
BigNum::operator int() {
	int num = digits[digits.length() - 1];
	for (int i = digits.length() - 2; i >= 0; --i)
		num = num * 10 + digits[i];
	return is_negative ? -num : num;
}
BigNum::operator string () {
	string str = "";
	if (is_negative)
		str.append("-");
	for (int i = digits.length() - 1; i >= 0; --i) {
		str.append(to_string(digits[i]));
	}
	return str;
}
BigNum& BigNum::operator=(const BigNum& num) {
	return *this;
}
int BigNum::operator[](int idx) const {
	return digits[idx];
}
bool BigNum::operator==(const BigNum& num) const {
	if (num.is_negative != this->is_negative)
		return false;
	return num.digits == this->digits;
}
bool BigNum::operator!=(const BigNum& num) const {
	return !((*this) == num);
}
bool BigNum::operator>(const BigNum& num) const {
	if (this->is_negative && !num.is_negative)
		return false;
	else if (!this->is_negative && num.is_negative)
		return true;
	if (this->digits.length() < num.digits.length())
		return false;
	if (this->digits.length() > num.digits.length())
		return true;
	for (int i = this->digits.length() - 1; i >= 0; --i)
	{
		if (this->operator[](i) > num[i])
			return true;
		else if (this->operator[](i) < num[i])
			return false;
	}
}
bool BigNum::operator>=(const BigNum& num) const {
	return this->operator>(num) || this->operator==(num);
}
bool BigNum::operator<(const BigNum& num) const {
	return !(this->operator>(num)) && !(this->operator==(num));
}
bool BigNum::operator<=(const BigNum& num) const {
	return !(this->operator>(num));
}
BigNum BigNum::operator+(const BigNum& num) const {
	int in_mind = 0;
	int res = 0;
	int sum = 0;
	for (int i = 0; i < num.digits.length(); i++)
	{
		sum = num[i] + (*this)[i];
		if (sum >= 10)
		{
			in_mind = sum / 10;
			sum %= 10;
		}
		res += pow(10, i) + sum * pow(10, i);
		sum = in_mind;
		in_mind = 0;
	}
	return BigNum(res);
}