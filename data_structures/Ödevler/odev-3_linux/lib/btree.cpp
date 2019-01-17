#include <stdio.h> 
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include "random_data.hpp"

struct node
{ 
	int data; 
	node *left;
	node *right; 
	node *root;
};

class btree{
public:
	btree();
	~btree();

	node* add(node *tree,int x);
	int height(struct node* tree);
	int del_min(node *tree);
	int del_max(node *tree);
	void levelorder(struct node* tree);
	void travers(node *tree);
	void printGivenLevel(struct node* tree, int level) 
	node* MergeTrees(node *headA, node *headB);

};


btree::btree(){
	root = NULL;
}

btree::~btree(){
}

node* add (node *tree,int x)
{
	if(tree == NULL)
	{
		node *root = (node *)malloc(sizeof(node));
		root->left = NULL;
		root->right = NULL;
		root->data = x;
		return root;
	}
	if(tree->data < x) 
	{
		tree->right = add(tree->right,x);
		return tree;
	}
	tree->left = add(tree->left,x);
	return tree;
}

void btree::travers(node *tree)
{
	if(tree==NULL) return;
	travers(tree->left);
	std::cout<<tree->data<<" ";
	travers(tree->right);
}

int btree::height(struct node* tree) 
{ 
	if (tree==NULL) 
		return 0; 
	else
	{ 
		/* compute the height of each subtree */
		int lheight = height(tree->left); 
		int rheight = height(tree->right); 

		/* use the larger one */
		if (lheight > rheight) 
			return(lheight+1); 
		else return(rheight+1); 
	} 
} 

/* Print nodes at a given level */
void btree::printGivenLevel(struct node* tree, int level) 
{ 
	if (tree == NULL) 
		return; 
	if (level == 1) 
		printf("%d ", tree->data); 
	else if (level > 1) 
	{ 
		printGivenLevel(tree->left, level-1); 
		printGivenLevel(tree->right, level-1); 
	} 
} 

/* Function to print level order traversal a tree*/
void btree::levelorder(struct node* tree) 
{ 
	int h = height(tree); 
	int i; 
	for (i=1; i<=h; i++) 
		printGivenLevel(tree, i); 
} 

int btree::del_max(node *tree)
{
	int tmp = -1;
	while(tree->right!=NULL) { tree=tree->right; }	
	tree->data = tmp;
	return 0;
}

int btree::del_min(node *tree)
{
	int tmp = -1;
	while(tree->left!=NULL) { tree=tree->left; }
	tree->data = tmp;
	return 0;
}

/* Function to merge given two binary trees*/
node* MergeTrees(node *headA, node *headB) 
{ 
    if (!headA) 
        return headB; 
    if (!headB) 
        return headA; 
    headA->data += headB->data; 
    headA->left = MergeTrees(headA->left, headB->left); 
    headA->right = MergeTrees(headA->right, headB->right); 
    return headA; 
}

int main(int argc, char ** argv)
{	
	system("clear");

    std::string input_data;
    std::cout << "input_data: " ;
    std::cin >> input_data;

    size_t input_len = input_data.length();

    int *trees_elem_list = new int[input_len];

    for (size_t i = 0; i < input_len; ++i) {
        trees_elem_list[i] = input_data[i] - '0';
    }

    std::cout << std::endl << "Number of Trees: " << input_len << std::endl << std::endl;
    for (size_t i = 0; i < input_len; ++i) {
            std::cout << i + 1 << ". tree depth : " << trees_elem_list[i] << std::endl;
    }

    std::cout << std::endl << "### Initializing..." << std::endl << std::endl;


	for (size_t i = 0; i < input_len; ++i)
	{	
		if (root == NULL) 
		{ 
			btree *tree = new btree();
			for (int j=0; j < trees_elem_list[i]; ++j)
			{
				int data = randomGenerator(1,500);
				tree = add(tree, data);
				if( height(tree) == trees_elem_list[i] ) break;
			}
			headA = root;
		} else 
		{
			btree *tree = new btree();
			for (int j=0; j < trees_elem_list[i]; ++j)
			{
				int data = randomGenerator(1,500);
				tree = add(tree, data);
				if( height(tree) == trees_elem_list[i] ) break;
			}
			headB = root;
			MergeTrees(headA, headB);
			headA = NULL;
			headB = NULL;
			root = NULL;
		}
	}

	std::cout<<" travers:";
	travers(tree);
	std::cout<<"\n";

	std::cout<<" del_max:";
	del_max(tree);
	travers(tree);
	std::cout<<"\n";

	std::cout<<" del_min:";
	del_min(tree);
	travers(tree);
	std::cout<<"\n";

	levelorder(tree);

}


