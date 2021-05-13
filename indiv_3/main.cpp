
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
	cout << m1;
	cout << m1.is_symmetric();
		
	

	return EXIT_SUCCESS;
}