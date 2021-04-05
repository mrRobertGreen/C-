#include <iostream>
#include "Lab8.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	Student s("Alex", 18, "SFU", 3);
	s.setMark(0, 5);
	s.setMark(1, 4);
	cout << s;
	Student s1(s);
	cout << s1;
	Student s2;
	cout << s2;
	s2 = s1;
	cout << s2;
	//для проверки совместимости типов
	Person p("Dimon", 20);
	Student sp("Robert", 19, "DSTU", 3);
	p = sp;
	sp.setMark(0, 5);
	cout << p;
	// sp = p; будет ошибка компиляции
	Person* pp = &p;
	Student* ss = &sp;
	pp = ss;
	cout << *pp;
	cout << *(Student*)pp; //downcast
	//ss = pp; // ошибка компиляции
	Person& rp = sp;
	//Student& rs = p; // ошибка компиляции

	return 0;
}