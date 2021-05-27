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
	void del_tree(node_ptr t);
	void add(node_ptr& t, int a);
	void fill_in_width(node_ptr& t, int* arr, int len);
	void fill_with_balance(node_ptr& t, int* arr, int len);
	void add_in_width(node_ptr& t, int a, int i);
	void add_with_balance(node_ptr& t, int a);
	void printLKR(node_ptr t, ostream& os) const;
	void print(node_ptr t, ostream& os, int n = 0) const;
	void copy(node_ptr source, node_ptr& destination)  const;
	int nodes_count(node_ptr t)  const;
	int leaves_count(node_ptr t)  const;
	int depth(node_ptr t)  const;
	bool is_equal(node_ptr t1, node_ptr t2) const;
public:
	Tree() : root(nullptr) {}
	Tree(const Tree& other) {
		copy(other.root, root);
	}
	~Tree() {
		del_tree(root);
	}
	void addNode(int a) {
		add(root, a);	
	}
	int nodesCount() {
		return nodes_count(root);
	}
	int leavesCount() {
		return leaves_count(root);
	}
	int rootDepth() {
		return depth(root);
	}
	void fillInWidth(int* arr, int len) {
		return fill_in_width(root, arr, len);
	}
	void fillWithBalance(int* arr, int len) {
		return fill_with_balance(root, arr, len);
	}
	Tree operator=(const Tree& other) {
		copy(other.root, root);
		return *this;
	}
	bool operator==(const Tree& other) {
		return is_equal(root, other.root);
	}
	friend ostream& operator<<(ostream& os, const Tree& t) { t.print(t.root, os);  return os; }
};
