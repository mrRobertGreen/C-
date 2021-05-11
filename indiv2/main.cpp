#include <iostream>
#include "header.h"

using namespace std;

int main() {
	/*EncryptionKey a;
	a.print();*/

	string str = "hello";
	Encoder encoder("test.txt");
	encoder << str;
	string s;
	Decoder dec("test.txt");
	dec >> s;
	cout << s;

	return EXIT_SUCCESS;
}