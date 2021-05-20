#include <iostream>
#include "TreeRec.h"


TreeR:: TreeR(const TreeR * t) {
	if (t->lt) lt = new TreeR(t->lt);
	data = t->data;
	if (t->rt) rt = new TreeR(t->rt);
}

TreeR::~TreeR() {
	if (lt != nullptr) delete lt;
	if (rt != nullptr) delete rt;
}

 std::ostream & operator<<(std::ostream & os, const TreeR *t) {
	if (t->lt) os << t->lt;
	os << t->data << "  ";
	if (t->rt) os << t->rt;
	return os;
}

 void TreeR:: printRKL(int skip) {
	 if (rt) rt->printRKL(skip + 2);
	 for (int i = 0; i < skip; ++i)std::cout << "  ";
	 std::cout << data << "\n ";
	 if (lt) lt->printRKL(skip + 2);
 }
 void TreeR::insert(int x)
 {
	 if (rand() % 2 == 0)  // вставл€ем элемент в случайное поддерево
		 if (lt) lt->insert(x);
		 else lt = new TreeR(x);
	 else
		 if (rt) rt->insert(x);
		 else rt = new TreeR(x);
//функци€ rand() один раз генерирует  случайные числа, а при последующих запусках программы всего лишь отображает сгенерированные первый раз числа
// чтобы при каждом запуске получать разные случайные числа, необходимо в начале программы сбросить генератор 
// используйте дл€ этого вызов srand(time(0)); ƒл€функции time нужно подключить библиотеку <ctime>
 }