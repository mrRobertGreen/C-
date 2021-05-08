
#include "header.h"
#include "array.h"
#include <iostream>

using namespace std;

int main() {
	Matrix<int> m1(4, 4);
	m1.ones();
	cout << m1;

	return EXIT_SUCCESS;
}