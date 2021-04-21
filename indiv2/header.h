#pragma once
#include <iostream>

using namespace std;

class EncryptionKey {
private:
	unsigned char* key[256];

	void generate_key();  // TODO: @alex написать генерацию ключа шифрования
public:
	EncryptionKey() {};
};