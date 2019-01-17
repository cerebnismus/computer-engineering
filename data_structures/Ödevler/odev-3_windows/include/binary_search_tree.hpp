/* @file BinarySearchTree.hpp
* @description BST Functions
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 20.12.2018
* @author Özge Öztataroglu ozge.oztataroglu@ogr.sakarya.edu.tr
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP


#include <iostream>

struct Node {

    Node(const int data) : m_data(data), m_left(nullptr), m_right(nullptr) {}

    Node *left() const {
        return m_left;
    }

    Node *right() const {
        return m_right;
    }

    void set_right(Node *value) {
        m_right = value;
    }

    void set_left(Node *value) {
        m_left = value;
    }

    int data() {
        return m_data;
    }

private:
    int m_data;
    Node *m_left;
    Node *m_right;
};




class BinarySearchTree {

public:
    BinarySearchTree() : m_root(nullptr), min_val(0), max_val(0) {}
    ~BinarySearchTree() {
        destroy_tree();
    }

    void insert(int key);

    int min();
    int max();
    int depth();
    void inorder_print();
    void postorder_print();
    void preorder_print();
    void destroy_tree();
    void printGivenLevel();
    void levelorder_print();

    void set_root(Node *root){
        m_root = root;
        min_val = max_val = root->data();
    }

    Node *last_elem() const;

private:
    void insert(int key, Node *leaf);
    int depth(Node* leaf);
    void inorder_print(Node *leaf);
    void postorder_print(Node *leaf);
    void preorder_print(Node *leaf);
    void levelorder_print(Node *leaf);
    void printGivenLevel(Node *leaf, int level);
    void destroy_tree(Node *leaf);

private:
    Node *m_root;
    Node *m_last_elem;

    int min_val;
    int max_val;
};

/*
 *
 */

void BinarySearchTree::insert(int key)
{
    if(m_root == nullptr){
        m_root = new Node(key);
        min_val = max_val = key;
    }else{
        insert(key, m_root);
    }
}


void BinarySearchTree::insert(int key, Node *leaf)
{
    if ( min_val > key ) {
        min_val = key;
    } else if( max_val < key ) {
        max_val = key;
    }

    if(key < leaf->data()) {

        if(leaf->left() == nullptr){
            leaf->set_left(new Node(key));
            m_last_elem = leaf->left();
        } else {
            insert(key, leaf->left());
        }


    } else if(key > leaf->data()) {

        if(leaf->right() == nullptr){
            leaf->set_right(new Node(key));
            m_last_elem = leaf->right();
        } else {
            insert(key, leaf->right());
        }


    } else {
        return;
    }
}

void BinarySearchTree::printGivenLevel(Node *leaf, int level) 
{ 
	if (leaf == NULL) 
		return; 
	if (level == 1) 
        std::cout <<"["<< leaf->data() << "] ";
	else if (level > 1) 
	{ 
		printGivenLevel(leaf->left(), level-1); 
		printGivenLevel(leaf->right(), level-1); 
	} 
} 

void BinarySearchTree::levelorder_print(){ levelorder_print(m_root); }

void BinarySearchTree::levelorder_print(Node *leaf) 
{ 
	int h = depth(leaf); 
	int i; 
	for (i=1; i<=h; i++) 
		printGivenLevel(leaf, i); 
} 
/*
 *
 */


int BinarySearchTree::min()
{

    return min_val; 
}

int BinarySearchTree::max()
{
    return max_val; 
}

int BinarySearchTree::depth()
{
    return depth(m_root);
}


int BinarySearchTree::depth(Node* leaf)
{
    if (leaf == nullptr) {
        return 0;
    } else {
        int left_depth = depth(leaf->left());
        int right_depth = depth(leaf->right());

        if (left_depth > right_depth) {
            return(left_depth + 1);
        } else {
            return(right_depth + 1);
        }
    }
}

/*
 *
 */

void BinarySearchTree::inorder_print()
{
    inorder_print(m_root);
}

void BinarySearchTree::inorder_print(Node *leaf)
{
    if(leaf != nullptr){
        inorder_print(leaf->left());
        std::cout << leaf->data() << ",";
        inorder_print(leaf->right());
    }
}


/*
 *
 */

void BinarySearchTree::postorder_print()
{
    postorder_print(m_root);
}

void BinarySearchTree::postorder_print(Node *leaf)
{
    if(leaf != nullptr){
		postorder_print(leaf->left());
		postorder_print(leaf->right());
        std::cout << leaf->data() << ",";
    }
}



/*
 *
 */

void BinarySearchTree::preorder_print()
{
    preorder_print(m_root);
}

void BinarySearchTree::preorder_print(Node *leaf)
{
    if(leaf != nullptr) {
        std::cout << leaf->data() << ",";
		preorder_print(leaf->left());
		preorder_print(leaf->right());
    }
}

/*
 *
 */

void BinarySearchTree::destroy_tree()
{
    //std::cout << "destroy_tree" << std::endl;
    destroy_tree(m_root);
}

void BinarySearchTree::destroy_tree(Node *leaf)
{
    if(leaf != nullptr){
        destroy_tree(leaf->left());
        destroy_tree(leaf->right());
        delete leaf;
    }
}

Node *BinarySearchTree::last_elem() const
{
    return m_last_elem;
}

#endif // BINARY_SEARCH_TREE_HPP


