#pragma once
#include <iostream>
#include <exception>
#include "array.h"

using namespace std;

template<typename T>
class Matrix;

template<typename T>
ostream& operator << (ostream& out, const Matrix<T> m);

template<typename T>
class Matrix {
private:
	int m, n;
	Array<Array<T>> data;

	T determinant();
public:
	Matrix(int m = 1, int n = 1) : m(m), n(n), data(m) {
		for (int i = 0; i < m; i++)
			data[i].resize(n);
	}
	int get_rows_count();
	int get_cols_count();
	Matrix<T>& ones();
	bool is_symmetric();
	double algebraic_complement(int m = 1, int n = 1) {};
	T operator()(int m, int n) {};
	Matrix<T>& operator+(Matrix<T> other) {};
	Matrix<T>& operator-(Matrix<T> other) {};
	Matrix<T>& operator*(Matrix<T> other) {};
	bool operator==(Matrix<T> other) {};
	bool operator!=(Matrix<T> other) {};

	friend ostream& operator<< <> (ostream& out, const Matrix<T> m);
};

template<typename T>
int Matrix<T>::get_rows_count() {
	return m;
}
template<typename T>
int Matrix<T>::get_cols_count() {
	return n;
}
template<typename T>
Matrix<T>& Matrix<T>::ones() {
	if (m != n) {
		throw exception("Can not be transformed into ones. Matrix isn't square.\n");
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			data[i][j] = (i == j) ? 1 : 0;
	return *this;
}
template<typename T>
ostream& operator << (ostream& out, const Matrix<T> matrix) {
	for (int i = 0; i < matrix.m; i++)
		out << matrix.data[i];
	return out;
}
template<typename T>
bool Matrix<T>::is_symmetric() {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (data[i][j] != data[j][i])
				return false;
		}
	return true;
}
template<typename T>
T Matrix<T>::determinant() {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{

		}
	}
}