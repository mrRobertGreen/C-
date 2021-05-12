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
	ofstream key_file("key.txt");
	key_file << key;
	key_file.close();
}
void EncryptionKey::print() {
	cout << "key: " << endl;
	for (int i = 0; i < 256; ++i) {
		cout << i << ": " << key[i] << "\n";
	}
};
int EncryptionKey::find_index(unsigned char value) {
	int idx = 0;
	while (value != key[idx]) ++idx;
	return idx;
}

void Encoder::operator<<(string& data) {
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "Can't open " << filename << "\n";
		return;
	}
	string encoded_data = encode(data); // кодируем данные
	file << encoded_data; // записываем данные в файл
	file.close();
}
string Encoder::encode(string& data) {
	string res = "";
	//unsigned char* ptr = reinterpret_cast<unsigned char*>(&data); // преобразуем указатель
	
	
	/*cout << "sizeof (data[0]): " << sizeof(data[0]) << "\n";
	cout << "sizeof (data): " << sizeof(data) << "\n";
	cout << "data.capacity(): " << data.capacity() << "\n";*/
	//int size = sizeof(data);
	int idx;
	for (int i = 0; i < data.length(); i++)
	{
		idx = static_cast<int>(data[i]);
		res += key[idx];
	}
	//while (size) { // проходимся новым указателем по строке
	//	; // преобразуем unsigned char в int
	//	 // используем полученный int как индекс массива-ключа
	//	++ptr;
	//	--size;
	//}
	
	return res;
}

string Decoder::decode(string data) {
	
	//cout << "encoded data: " << data << "\n";
	string res = "";
	//unsigned char* ptr = reinterpret_cast<unsigned char*>(&data); // преобразуем указатель
	int idx;
	for (int i = 0; i < data.length(); i++)
	{
		idx = find_index(data[i]);
		res += key[idx];
	}

	
	//while (size) { // проходимся новым указателем по строке
	//	idx = find_index(*data);
	//	//idx = static_cast<int>(*ptr); // преобразуем unsigned char в int
	//	res += key[idx]; // используем полученный int как индекс массива-ключа
	//	++data;
	//	--size;
	//}

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
		data += this->decode(encoded);
	}
	file.close();
}
Decoder Encoder::create_decoder() {
	return Decoder(filename, key);
}