#include <iostream>
#include "utils.h" 

using namespace std;

int main() {
	Fract f1(2, 3), f2(3), f3(1, 2);
	cout << "f1=" << f1 << endl;
	cout << "f2=" << f2 << endl;
	cout << "f3=" << f3 << endl;
	Fract res = f1 + f2;
	cout << res << endl;
	res = f1 + f3;
	cout << res << endl;
	Fract sum;
	sum = sum + f1;
	sum = sum + f2;
	sum = sum + f3;
	cout << sum << endl;
	system("pause");

	return EXIT_SUCCESS;
}