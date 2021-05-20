#pragma once
#include <iostream>
using namespace std;


class Tree {
private:
	struct TNode;
	typedef TNode* node_ptr;
	struct TNode {
		int data;
		node_ptr lt, rt;
		TNode(int val, node_ptr l = nullptr, node_ptr r = nullptr) : data(val), lt(l), rt(r) {}
	};

	node_ptr root;
	void delTree(node_ptr t); 
	void add(node_ptr& t, int a); 
	void printLKR(node_ptr t, ostream& os) const; 
	void copy(node_ptr t, node_ptr &newT)  const;
public:
	Tree() : root(nullptr) {}
	Tree(const Tree& t) {
		copy( t.root, root);
	}
	~Tree() {
		delTree (root);
	}
	void addNode(int a) {
		add(root, a);
	}
	friend ostream& operator<<(ostream& os, const Tree &t) { t.printLKR(t.root,os);  return os; }
};