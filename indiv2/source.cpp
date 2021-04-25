#include <iostream>
#include "header.h"

using namespace std;

EncryptionKey::EncryptionKey() {
	// заполняем исходный
	for (int i = 0; i < 256; ++i)
		this->key[i] = static_cast<unsigned char>(i);

	int a, b;
	unsigned char c;
	// рандомно переставляем
	for (int i = 0; i < 5000; ++i) {
		a = rand() % 25;
		b = rand() % 256;
		c = this->key[a];
		this->key[a] = this->key[b];
		this->key[b] = c;
	}
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