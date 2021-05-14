
#include "header.h"
#include "array.h"
#include <iostream>

using namespace std;

int main() {
	Matrix<int> m1(3, 3);
	/*try
	{
		cout << m1.ones();
	}
	catch (const exception err)
	{
		cerr << err.what();
	}*/
	for (int i = 0; i < m1.get_rows_count(); i++)
		for (int j = 0; j < m1.get_cols_count(); j++)
			m1(i, j) = i + j;

	cout << m1 << "\n";
	cout << m1.minor(1, 1) << "\n";
	cout << m1.minor(1, 1).determinant() << "\n";
	cout << m1.algebraic_complement(1, 2) << "\n";
	

	return EXIT_SUCCESS;
}