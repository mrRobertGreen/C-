#include <iostream>
#include "utils.h" 

using namespace std;

int main() {
	// проверка работы ввода и вывода
	Array a(3);
	Array b(3, 1);
	Array c(a + b);
	c = a + b;

	return EXIT_SUCCESS;
}