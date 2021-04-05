#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Array {
private:
	int n;
	T* arr;
public:
	Array(); //конструктор по умолчанию
	Array(int _n, T x); //конструктор с параметрами
	Array(const Array& other); //конструктор копии
	~Array(); // деструктор
	// методы
	int length() const;
	Array operator+(const Array& arr);
	Array operator+=(const Array& arr);
	Array operator+(const int x);
	Array& operator=(const Array& arr);
	T& operator[](int i);
	T operator[](int i) const;
	bool operator==(const Array& arr) const;
	bool operator!=(const Array& arr) const;
	int find_index(T value) const;
	void resize(int new_size);
	Array& push(T value);
	Array& insert(T value, int idx);
	Array& remove_by_index(int idx);

	// дружественные функции
	friend ostream& operator << (ostream& out, const Array& arr);
	friend istream& operator >> (istream& in, Array& arr);
};

template <typename T>
Array<T>::Array() { // конструктор по умолчанию - создается массив на 10 элементов равных 0
	n = 10;
	arr = new T[n];
	for (int i = 0; i < n; i++)
		arr[i] = T();
}
template <typename T>
Array<T>::Array(int _n, T x) { // конструктор с параметрами
	n = _n;
	arr = new T[n];
	for (int i = 0; i < n; i++)
		arr[i] = x;
}
template <typename T>
Array<T>::Array(const Array& B) { // констуктор копии
	n = B.n;
	arr = new T[n];
	for (int i = 0; i < n; i++)
		arr[i] = B.arr[i];
}
template <typename T>
int Array<T>::length() const { // длина массива
	return n;
}
template <typename T>
Array<T> Array<T>::operator+(const Array<T>& B) { // поэлементное сложение массивов
	if (n != B.n)
		throw exception("arrays have different lenghts");
	Array C(n);
	for (int i = 0; i < n; i++)
		C.arr[i] = arr[i] + B.arr[i];
	return C;
}
template <typename T>
Array<T> Array<T>::operator+=(const Array<T>& B) { // поэлементное прибавление массива
	if (n != B.n)
		throw exception("arrays have different lenghts");
	for (int i = 0; i < n; i++)
		arr[i] = arr[i] + B.arr[i];
	return *this;
}
template <typename T>
Array<T> Array<T>::operator+(const int x) { // увеличение каждого элемента на x
	Array C(n);
	for (int i = 0; i < n; i++)
		C.arr[i] = arr[i] + x;
	return C;
}
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& B) { // присваивание массива
	if (this != &B) {
		delete[] arr;
		n = B.n;
		arr = new T[n];
		for (int i = 0; i < n; i++)
			arr[i] = B.arr[i];
	}
	return *this;
}
template <typename T>
T& Array<T>::operator[](int i) { // взятие элемента по индексу
	return arr[i];
}
template <typename T>
T Array<T>::operator[](int i) const { // взятие элемента по индексу (константный метод)
	return arr[i];
}
template <typename T>
Array<T>::~Array() { // удаление массива (деструктор)
	delete[] arr;
}
template <typename T>
ostream& operator << (ostream& out, const Array<T>& arr) { // вывод в поток
	for (int i = 0; i < arr.n; i++)
	{
		out << arr[i] << " ";
	}
	out << "\n";
	return out;
}
template <typename T>
istream& operator >> (istream& in, Array<T>& arr) { // ввод из потока
	for (int i = 0; i < arr.n; i++)
	{
		cout << "Enter array[" << i << "]: ";
		in >> arr[i];
	}
	return in;
}
template <typename T>
bool Array<T>::operator==(const Array<T>& arr) const {
	if (arr.length() != n)
		return false;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != this->arr[i])
			return false;
	}
	return true;
}
template <typename T>
bool Array<T>::operator!=(const Array<T>& arr) const {
	return !(*this == arr);
}
template <typename T>
int Array<T>::find_index(T value) const { // поиск индекса элемента с заданным значением
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == value)
			return i;
	}
	throw exception("element with this value doesn't exist");
}
template <typename T>
void Array<T>::resize(int new_size) { // изменение размера массива
	int* new_arr = new int[new_size];
	int min_size = new_size < n ? new_size : n;
	for (int i = 0; i < min_size; i++)
		new_arr[i] = arr[i];
	delete[] arr;
	arr = new_arr;
	n = new_size;
}
template <typename T>
Array<T>& Array<T>::push(T value) { // добавление элемента в конец массива
	this->resize(n + 1);
	arr[n - 1] = value;
	return *this;
}
template <typename T>
Array<T>& Array<T>::insert(T value, int idx) { // вставка элемента в массив по индексу
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
template <typename T>
Array<T>& Array<T>::remove_by_index(int idx) { // удаление элемента с заданным индексом
	if (idx < 0 || idx >= n)
		throw exception("invalid index");
	for (int i = idx; i < n - 1; i++)
		arr[i] = arr[i + 1];
	this->resize(n - 1);
	return *this;
}