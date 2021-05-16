
#include "header.h"
#include "array.h"
#include <iostream>

using namespace std;

int main() {
	/* JUST EXAMPLES */

	/*Matrix<int> m1(3, 3);
	Matrix<int> m2(3, 3);
	try
	{
		cout << "m1.ones():\n" << m1.ones() << "\n";
	}
	catch (const exception err)
	{
		cerr << err.what();
	}
	for (int i = 0; i < m1.get_rows_count(); i++)
		for (int j = 0; j < m1.get_cols_count(); j++)
			m1(i, j) = i + j;

	for (int i = 0; i < m2.get_rows_count(); i++)
		for (int j = 0; j < m2.get_cols_count(); j++)
			m2(i, j) = i - j;

	cout << "m1:\n"<< m1 << "\n";
	cout << "m2:\n" << m2 << "\n";
	cout << "m1 + m2:\n" << m1 + m2 << "\n";
	cout << "m1 * m2:\n" << m1 * m2 << "\n";
	cout << "m1 == m2: " << (m1 == m2) << "\n";
	cout << "m1 == m1: "<< (m1 == m1) << "\n";
	cout << "m1 != m1: " << (m1 != m1) << "\n";*/

	/* 
	ЗАДАЧА
	Используя матрицу вещественных чисел решить задачу: Даны две квадратные
	матрицы. Найти их произведение и проверить, является ли оно симметричной
	матрицей.
	*/
	Matrix<double> M1 = Matrix<double>(3, 3).random();
	Matrix<double> M2 = Matrix<double>(3, 3).random();

	cout << "M1:\n" << M1 << "\n";
	cout << "M2:\n" << M2 << "\n";

	Matrix<double> M3 = M1 * M2;

	cout << "M3 = M1 * M2:\n" << M3 << "\n";
	cout << "M3 is symmetric: " << (M3.is_symmetric() ? "true" : "false")<< "\n";


	return EXIT_SUCCESS;
}