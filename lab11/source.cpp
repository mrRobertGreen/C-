#include "header.h"

using namespace std;

void Tree::del_tree(node_ptr t) {
	int c;
	if (t != nullptr) {
		del_tree(t->lt);
		del_tree(t->rt);
		delete t;
		t = nullptr;
	}
}
void Tree::add(node_ptr& t, int a) {
	if (t == nullptr) t = new TNode(a);
	else if (t->data > a) add(t->lt, a);
	else add(t->rt, a);
}
void Tree::printLKR(node_ptr t, ostream& os) const {
	if (t) {
		printLKR(t->lt, os);
		os << t->data << " ";
		printLKR(t->rt, os);
	}
}
void Tree::print(node_ptr t, ostream& os, int n) const {
	if (t) {
		print(t->lt, os, n + 1);
		for (int i = 0; i < n; ++i)
			cout << " ";
		cout << t->data << "\n";
		print(t->rt, os, n + 1);
	}
}
int Tree::nodes_count(node_ptr t)  const {
	if (t)
	{
		return 1 + nodes_count(t->lt) + nodes_count(t->rt);
	}
	else {
		return 0;
	}
}
int Tree::leaves_count(node_ptr t)  const {
	if (t)
	{
		if (t->rt || t->lt)
		{
			return leaves_count(t->lt) + leaves_count(t->rt);
		}
		else return 1;
	}
	else {
		return 0;
	}
}
int Tree::depth(node_ptr t)  const {
	if (t)
	{
		return max(1 + depth(t->lt), 1 + depth(t->rt));
	}
	else {
		return 0;
	}
}
void Tree::copy(node_ptr source, node_ptr& destination)  const //KLR
{
	if (source != nullptr)
	{
		destination = new TNode(source->data, nullptr, nullptr);
		copy(source->lt, destination->lt);
		copy(source->rt, destination->rt);
	}
	else destination = nullptr;
}
