#include <iostream>
#include "header.h"

using namespace std;

int main() {
	string filename = "test.txt";
	string str = "hello";
	cout << "initial data: " << str << "\n";
	Encoder encoder(filename);
	encoder << str;

	ifstream file(filename);
	char ch;
	cout << "encoded data: ";
	while (file >> ch)
		cout << ch;
	cout << "\n";

	string decoded;
	Decoder decoder = encoder.create_decoder();
	decoder >> decoded;
	cout << "decoded data: " << decoded << "\n";
	

	return EXIT_SUCCESS;
}