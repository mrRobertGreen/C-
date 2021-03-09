#include <iostream>
#include "utils.h" 

using namespace std;

int main() {
	// проверка работы ввода и вывода
	Array a(3);

	cout << a;
	cin >> a;
	cout << a;

	return EXIT_SUCCESS;
}