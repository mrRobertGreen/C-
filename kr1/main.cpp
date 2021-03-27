#include <iostream>
#include "utils.h" 
#include <exception>

using namespace std;

int main() {
	try
	{
		Measurer size1(3, 5), size2;
		cout << "Your size1:" << "\n";
		cout << size1 << "\n";
		cin >> size1;
		cout << "Your new size1:" << "\n";
		cout << size1 << "\n";
		cout << "Your new size1 in centimetres:" << "\n";
		cout << size1.to_centimetres() << "cm." << "\n";

		cout << "Enter size2" << "\n";
		cin >> size2;
		cout << "Your size2:" << "\n";
		cout << size2 << "\n";
		cout << "size1 == size2: " << (size1 == size2) << "\n";
		cout << "size1 < size2: " << (size1 < size2) << "\n";
		cout << "size1 - size2: " << (size1 < size2) << "\n";
		int x;
		cout << "Enter count of centimetres: ";
		cin >> x;
		size1 += x;
		cout << "size1 += " << x << " = " << size1;

	}
	catch (const exception& err)
	{
		cerr << err.what();
	}

	return EXIT_SUCCESS;
}