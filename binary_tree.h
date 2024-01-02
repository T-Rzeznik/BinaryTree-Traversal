#pragma once
class binary_tree_node
{
public:
	typedef char value_type;
	void set_data(const value_type& new_data);
	void set_right(binary_tree_node* new_right);
	void set_left(binary_tree_node* new_left);
	value_type get_data() const;
	binary_tree_node* get_right() const;
	binary_tree_node* get_left() const;
	bool is_leaf() const;
	binary_tree_node(const value_type& init_data, binary_tree_node* init_right, binary_tree_node* init_left);

	
private:
	value_type data_field;
	binary_tree_node* right_field;
	binary_tree_node* left_field;
};
void inorder_print(binary_tree_node* node_ptr);
void preorder_print(binary_tree_node* node_ptr);
void postorder_print(binary_tree_node* node_ptr);

