#include "binary_tree_node.hpp"

template <class Item>
void tree_clear(binary_tree_node<Item>*& root_ptr)
{
	binary_tree_node<Item>* child;
	if(root_ptr != NULL)
	{
		child = root_ptr->left();
		tree_clear(child);
		child = root_ptr->right();
		tree_clear(child);
		delete root_ptr;
		root_ptr = NULL;
	}
}

template <class Item>
binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr)
{
    binary_tree_node<Item> *l_ptr;
    binary_tree_node<Item> *r_ptr;
    if(root_ptr == NULL) return NULL;
    else
    {
        l_ptr = tree_copy(root_ptr->left());
        r_ptr = tree_copy(root_ptr->right());
        return new binary_tree_node<Item>(root_ptr->data(), l_ptr, r_ptr);
    }
}

