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

class ListIterator;

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
	void delFirst() {
		if (first)
		{
			Node* newFirst = new Node(first->next->data, first->next->next);
			delete first;
			first = newFirst;
		}
		else throw exception("list is empty");
	};
	void delLast() {
		if (last)
		{
			Node* newLast = new Node(first->data, first->next);
			while (newLast->next != last)
				newLast = newLast->next;
			delete last;
			newLast->next = nullptr;
			last = newLast;
		}
		else throw exception("list is empty");
	};

	//обработка с предикатом
	int count(bool(*f) (int)) {
		Node* cur = first;
		int res = 0;
		while (cur) {
			if (f(cur->data))
				++res;
			cur = cur->next;
		}
		return res;
	};
	void for_each(void(*action)(int&)) {
		Node* cur = first;
		while (cur) {
			action(cur->data);
			cur = cur->next;
		}
	};

	ListIterator begin() const;
	ListIterator end() const;

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


// пример функций для проверки метода 
//	int count(bool(*f) (int));
bool odd(int x) {
	return x % 2 != 0;
}

// пример функций для проверки метода 
//	void for_each(void(*action)(int &));
void mult2(int& x) {
	x *= 2;
}

class ListIterator {
private:
	const List* collection;
	Node* cur;
public:
	ListIterator(const List* s, Node* e) : collection(s), cur(e) {}
	int& operator *() {
		if (cur) return cur->data;
		else throw exception("elem is undefined");
	}
	ListIterator operator++() { // префиксный ++
		if (cur) {
			cur = cur->next;
			return *this;
		}
		else throw exception("elem is undefined");
	}
	bool operator == (const ListIterator& iter) const {
		return ((collection == iter.collection) && (cur == iter.cur));
	}
	bool operator != (const ListIterator& iter) const {
		return !(*this == iter);
	}
};

ListIterator List::begin() const {
	return ListIterator(this, first);
};
ListIterator List::end() const {
	return ListIterator(this, nullptr);
};
