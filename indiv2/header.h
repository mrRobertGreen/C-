#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class EncryptionKey {
private:
	unsigned char* key[256];
public:
	EncryptionKey() {};
};

class Encoder : public EncryptionKey {
public: 
	string filename;
private:
	Encoder(string filename) : filename(filename) { EncryptionKey(); };
	void encode();
	Decoder& create_decoder();

	friend ifstream& operator<<(ifstream& fin, string filename);
};

class Decoder : public EncryptionKey {
public:
	string filename;
private:
	Decoder(string filename) : filename(filename) {};
	void decode();

	friend ostream& operator>>(ofstream& fout, string filename);
};
