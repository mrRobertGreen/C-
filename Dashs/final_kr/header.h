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
	void add_right_in_every_leave(node_ptr& t, int a);
	void print(node_ptr t, ostream& os, int n = 0) const;
	void copy(node_ptr source, node_ptr& destination)  const;
	int nodes_count(node_ptr t)  const;
	int leaves_count(node_ptr t)  const;
	int depth(node_ptr t)  const;
	bool is_leave(node_ptr t) const;
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
	void addRightInEveryLeave(int a) { // вставка узла с заданным значением справа от каждого левого листа
		add_right_in_every_leave(root, a);
	}
	friend ostream& operator<<(ostream& os, const Tree& t) { t.print(t.root, os);  return os; }
};
