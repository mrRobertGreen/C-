#pragma once
#include <iostream>
#include <exception>

using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}

	friend 	ostream& operator<< (ostream& out, const Node& x) {
		out << x.data;
		return out;
	};
};

class List {
private:
	Node* first;
	Node* last;
public:
	List() : first(nullptr), last(nullptr) {}
	~List() {
		while (first)
		{
			Node* cur = first;
			first = first->next;
			delete cur;
		}
		first = last = nullptr;
	};
	bool isEmpty() const {
		return first == nullptr && last == nullptr;
	};
	void addFirst(int x) {
		Node* elem = new Node(x, first);
		if (!first)
			last = elem;
		first = elem;
	};
	void addLast(int val) {
		Node* elem = new Node(val, nullptr);
		if (!first)
			first = last = elem;
		else {
			last->next = elem;
			last = elem;
		}
	};
	int getFirst() const {
		return first->data;
	};
	int getLast() const {
		return last->data;
	};
	void insertSumBetween() {
		Node* cur = first;
		while (cur->next) {
			int sum = cur->data + cur->next->data;
			Node* item = new Node(sum, cur->next);
			cur->next = item;
			cur = item->next;
		}
	};

	friend ostream& operator << (ostream& out, const List& list) {
		Node* cur = list.first;
		while (cur) {
			out << cur->data << " ";
			cur = cur->next;
		}
		out << "\n";
		return out;
	};
};