#include "header.h"
#include <exception>

using namespace std;


string Decoder::simple_decode(string data) {
	string res = "";
	int idx;
	for (int i = 0; i < data.length(); i++)
	{
		idx = find_index(data[i]);
		res += static_cast<unsigned char>(idx);
	}

	return res;
}
string Decoder::decode(string data) {
	string res = "";
	unsigned char* ptr = reinterpret_cast<unsigned char*>(&data); // преобразуем указатель

	int idx;
	int size = sizeof(data);
	while (size)
	{ // проходимся новым указателем по строке
		idx = find_index(*ptr);
		res += static_cast<unsigned char>(idx);
		++ptr;
		--size;
	}

	return res;
}

void Decoder::operator>>(string& data) {
	ifstream file(filename);
	data = "";
	if (!file.is_open()) {
		cerr << "Can't open " << filename << "\n";
		return;
	}
	string encoded;
	while (getline(file, encoded)) {
		data += this->simple_decode(encoded);
		//data += this->decode(encoded);
	}

	file.close();
}
string Decoder::get_filename() {
	return this->filename;
}
bool Decoder::operator==(Decoder decoder) {
	bool res = true;
	for (int i = 0; i < 256; i++)
		res &= this->key[i] == decoder.key[i];
	return this->filename == decoder.filename && res;
}
void Decoder::decode_file() {
	fstream file(filename);
	string data = "";
	if (!file.is_open()) {
		cerr << "Can't open " << filename << "\n";
		return;
	}
	string encoded;
	while (getline(file, encoded)) {
		data += this->simple_decode(encoded);
	}
	file << data;
}

ostream& operator<<(ostream& os, Decoder decoder) {
	string data;
	decoder >> data;
	os << data;
	return os;
}
istream& operator>>(istream& is, Decoder& decoder) {
	is >> decoder.filename; // самый логичный вариант - ввод нового файла
	return is;
};