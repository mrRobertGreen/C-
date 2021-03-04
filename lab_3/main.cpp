#include <iostream>
#include "utils.h" 

using namespace std;

int main() {
	Date d1(1, MONTH::FEBRUARY, 2020);
	d1.add_days(30);
	cout << d1 << "\n";
	/*d1++;
	cout << ++d1 << "\n";
	cin >> d1;

	cout << d1;*/
	return EXIT_SUCCESS;
}