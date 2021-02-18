#pragma once

struct elem_list {
	int val;
	char buf[1024] = "";
	elem_list* next;
};

typedef elem_list* listptr;

void deleteList(listptr& head);
void printList(listptr head);
listptr inputList();
int listLength(listptr head);
int countOf(listptr head, int value);
listptr findItemByValue(int value, listptr head);
void insertAfter(int item, listptr& head, int value);
void unshift(listptr& head, int item);
void push(listptr& head, int item);
void deleteItemByValue(listptr& head, int value);
void deleteAllItemsByValue(listptr& head, int value);
listptr arrToList(int* arr, int len);
int listItemsSum(listptr head);
int countOfRecursion(listptr head, int value);
int maxItemByValue(listptr head, int max = INT_MIN);
void printReverse(listptr head);
bool isEqual(listptr head1, listptr head2);