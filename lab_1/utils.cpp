#include <iostream>
#include <exception>
#include "utils.h"

using namespace std;

void deleteList(listptr& head) {
	listptr ptr = nullptr;
	while (head) {
		ptr = head->next;
		delete head;
		head = ptr;
	}
	delete ptr;
}
void printList(listptr head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
listptr inputList() {
	int len;
	listptr head = nullptr, cur = nullptr, prev = nullptr;
	cout << "Enter list length: ";
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		cur = new elem_list;
		cout << "Enter " << i + 1 << " item: ";
		cin >> cur->val;
		cur->next = nullptr;
		if (prev) {
			prev->next = cur;
		}
		prev = cur;
		if (i == 0) {
			head = cur;
		}
	}
	return head;
}
int listLength(listptr head) {
	int len = 0;
	while (head)
	{
		++len;
		head = head->next;
	}
	return len;
}
int countOf(listptr head, int value) {
	int count = 0;
	while (head)
	{
		if (head->val == value)
		{
			++count;
		}
		head = head->next;
	}
	return count;
}
listptr findItemByValue(int value, listptr head) {
	while (head)
	{
		if (head->val == value)
		{
			return head;
		}
		head = head->next;
	}
	return nullptr;
}
void insertAfter(int item, listptr& head, int value) {
	listptr ptr = head;
	while (ptr && ptr->val != value)
	{
		ptr = ptr->next;
	}
	if (ptr) {
		ptr = ptr->next;
		if (ptr)
		{
			unshift(ptr, item);
		}
		else {
			push(head, item);
		}
	}
	else {
		throw invalid_argument("item with this value doesn't exist");
	}
}
void unshift(listptr& head, int item) {
	int saver, inserter = item;
	while (head->next)
	{
		saver = head->val;
		head->val = inserter;
		head = head->next;
		inserter = saver;
	}
	saver = head->val;
	head->val = inserter;
	inserter = saver;
	listptr final = new elem_list;
	final->val = inserter;
	final->next = nullptr;
	head->next = final;
}
void push(listptr& head, int item) {
	listptr ptr = head;
	while (ptr->next) ptr = ptr->next;
	listptr new_item = new elem_list;
	new_item->val = item;
	new_item->next = nullptr;
	ptr->next = new_item;
}
void deleteItemByValue(listptr& head, int value) {
	listptr ptr = head, prev = nullptr, next = nullptr;
	while (ptr && ptr->val != value)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (!ptr)
	{
		throw invalid_argument("item with this value doesn't exist");
	}
	next = ptr->next;
	delete ptr;
	if (prev)
	{
		prev->next = next;
	}
	else { // если был удален первый элемент
		head = next;
	}
}
void deleteAllItemsByValue(listptr& head, int value) {
	while (countOf(head, value) != 0)
	{
		deleteItemByValue(head, value);
	}
}
listptr arrToList(int* arr, int len) {
	listptr head = nullptr, ptr = nullptr, tail = nullptr;
	for (int i = 0; i < len; i++)
	{
		if (i == 0)
		{
			head = tail = new elem_list;
			head->val = arr[i];
			head->next = nullptr;
		}
		else
		{
			ptr = new elem_list;
			ptr->val = arr[i];
			ptr->next = nullptr;
			tail->next = ptr;
			tail = ptr;
		}
	}
	return head;
}
int listItemsSum(listptr head) {
	if (!head)
	{
		return 0;
	}
	else
	{
		return head->val + listItemsSum(head->next);
	}
}
int countOfRecursion(listptr head, int value) {
	if (!head)
	{
		return 0;
	}
	else
	{
		const int count = head->val == value ? 1 : 0;
		return count + countOfRecursion(head->next, value);
	}
}
int maxItemByValue(listptr head, int max) {
	if (!head)
	{
		if (max == INT_MIN)
		{
			throw invalid_argument("list is empty");
		}
		else
		{
			return max;
		}
	}
	else
	{
		max = head->val > max ? head->val : max;
		return maxItemByValue(head->next, max);
	}
}
void printReverse(listptr head) {
	if (!head->next)
	{
		cout << head->val << " ";
	}
	else
	{
		printReverse(head->next);
		cout << head->val << " ";
	}
}
bool isEqual(listptr head1, listptr head2) {
	while (head1 && head2)
	{
		if (head1->val != head2->val)
		{
			return false;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	if (head1 || head2)
	{
		return false;
	}
	return true;
}