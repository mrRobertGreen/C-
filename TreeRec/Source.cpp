#include <iostream>
#include <ctime>
#include "TreeRec.h"

using namespace std;

int main() {
	TreeR *t = new TreeR();// это непустое дерево
	srand(time(0));
	t->insert(5);
	t->insert(-7);
	t->insert(3);
	t->insert(-4);
	t->printRKL();
	cout << "T " << t << endl;
	t->printRKL();
	TreeR *t1 = new TreeR(t);
	cout << "T1 " << t1 << endl;
	t1->printRKL(0);
	delete t;
	delete t1;
	return 0;
}