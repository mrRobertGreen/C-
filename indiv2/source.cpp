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
		cout << key[i];
	}
};

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
	unsigned char* ptr = reinterpret_cast<unsigned char*>(&data); // преобразуем указатель
	/*cout << "sizeof (data[0]): " << sizeof(data[0]) << "\n";
	cout << "sizeof (data): " << sizeof(data) << "\n";
	cout << "data.capacity(): " << data.capacity() << "\n";*/
	int size = sizeof(data);
	int idx;
	while (size) { // проходимся новым указателем по строке
		idx = static_cast<int>(*ptr); // преобразуем unsigned char в int
		res += key[idx]; // используем полученный int как индекс массива-ключа
		++ptr;
		--size;
	}

	return res;
}