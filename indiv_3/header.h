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
public:
	Matrix(int m = 1, int n = 1) : m(m), n(n), data(m) {
		for (int i = 0; i < m; i++)
			data[i].resize(n);
	}
	int get_rows_count();
	int get_cols_count();
	Matrix<T>& ones();
	Matrix<T>& random();
	bool is_symmetric();
	T algebraic_complement(int i = 1, int j = 1) const;
	T determinant() const;
	Matrix<T> minor(int i, int j) const;
	T& operator()(int i, int j);
	T operator()(int i, int j) const;
	Matrix<T> operator+(Matrix<T> other) const;
	Matrix<T> operator-(Matrix<T> other) const;
	Matrix<T> operator*(Matrix<T> other) const;
	bool operator==(Matrix<T> other) const;
	bool operator!=(Matrix<T> other) const;

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
Matrix<T>& Matrix<T>::random() {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			data[i][j] = rand() / 777.;
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
	if (m != n)
		return false;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (data[i][j] != data[j][i])
				return false;
		}
	return true;
}
template<typename T>
Matrix<T> Matrix<T>::minor(int i, int j) const {
	Matrix<T> minor = Matrix(this->m - 1, this->n - 1);
	int minor_row = 0, minor_col;
	for (int row = 0; row < this->m; row++)
	{
		if (row == i)
			continue;
		minor_col = 0;
		for (int col = 0; col < this->n; col++)
		{
			if (col == j)
				continue;
			minor(minor_row, minor_col) = data[row][col];
			++minor_col;
		}
		++minor_row;
	}
	return minor;
}
template<typename T>
T Matrix<T>::algebraic_complement(int i, int j) const {
	return pow(-1, i + j) * this->minor(i, j).determinant();
}
template<typename T>
T Matrix<T>::determinant() const {
	T res = 0;
	if (m == 1) {
		return data[0][0];
	}
	if (m == 2) {
		return data[0][0] * data[1][1] - data[0][1] * data[1][0];
	}
	for (int j = 0; j < n; j++)
	{
		T elem = data[0][j];
		Matrix<T> minor = this->minor(0, j);
		res += pow(-1, j) * minor.determinant();
	}
	return res;
}
template<typename T>
T& Matrix<T>::operator()(int i, int j) {
	return data[i][j];
}
template<typename T>
T Matrix<T>::operator()(int i, int j) const {
	return data[i][j];
}
template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> other) const {
	if (other.m != this->m || other.n != this->n)
		throw exception("matrixes have different sizes");
	Matrix<T> res = Matrix<T>(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			res(i, j) = data[i][j] + other(i, j);
	return res;
}
template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> other) const {
	if (other.m != this->m || other.n != this->n)
		throw exception("matrixes have different sizes");
	Matrix<T> res = Matrix<T>(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			res(i, j) = data[i][j] - other(i, j);
	return res;
}
template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> other) const {
	if (other.m != this->n || other.n != this->m)
		throw exception("matrix's sizes are unsuitable for multiplication");
	Matrix<T> res = Matrix<T>(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			res(i, j) = data[i][j] * other(j, i);
	return res;
}
template<typename T>
bool Matrix<T>::operator==(Matrix<T> other) const {
	if (other.m != m || other.n != n)
		return false;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (other(i, j) != data[i][j])
				return false;
		}
	return true;
}
template<typename T>
bool Matrix<T>::operator!=(Matrix<T> other) const {
	return !(*this == other);
}