/* @file binary_tree_node.hpp
* @description binary_tree_node Functions
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 20.12.2018
* @author Özge Öztataroglu ozge.oztataroglu@ogr.sakarya.edu.tr
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/

#ifndef BINARY_TREE_NODE_HPP
#define BINARY_TREE_NODE_HPP

#include <string>
#include <cstring>
#include <string.h>
#include <iostream>

template <class Item>
class binary_tree_node{
	private:
		Item data_field;
		binary_tree_node *left_field;
		binary_tree_node *right_field;
	public:
		// TYPEDEF
		typedef Item value_type;
		// CONSTRUCTOR
		binary_tree_node(
			const Item& init_data = Item(),
			binary_tree_node* init_left = NULL,
			binary_tree_node* init_right = NULL
		)
		{
			data_field = init_data;
			left_field = init_left;
			right_field = init_right;
		}
		//MODIFICATION MEMBER FUNCTIONS
		Item& data() { return data_field; }
		binary_tree_node*& left() { return left_field; }
		binary_tree_node*& right() { return right_field; }
		void set_data(const Item& new_data) { data_field = new_data; }
		void set_left(binary_tree_node* new_left) { left_field = new_left; }
		void set_right(binary_tree_node* new_right) { right_field = new_right; }
		
		// CONSTANT MEMBER FUNCTIONS
		const Item& data() const { return data_field; }
		const binary_tree_node* left() const { return left_field; }
		const binary_tree_node* right() const { return right_field; }
		bool is_leaf() const { return (left_field == NULL) && (right_field == NULL); }

		// CLEAR LEFT & RIGHT SUBTREE AND SET ROOT POINTER TO NULL
		void tree_clear(binary_tree_node<Item>*& root_ptr);
		// Precondition: root_ptr is the root pointer of a binary tree (which may be NULL for the empty tree).
		// Postcondition: All nodes at the root or below have been returned to the heap,
		// and root_ptr has been set to NULL.

		// COPYING A TREE
		binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr);
		// Precondition: root_ptr is the root pointer of a binary tree (which may be NULL for the empty tree).
		// Postcondition: A copy of the binary tree has been made,
		// and the return value is a pointer to the root of this copy.
		

};

#endif // binary_tree_node_HPP