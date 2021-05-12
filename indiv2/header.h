#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class EncryptionKey {
protected:
	unsigned char key[256];
public:
	EncryptionKey();
	EncryptionKey(unsigned char key[256]) {
		for (int i = 0; i < 256; i++)
			this->key[i] = key[i];
	};
	int find_index(unsigned char value);

	void print();
};

class Decoder : public EncryptionKey {
private:
	string filename;

	string simple_decode(string data);
	string decode(string data);
public:
	Decoder(string filename, unsigned char key[256]) : filename(filename),  EncryptionKey(key) {};

	void operator>>(string& data);
};

class Encoder : public EncryptionKey {
private:
	string filename;

	string simple_encode(string& data);
	string encode(string& data);
public:
	Encoder(string filename) : filename(filename) { EncryptionKey(); };
	Decoder create_decoder();

	void operator<<(string& data);
};

