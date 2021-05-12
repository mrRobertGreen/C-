#include <iostream>
#include "header.h"

using namespace std;

int main() {
	/*EncryptionKey a;
	a.print();*/

	string str = "hello";
	Encoder encoder("test.txt");
	encoder.print();
	encoder << str;
	string s;
	//Decoder dec("test.txt");
	//dec >> s;
	Decoder decoder = encoder.create_decoder();
	decoder >> s;
	cout << s;
	/*encoder.print();
	decoder.print();*/

	//cout << static_cast<int>(static_cast<char>(5));
	

	return EXIT_SUCCESS;
}