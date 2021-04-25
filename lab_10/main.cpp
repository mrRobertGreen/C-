#include <iostream>
#include "header.h"

using namespace std;

int main() {

	List list;
	for (int i = 4; i > -1; i--)
		list.addFirst(i);

	for (int i = 5; i < 10; i++)
		list.addLast(i);
	cout << list;

	cout << "Count of odd: " << list.count(odd) << "\n";

	list.for_each(mult2);
	cout << "After x2 operation:\n";
	cout << list;

	cout << "Count of odd: " << list.count(odd) << "\n";

	ListIterator iter = list.begin();

	cout << "Print with using iterator:\n";
	while (iter != list.end())
	{
		cout << *iter << " ";
		++iter;
	}

	for (int i = 0; i < 5; ++i)
		list.delLast();
	cout << "\nAfter removing 5 last elements:\n";
	cout << list << "\n";

	return EXIT_SUCCESS;
}