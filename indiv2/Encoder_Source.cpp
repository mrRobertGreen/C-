#include "header.h"
#include <exception>

using namespace std;

void Encoder::operator<<(string& data) {
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "Can't open " << filename << "\n";
		return;
	}
	string encoded_data = simple_encode(data); // �������� ������
	//string encoded_data = encode(data); // �������� ������
	file << encoded_data; // ���������� ������ � ����
	file.close();
}
string Encoder::simple_encode(string& data) {
	string res = "";
	int idx;
	for (int i = 0; i < data.length(); i++)
	{
		idx = static_cast<int>(data[i]);
		res += key[idx];
	}
	return res;
}
string Encoder::encode(string& data) {
	string res = "";
	unsigned char* ptr = reinterpret_cast<unsigned char*>(&data); // ����������� ���������

	/*cout << "sizeof (data[0]): " << sizeof(data[0]) << "\n";
	cout << "sizeof (data): " << sizeof(data) << "\n";
	cout << "data.capacity(): " << data.capacity() << "\n";*/

	int size = sizeof(data);
	int idx;
	while (size) { // ���������� ����� ���������� �� ������
		idx = static_cast<int>(*ptr); // ����������� unsigned char � int
		res += key[idx]; // ���������� ���������� int ��� ������ �������-�����
		++ptr;
		--size;
	}

	return res;
}

Decoder Encoder::create_decoder() {
	return Decoder(filename, key);
}
string Encoder::get_filename() {
	return this->filename;
}
bool Encoder::operator==(Encoder encoder) {
	bool res = true;
	for (int i = 0; i < 256; i++)
		res &= this->key[i] == encoder.get_key()[i];
	return this->filename == encoder.filename && res;
}

ostream& operator<<(ostream& os, Encoder encoder) {
	
}