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
	tree.addNode(6);
	tree.addNode(0);
	tree.addNode(1);
	cout << "BEFORE INSERTING: \n";
	cout << tree;
	cout << "Nodes count: " << tree.nodesCount() << "\n";
	cout << "Leaves count: " << tree.leavesCount() << "\n";
	cout << "Depth: " << tree.rootDepth() << "\n";

	tree.addRightInEveryLeave(7);

	cout << "\nAFTER INSERTING:\n";
	cout << tree;
	cout << "Nodes count: " << tree.nodesCount() << "\n";
	cout << "Leaves count: " << tree.leavesCount() << "\n";
	cout << "Depth: " << tree.rootDepth() << "\n";

	return EXIT_SUCCESS;
}