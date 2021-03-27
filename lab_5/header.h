#pragma once
#include <iostream>
#include <string>

using namespace std;

class Array {
private:
	int n;
	int* arr;
public:
	Array(); //конструктор по умолчанию
	Array(int _n, int x = 0); //конструктор с параметрами
	Array(const Array& other); //конструктор копии
	~Array(); // деструктор
	// методы
	int length() const;
	Array operator+(const Array& arr);
	Array operator+=(const Array& arr);
	Array operator+(const int x);
	Array& operator=(const Array& arr);
	int& operator[](int i);
	int operator[](int i) const;
	int operator==(const Array& arr) const;
	int operator!=(const Array& arr) const;
	int find_index(int value) const;
	void resize(int new_size);
	Array& push(int value);
	Array& insert(int value, int idx);
	Array& remove_by_index(int idx);

	// дружественные функции
	friend ostream& operator << (ostream& out, const Array& arr);
	friend istream& operator >> (istream& in, Array& arr);
};

class BigNum {
private:
	bool is_negative;
	Array digits;
public:
	BigNum();
	BigNum(int n);
	BigNum(const string str);
	BigNum(const BigNum& other);

	operator int();
	operator string();
	BigNum& operator=(const BigNum& num);
	int operator[](int idx) const;
	bool operator==(const BigNum& num) const;
	bool operator!=(const BigNum& num) const;
	bool operator>(const BigNum& num) const;
	bool operator>=(const BigNum& num) const;
	bool operator<(const BigNum& num) const;
	bool operator<=(const BigNum& num) const;
	BigNum operator+(const BigNum& num) const;
	bool get_is_negative();
	Array get_digits();

	friend ostream& operator << (ostream& out, const BigNum& num);
	friend istream& operator >> (istream& in, BigNum& num);
};