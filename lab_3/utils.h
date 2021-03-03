#pragma once
#include <iostream>

class Fract {
private:
	int numen, denom;

public:
	Fract() : numen(0), denom(1) {}
	Fract(int a, int b = 1) :numen(a) {
		denom = (b != 0) ? b : 1;
	}
	Fract operator+(const Fract& other);
	Fract operator-(const Fract& other);
	Fract operator*(const Fract& other);
	Fract operator/(const Fract& other);
	bool operator>(const Fract& other);
	bool operator<(const Fract& other);
	bool operator>=(const Fract& other);
	bool operator<=(const Fract& other);
	bool operator!=(const Fract& other);
	friend std::ostream& operator << (std::ostream&, const Fract&);
	friend std::istream& operator >> (std::istream&, Fract&);
};

enum class MONTH {
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER,
};
MONTH& operator++(MONTH& month);
MONTH& operator--(MONTH& month);

class Date {
private:
	int day, year;
	MONTH month;

	bool is_valid_date(int day, MONTH month, int year);
	bool is_leap_year(int year);
	
	int get_days_count(MONTH month, int year);

public:
	Date() : day(1), month(MONTH::JANUARY), year(0) {};
	Date(int day, MONTH month, int year) {
		if (is_valid_date(day, month, year))
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
		else
		{
			this->day = 1;
			this->month = MONTH::JANUARY;
			this->year = 0;
		}
	}
	void add_days(int days);
	void add_months(int month);
	void add_years(int year);
	bool operator==(const Date& other) const;
	bool operator!=(const Date& other) const;
	bool operator>(const Date& other) const;
	bool operator<(const Date& other) const;
	bool operator>=(const Date& other) const;
	bool operator<=(const Date& other) const;
	Date& operator++();
	Date operator++(int);
	friend std::ostream& operator << (std::ostream& os, const Date& date);
	friend std::istream& operator >> (std::istream& is, Date& date);
};



