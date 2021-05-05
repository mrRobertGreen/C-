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

	void print();
};

class Decoder : public EncryptionKey {
private:
	string filename;
public:
	Decoder(string filename) : filename(filename) {};
	void decode();

	ostream& operator>>(ostream out);
};

class Encoder : public EncryptionKey {
private: 
	string filename;

	string encode(string& data);
public:
	Encoder(string filename) : filename(filename) { EncryptionKey(); };
	Decoder create_decoder();

	void operator<<(string &data);
};

