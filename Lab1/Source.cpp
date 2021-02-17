#include <iostream>
#include "Header.h" 

using namespace std;

int main() {
	listptr l1, l2 ; // elem_list* l1,*l2;
	listptr p, t;
	// создаем два списка
	l1 = nullptr; 
	for (int i = 0; i < 10; ++i)
	{
		p = new elem_list;
		p->val = i;
		p->next = l1;
		l1 = p;
	}

	l2 = nullptr; t = nullptr;
	t = l2 = new elem_list;
	l2->val = 0;
	l2->next = nullptr;
	for (int i = 1; i < 10; ++i) {
		t->next = new elem_list;
		t = t->next;
		t->val = i;
		t->next = nullptr;
	}
	//распечатываем
	//cout << " 1 list-> ";
	//p = l1;
	//while (p != nullptr) // while (p)
	//{
	//	cout << p->val << " -- ";
	//	p = p->next;
	//}
	//cout << endl;
	//cout << " 2 list-> ";
	//// другой вариант цикла
	//for (p = l2; p != nullptr; p = p->next) {
	//	cout << p->val << " -- ";
	//}
	//cout << endl;

	// удаляем
	p = l1;
	while (p != nullptr) // while (p)
	{
		l1 = l1->next;
		delete p;
		p = l1;
	}
	p = l2;
	while (p != nullptr) // while (p)
	{
		l2 = l2->next;
		delete p;
		p = l2;
	}
	t = nullptr; //!!!!

	system("pause");
	return 0;
}