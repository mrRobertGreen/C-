#include <iostream>
#include "header.h"

using namespace std;

int main() {
	string filename, str;
	cout << "enter file name: ";
	cin >> filename;
	cout << "enter data: ";
	cin.ignore();
	getline(cin, str, '\n');
	cout << "initial data: " << str << "\n";
	Encoder encoder(filename);
	encoder << str;

	ifstream file(filename);
	cout << "encoded data: ";
	cout << encoder;
	cout << "\n";

	Decoder decoder = encoder.create_decoder();
	cout << "decoded data: " << decoder;
	return EXIT_SUCCESS;
}