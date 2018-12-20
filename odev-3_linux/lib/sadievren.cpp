#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node
{ 
	int data; 
	node * left;
	node * right; 
}; 

node * add (node *tree,int x)
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

void travers(node *tree)
{
	if(tree==NULL) return;
	travers(tree->left);
	std::cout<<tree->data<<" ";
	travers(tree->right);
}

/* Compute the "height" of a tree -- the number of 
	nodes along the longest path from the root node 
	down to the farthest leaf node.*/
int height(struct node* node) 
{ 
	if (node==NULL) 
		return 0; 
	else
	{ 
		/* compute the height of each subtree */
		int lheight = height(node->left); 
		int rheight = height(node->right); 

		/* use the larger one */
		if (lheight > rheight) 
			return(lheight+1); 
		else return(rheight+1); 
	} 
} 

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level) 
{ 
	if (root == NULL) 
		return; 
	if (level == 1) 
		printf("%d ", root->data); 
	else if (level > 1) 
	{ 
		printGivenLevel(root->left, level-1); 
		printGivenLevel(root->right, level-1); 
	} 
} 

/* Function to print level order traversal a tree*/
void Levelorder(struct node* root) 
{ 
	int h = height(root); 
	int i; 
	for (i=1; i<=h; i++) 
		printGivenLevel(root, i); 
} 

int del_max(node *tree)
{
	int tmp = -1;
	while(tree->right!=NULL) { tree=tree->right; }	
	tree->data = tmp;
	return 0;
}

int del_min(node *tree)
{
	int tmp = -1;
	while(tree->left!=NULL) { tree=tree->left; }
	tree->data = tmp;
	return 0;
}

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,1000);
int dice_roll = distribution(generator);

int main() 
{	
	system("clear"); // Terminal ekranini temizle.

	std::string user_input;
	std::cout << "Yukseklik: ";
	std::cin >> user_input;

	for (int i=0; i<user_input.size(); i++) 
		node * tree = NULL;
		for (int j=0; j<user_input.size(); j++)
			// node * add (node *tree,int dice_roll)
			tree=add(tree,dice_roll);
/*
	tree=add(tree,12);
	tree=add(tree,200);
	tree=add(tree,190);
	tree=add(tree,213);
	tree=add(tree,56);
	tree=add(tree,24);
*/
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
}
