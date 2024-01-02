#include "binary_tree.h"
#include <iostream>
using namespace std;
int main()
{
	binary_tree_node* tree1 = new binary_tree_node('A', nullptr, nullptr);
	tree1->set_left(new binary_tree_node('B', nullptr, nullptr));
	tree1->set_right(new binary_tree_node('C', nullptr, nullptr));
	cout << "Inorder:" << endl;
	inorder_print(tree1);
	cout << "Preorder:" << endl;
	preorder_print(tree1);
	cout << "Postorder:" << endl;
	postorder_print(tree1);
	return 0;
}