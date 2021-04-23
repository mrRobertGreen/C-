#include <iostream>
#include "header.h"

using namespace std;

EncryptionKey::EncryptionKey() {
	// TODO: @alex написать генерацию ключа шифрования
}

void Encoder::encode() {
	fstream file(filename, fstream::in, fstream::out);
	if (!file.is_open()) {
		cerr << "Can't open " << filename << "\n";
		return;
	}
	char symb;
	string data;
	while (file.get(symb)) {
		data.push_back(symb);
		
	}
}