#include <iostream>
//#include <vector>
#include "header.h"

using namespace std;

int main() {
	// для векторов алгоритм equal работает некорректно в двух случаях
	// 1) когда у векторов разная длина
	// 2) когда у векторов одинаковая начальная длина, но потом она меняется
	/*vector<int> a(3);
	for (int i = 0; i < 3; i++)
		a.push_back(i);

	vector<int> b(3);
	for (int i = 0; i < 4; i++)
		b.push_back(i);*/

	// для обычных статических массивов алгоритм equal работает некорректно, если у массивов разная длина
	int a[3] = { 1, 2, 3 }; 
	int b[4] = { 1, 2, 3, 4 };
	

	cout << my_equal(begin(a), end(a), begin(b));

	return EXIT_SUCCESS;
}