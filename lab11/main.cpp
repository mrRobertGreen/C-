#include <iostream>
#include "header.h"

using namespace std;

int main() {
	Tree tree = Tree();
	Tree tree2 = Tree();
	tree.addNode(3);
	tree.addNode(5);
	tree.addNode(1);
	tree.addNode(2);
	tree.addNode(2);
	tree.addNode(4);
	tree.addNode(6);
	cout << tree << "\n";
	cout << "Nodes count: " << tree.nodesCount() <<"\n";
	cout << "Leaves count: " << tree.leavesCount() <<"\n";
	cout << "Depth: " << tree.rootDepth() <<"\n";
	cout << (tree2 = tree);
	cout << tree;



	return EXIT_SUCCESS;
}