#pragma once

struct elem_list {
	int val;
	char buf[1024]=""; //��� ��������� ����, ������������ ������ ��� �������� ������ ������
	elem_list* next;
};

typedef elem_list* listptr;