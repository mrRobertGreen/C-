#include <iostream>
#include "utils.h" 

using namespace std;

int main() {
	listptr l1; 
	l1 = inputList();

	cout << "list -> ";
	printList(l1);
	cout << "reversed list -> ";
	printReverse(l1);


	deleteList(l1);

	return 0;
}