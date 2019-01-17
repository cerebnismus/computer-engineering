#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node 
{ 
	int data; 
	struct node* left, *right; 
}; 

/* Function protoypes */
void printGivenLevel(struct node* root, int level); 
int height(struct node* node); 
struct node* newNode(int data); 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*) 
						malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return(node); 
} 

/* Given a non-empty binary search tree, 
return the minimum data value found in that 
tree. Note that the entire tree does not need 
to be searched. */
int minValue(struct node* node) { 
struct node* current = node; 

/* loop down to find the leftmost leaf */
while (current->left != NULL) { 
	current = current->left; 
} 
return(current->data); 
} 

/* Give a binary search tree and a number, 
inserts a new node with the given number in 
the correct place in the tree. Returns the new 
root pointer which the caller should then use 
(the standard trick to avoid using reference 
parameters). */
struct node* insert(struct node* node, int data) 
{ 
/* 1. If the tree is empty, return a new,	 
	single node */
if (node == NULL) 
	return(newNode(data)); 
else
{ 
	/* 2. Otherwise, recur down the tree */
	if (data <= node->data) 
		node->left = insert(node->left, data); 
	else
		node->right = insert(node->right, data); 
	
	/* return the (unchanged) node pointer */
	return node; 
} 
} 

/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root) 
{ 
	int h = height(root); 
	int i; 
	for (i=1; i<=h; i++) 
		printGivenLevel(root, i); 
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

/* Driver program to test sameTree function*/	
/* Driver program to test above functions*/
int main() 
{ 
std::cout<<"\n Test_0"<<std::endl; 

struct node *root = NULL; 
root = insert(root, 4); 
insert(root, 2); 
insert(root, 1); 
insert(root, 3); 
insert(root, 6); 
insert(root, 5); 

std::cout<<"\n Test_1"<<std::endl; 

std::cout << "\n Minimum value in BST is: " << minValue(root) << std::endl;
getchar(); 

std::cout << "Level Order traversal of binary tree is \n" << std::endl; 
printLevelOrder(root); 

return 0; 
} 