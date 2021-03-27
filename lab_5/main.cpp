#include <iostream>
#include "header.h" 

using namespace std;

int main() {
	BigNum num1;
	BigNum num2(-345);
	BigNum num3("345");

	cout << num1 << "\n";
	cout << num2 << "\n";
	cout << num3 << "\n";

	cout << static_cast<int>(num2) << "\n";
	cout << static_cast<string>(num2);


	return EXIT_SUCCESS;
}