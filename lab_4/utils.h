#pragma once
#include <iostream>

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
	int find_index(int value) const;
	void resize(int new_size);
	Array& push(int value);
	Array& insert(int value, int idx);
	Array& remove_by_index(int idx);

	// дружественные функции
	friend ostream& operator << (ostream& out, const Array& arr);
	friend istream& operator >> (istream& in, Array& arr);
};

bool are_equal_arrs(const Array& a, const Array& b);