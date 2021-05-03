#include "header.h"
#include <exception>

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
		swap(this->key[a], this->key[b]);
	}
}

void Encoder::operator<<(string &data) {
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "Can't open " << filename << "\n";
		return;
	}
	string encoded_data = encode(data);
	file << encoded_data;
	file.close();
}
string Encoder::encode(string &data) {
	string res = "";
	const unsigned char* ptr = reinterpret_cast<unsigned char*>(&data);
	
	return res;
}