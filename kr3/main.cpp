#include <iostream>
#include "header.h"

using namespace std;

int main() {
	List list;
	for (int i = 4; i > -1; i--)
		list.addFirst(i);

	list.insertSumBetween();
	cout << list;
	
	return EXIT_SUCCESS;
}