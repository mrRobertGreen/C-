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
bool Fract::operator>(const Fract& other) {
	if (other.denom != this->denom)
	{
		double this_numen = this->numen * other.denom;
		double other_numen = other.numen * this->denom;
		return this_numen > other_numen;
	}
	else
	{
		return this->numen > other.numen;
	}
}
bool Fract::operator<(const Fract& other) {
	if (other.denom != this->denom)
	{
		double this_numen = this->numen * other.denom;
		double other_numen = other.numen * this->denom;
		return this_numen < other_numen;
	}
	else
	{
		return this->numen < other.numen;
	}
}
bool Fract::operator<=(const Fract& other) {
	return !(*this > other);
}
bool Fract::operator>=(const Fract& other) {
	return !(*this < other);
}
bool Fract::operator!=(const Fract& other) {
	if (other.denom != this->denom)
	{
		double this_numen = this->numen * other.denom;
		double other_numen = other.numen * this->denom;
		return this_numen != other_numen;
	}
	else
	{
		return this->numen != other.numen;
	}
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
	if (fr.denom < 0 || (fr.denom < 0 && fr.numen < 0))
	{
		fr.denom = -fr.denom;
		fr.numen = -fr.numen;
	}
	return stream;
}
Fract Fract::operator*(const Fract& other) {
	Fract temp;
	temp.denom = this->denom * other.denom;
	temp.numen = this->denom * other.denom;
	if (temp.denom < 0 || (temp.denom < 0 && temp.numen < 0))
	{
		temp.denom = -temp.denom;
		temp.numen = -temp.numen;
	}
	return temp;
}
Fract Fract::operator/(const Fract& other) {
	Fract temp;
	temp.numen = this->numen * other.denom;
	temp.denom = this->denom * other.numen;
	if (temp.denom < 0 || (temp.denom < 0 && temp.numen < 0))
	{
		temp.denom = -temp.denom;
		temp.numen = -temp.numen;
	}
	return temp;
}

// special behavior for ++MONTH
MONTH& operator++(MONTH& month) {
	int month_int = static_cast<int>(month);
	MONTH res;
	if (month == MONTH::DECEMBER)
	{
		res = MONTH::JANUARY;
	}
	else
	{
		res = static_cast<MONTH>(++month_int);
	}
	month = res;
	return res;
}
// special behavior for --MONTH
MONTH& operator--(MONTH& month) {
	int month_int = static_cast<int>(month);
	MONTH res;
	if (month == MONTH::JANUARY)
	{
		res = MONTH::DECEMBER;
	}
	else
	{
		res = static_cast<MONTH>(--month_int);
	}
	month = res;
	return res;
}

bool Date::is_leap_year(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
int Date::get_days_count(MONTH month, int year) {
	switch (month)
	{
	case MONTH::FEBRUARY:
		if (is_leap_year(year))
		{
			return 29;
		}
		else
		{
			return 28;
		}
	case MONTH::JANUARY: case MONTH::MARCH: case MONTH::MAY: case MONTH::JULY:
	case MONTH::AUGUST: case MONTH::OCTOBER: case MONTH::DECEMBER:
		return 31;
	default:
		return 30;
	}
}
bool Date::is_valid_date(int day, MONTH month, int year) {
	if (day <= 0) return false;
	if (year < 0) return false;
	const int month_days_count = get_days_count(month, year);
	if (day > month_days_count)
	{
		return false;
	}
	return true;
}
void Date::add_days(int day) {
	int res_day = this->day + day;
	if (is_valid_date(res_day, this->month, this->year))
	{
		this->day = res_day;
	}
	else
	{
		int curr_month_days_count = get_days_count(this->month, this->year);
		if (res_day > 0)
		{
			int extra_days_count = res_day - curr_month_days_count;
			if (this->month == MONTH::DECEMBER)
			{
				++this->year;

			}
			++this->month;
			this->day = extra_days_count;
		}
		else
		{
			if (this->month == MONTH::JANUARY)
			{
				--this->year;

			}
			--this->month;
			int prev_month_days_count = get_days_count(this->month, this->year);
			this->day = prev_month_days_count - res_day;
		}
	}
}
//void Date::add_months(int months) {
//	int cur_month_number = static_cast<int>(this->month);
//	int months_sum_number = cur_month_number + months;
//	if (months_sum_number > 12)
//	{
//		++this->year;
//	}
//	for (int i = 0; i < months; i++)
//	{
//		++this->month;
//	}
//}
//void Date::add_years(int year) {
//	int res = this->year + year;
//	if (res >= 0)
//	{
//		this->year = res;
//	}
//	else
//	{
//		this->year = 0;
//	}
//}
bool Date::operator==(const Date& other) const {
	return other.day == day && other.month == month && other.year == year;
}
bool Date::operator!=(const Date& other) const {
	return !(other == (*this));
}
bool Date::operator>(const Date& other) const {
	if (year > other.year)
	{
		return true;
	}
	if (month > other.month)
	{
		return true;
	}
	if (day > other.day)
	{
		return true;
	}
	return false;
}
bool Date::operator<(const Date& other) const {
	return !((*this) > other) && other != (*this);
}
bool Date::operator>=(const Date& other) const {
	return (*this) > other || other == (*this);
}
bool Date::operator<=(const Date& other) const {
	return (*this) < other || other == (*this);
}
ostream& operator << (ostream& os, const Date& date) {
	os << date.day << "." << static_cast<int>(date.month) << "." << date.year;
	return os;
}
std::istream& operator >> (std::istream& is, Date& date) {
	int input_month, input_day, input_year;
	cout << "Enter day: ";
	is >> input_day;
	cout << "Enter month: ";
	is >> input_month;
	cout << "Enter year: ";
	is >> input_year;
	date = Date(input_day, static_cast<MONTH>(input_month), input_year);
	return is;
}
Date& Date::operator++() {
	add_days(1);
	return *this;
}
Date Date::operator++(int) {
	Date prev_date = *this;
	add_days(1);
	return prev_date;
}