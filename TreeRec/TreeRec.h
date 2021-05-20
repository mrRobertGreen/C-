#pragma once
#include <iostream>

// �������� ���� ������:
//     data - �������� � ���� ������;
//     lt - �������� �� ����� ���������;
//     rt - ��������� �� ������ ���������.

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



