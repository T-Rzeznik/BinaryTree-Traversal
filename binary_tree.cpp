#include "binary_tree.h"
#include <iostream>
using namespace std;
void binary_tree_node::set_data(const binary_tree_node::value_type& new_data)
{
	data_field = new_data;
}
void binary_tree_node::set_right(binary_tree_node* new_right)
{
	right_field = new_right;
}
void binary_tree_node::set_left(binary_tree_node* new_left)
{
	left_field = new_left;
}
binary_tree_node::value_type binary_tree_node::get_data() const
{
	return data_field;
}
binary_tree_node* binary_tree_node::get_right() const
{
	return right_field;
}
binary_tree_node* binary_tree_node::get_left() const
{
	return left_field;
}
bool binary_tree_node::is_leaf() const
{
	return ((right_field == nullptr) && (left_field == nullptr));
}
binary_tree_node::binary_tree_node(const value_type& init_data, binary_tree_node* init_right, binary_tree_node* init_left)
{
	data_field = init_data;
	right_field = init_right;
	left_field = init_left;
}
void inorder_print(binary_tree_node* node_ptr)
{
	if (node_ptr != nullptr)
	{
		inorder_print(node_ptr->get_left());
		cout << node_ptr->get_data() << endl;
		inorder_print(node_ptr->get_right());
	}
}
void preorder_print(binary_tree_node* node_ptr)
{
	if (node_ptr != nullptr)
	{
		cout << node_ptr->get_data() << endl;
		preorder_print(node_ptr->get_left());		
		preorder_print(node_ptr->get_right());
	}
}
void postorder_print(binary_tree_node* node_ptr)
{
	if (node_ptr != nullptr)
	{
		postorder_print(node_ptr->get_left());
		postorder_print(node_ptr->get_right());
		cout << node_ptr->get_data() << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
binary_tree_node* search_item(binary_tree_node* node_ptr, const binary_tree_node::value_type& item)
{
	if (node_ptr == nullptr || node_ptr->get_data() == item) //return the node if the tree is empty or the item is in the root/node(recurrsion)
	{
		return node_ptr;
	}

	binary_tree_node* left_search = search_item(node_ptr->get_left(), item);
	if (left_search != nullptr) //if the item is found in the left, return the new node
	{
		return left_search;
	}

	return search_item(node_ptr->get_right(), item); //search the right side
}

binary_tree_node* insert_item(binary_tree_node* node_ptr, const binary_tree_node::value_type& item)
{
	if (node_ptr == nullptr) //tree is empty
	{
		return new binary_tree_node(item, nullptr, nullptr);
	}

	if (item < node_ptr->get_data()) //item is < nodes data, meaning the new node belongs on the left side
	{
		node_ptr->set_left(insert_item(node_ptr->get_left(), item));
	}
	else if (item > node_ptr->get_data()) //item is > nodes data, meaning the new node belongs on the right side
	{
		node_ptr->set_right(insert_item(node_ptr->get_right(), item));
	}

	return node_ptr;
}

/// ////////////////////////////////////////////////////////////////////////////delete function

binary_tree_node* find_min_node(binary_tree_node* node_ptr)
{
	while (node_ptr->get_left() != nullptr)
	{
		node_ptr = node_ptr->get_left();
	}
	return node_ptr;
}

binary_tree_node* delete_item(binary_tree_node* node_ptr, const binary_tree_node::value_type& item)
{
	if (node_ptr == nullptr)     //Case 1: empty tree, base case
	{
		return node_ptr;
	}

	if (item < node_ptr->get_data())    //left treversal, when item is less than current nodes item
	{
		node_ptr->set_left(delete_item(node_ptr->get_left(), item));
	}
	else if (item > node_ptr->get_data()) //right treversal, when item is greater than current nodes item
	{
		node_ptr->set_right(delete_item(node_ptr->get_right(), item));
	}
	else // if the current node holds the item to be deleted
	{
		if (node_ptr->get_left() == nullptr) // Case 1: current node has no left child
		{
			binary_tree_node* temp = node_ptr->get_right();
			delete node_ptr;
			return temp;
		}
		else if (node_ptr->get_right() == nullptr) //Case 2: current node has no right child
		{
			binary_tree_node* temp = node_ptr->get_left();
			delete node_ptr;
			return temp;
		}
		else // Case 3: has right and left child
		{
			binary_tree_node* temp = find_min_node(node_ptr->get_right());
			node_ptr->set_data(temp->get_data());
			node_ptr->set_right(delete_item(node_ptr->get_right(), temp->get_data()));
		}
	}
	return node_ptr;
}

//----------------------------------------------------------------------------------------------------------------------------------
int tree_height(binary_tree_node* node_ptr)
{
	if (node_ptr == nullptr)  //returns -1 if tree is empty
	{
		return -1;
	}

	int left_height = tree_height(node_ptr->get_left()); //size of left
	int right_height = tree_height(node_ptr->get_right()); //size of right

	return 1 + std::max(left_height, right_height); // returning the comparison of the sides + 1 (for current node), (total size of the tree)
}

int count_nodes(binary_tree_node* node_ptr)
{
	if (node_ptr == nullptr) //empty tree
	{
		return 0;
	}

	return 1 + count_nodes(node_ptr->get_left()) + count_nodes(node_ptr->get_right()); //left nodes + right nodes + 1 (current node)
}

int count_leaves(binary_tree_node* node_ptr)
{
	if (node_ptr == nullptr) //tree is empty
	{
		return 0;
	}

	if (node_ptr->is_leaf()) //+1 leaf
	{
		return 1;
	}

	return count_leaves(node_ptr->get_left()) + count_leaves(node_ptr->get_right()); 
}

binary_tree_node* copy_tree(const binary_tree_node* node_ptr)
{
	if (node_ptr == nullptr)
	{
		return nullptr;
	}

	return new binary_tree_node(node_ptr->get_data(), copy_tree(node_ptr->get_right()), copy_tree(node_ptr->get_left()));
}
