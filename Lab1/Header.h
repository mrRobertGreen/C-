#pragma once

struct elem_list {
	int val;
	char buf[1024]=""; //это фиктивное поле, используется только для контроля утечки памяти
	elem_list* next;
};

typedef elem_list* listptr;