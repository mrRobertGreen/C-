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
void EncryptionKey::print() {
	cout << "key: " << endl;
	for (int i = 0; i < 256; ++i) {
		cout << i << ": " << key[i] << "\n";
	}
};
unsigned char* EncryptionKey::get_key() {
	return this->key;
}
int EncryptionKey::find_index(unsigned char value) {
	int idx = 0;
	while (value != key[idx]) ++idx;
	return idx;
}

