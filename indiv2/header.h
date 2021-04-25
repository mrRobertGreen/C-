#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class EncryptionKey {
protected:
	unsigned char key[256];
public:
	EncryptionKey();

	void print() {
		cout << "key: " << endl;
		for (int i = 0; i < 256; ++i) {
			cout << key[i];
		}
	};
};

class Encoder : public EncryptionKey {
private: 
	string filename;
public:
	Encoder(string filename) : filename(filename) { EncryptionKey(); };
	void encode();
	//Decoder create_decoder();

	friend ifstream& operator<<(ifstream& fin, string filename);
};

class Decoder : public EncryptionKey {
private:
	string filename;
public:
	Decoder(string filename) : filename(filename) {};
	void decode();

	friend ostream& operator>>(ofstream& fout, string filename);
};
