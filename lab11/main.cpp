#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "header.h"

using namespace std;

int main() {
	/*Tree tree = Tree();
	Tree tree2 = Tree();
	tree.addNode(3);
	tree.addNode(5);
	tree.addNode(1);
	tree.addNode(2);
	tree.addNode(2);
	tree.addNode(4);
	tree.addNode(6);
	cout << tree << "\n";
	cout << "Nodes count: " << tree.nodesCount() << "\n";
	cout << "Leaves count: " << tree.leavesCount() << "\n";
	cout << "Depth: " << tree.rootDepth() << "\n";
	cout << (tree2 = tree);
	cout << "--------------\n";
	tree.addNode(3);
	cout << tree;
	cout << (tree == tree2);
	cout << "--------------\n";*/

	int length = 10;
	int* arr = new int[length];
	for (int i = 0; i < length; i++)
		arr[i] = i;
	
	Tree tree3 = Tree();
	tree3.fillInWidth(arr, length);
	cout << tree3;



	return EXIT_SUCCESS;
}