#pragma once
#include <iostream>

// Описание узла дерева:
//     data - значение в узле дерева;
//     lt - укзатель на левое поддерево;
//     rt - указатель на правое поддерево.

class TreeR {
private:
	int data;
	TreeR *lt, *rt;
public:
	TreeR(int val = 0, TreeR *l = nullptr, TreeR *r = nullptr) :
		data(val), lt(l), rt(r) {}

	TreeR(const TreeR * t); 
	~TreeR(); 
	friend std::ostream & operator<<(std::ostream & os, const TreeR *t); 
	void printRKL(int skip = 0); 
	void insert(int x);
};



