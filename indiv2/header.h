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
	unsigned char* get_key();
	void print();
};

class Decoder : public EncryptionKey {
private:
	string filename;

	string simple_decode(string data);
	string decode(string data);
public:
	Decoder(string filename, unsigned char key[256]) : filename(filename), EncryptionKey(key) {};
	string get_filename();
	void decode_file();

	void operator>>(string& data);
	bool operator==(Decoder decoder);
	//bool operator==(Encoder encoder);
};

class Encoder : public EncryptionKey {
private:
	string filename;

	string simple_encode(string& data);
	string encode(string& data);
public:
	Encoder(string filename) : filename(filename) {
		EncryptionKey();
		ofstream key_file(filename.substr(0, filename.size() - 4) + "_key.txt");
		key_file << key;
		key_file.close();
	};
	Decoder create_decoder();
	string get_filename();


	void operator<<(string& data);
	//bool operator==(Decoder decoder);
	bool operator==(Encoder encoder);
};

