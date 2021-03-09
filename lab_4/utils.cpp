#include <iostream>
#include <exception>
#include "utils.h"

using namespace std;

Array::Array() { // конструктор по умолчанию - создается массив на 10 элементов равных 0
	n = 10;
	arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
}
Array::Array(int _n, int x) { // конструктор с параметрами
	n = _n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = x;
}
Array::Array(const Array& B) { // констуктор копии
	n = B.n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = B.arr[i];
}
int Array::length() const { // длина массива
	return n;
}
Array Array::operator+(const Array& B) { // поэлементное сложение массивов
	if (n != B.n)
		throw exception("arrays have different lenghts");
	Array C(n);
	for (int i = 0; i < n; i++)
		C.arr[i] = arr[i] + B.arr[i];
	return C;
}
Array Array::operator+=(const Array& B) { // поэлементное прибавление массива
	if (n != B.n)
		throw exception("arrays have different lenghts");
	for (int i = 0; i < n; i++)
		arr[i] = arr[i] + B.arr[i];
	return *this;
}
Array Array::operator+(const int x) { // увеличение каждого элемента на x
	Array C(n);
	for (int i = 0; i < n; i++)
		C.arr[i] = arr[i] + x;
	return C;
}
Array& Array::operator=(const Array& B) { // присваивание массива
	if (this != &B) {
		delete[] arr;
		n = B.n;
		arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = B.arr[i];
	}
	return *this;
}
int& Array::operator[](int i) { // взятие элемента по индексу
	return arr[i];
}
int Array::operator[](int i) const { // взятие элемента по индексу (константный метод)
	return arr[i];
}
Array::~Array() { // удаление массива (деструктор)
	delete[] arr;
}
ostream& operator << (ostream& out, const Array& arr) { // вывод в поток
	for (int i = 0; i < arr.n; i++)
	{
		out << arr[i] << " ";
	}
	out << "\n";
	return out;
}
istream& operator >> (istream& in, Array& arr) { // ввод из потока
	for (int i = 0; i < arr.n; i++)
	{
		cout << "Enter array[" << i << "]: ";
		in >> arr[i];
	}
	return in;
}
int Array::find_index(int value) const { // поиск индекса элемента с заданным значением
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == value)
			return i;
	}
	throw exception("element with this value doesn't exist");
}
void Array::resize(int new_size) { // изменение размера массива
	int* new_arr = new int[new_size];
	int min_size = new_size < n ? new_size : n;
	for (int i = 0; i < min_size; i++)
		new_arr[i] = arr[i];
	delete[] arr;
	arr = new_arr;
	n = new_size;
}
Array& Array::push(int value) { // добавление элемента в конец массива
	this->resize(n + 1);
	arr[n - 1] = value;
	return *this;
}
Array& Array::insert(int value, int idx) { // вставка элемента в массив по индексу
	this->resize(n + 1);
	int temp_value;
	for (int i = idx; i < n; i++)
	{
		temp_value = arr[i];
		arr[i] = value;
		value = temp_value;
	}
	return *this;
}
Array& Array::remove_by_index(int idx) { // удаление элемента с заданным индексом
	if (idx < 0 || idx >= n)
		throw exception("invalid index");
	for (int i = idx; i < n - 1; i++)
		arr[i] = arr[i + 1];
	this->resize(n - 1);
	return *this;
}

// вспомогательные функции
bool are_equal_arrs(const Array& a, const Array& b) { // проверка на равенство двух массивов
	int a_len = a.length();
	int b_len = b.length();
	if (a_len != b_len)
		return false;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}