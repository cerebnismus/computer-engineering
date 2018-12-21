#include <stdio.h> 
#include <stdlib.h>
#include <iomanip>
#include <iostream>

struct node
{ 
	int data; 
	node *left;
	node *right; 
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
	void travers(node *tree)
	node* MergeLists(node *headA, node *headB)

	node *root;
};


btree::btree(){
	root = NULL;
}

btree::~btree(){
	destroy_tree();
}

node* btree::add (node *tree,int x)
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

node* btree::MergeLists(node *headA, node* headB)
{
    if (headA == NULL) {
        return headB;
    } else if (headB == NULL) {
        return headA;
    } else if (headA->data <= headB->data) {
        headA->next = MergeLists(headA->next, headB);
        return headA;
    } else {
        headB->next = MergeLists(headA, headB->next);
        return headB;
    }
}

/*
 * 	You should strongly prefer this to strlen(str.c_str()) 
 * 	for the following reasons:
 *	Clarity: The length() (or size() ) member functions
 *	unambiguously give back the length of the string.
 *	Efficiency: length() and size() run in time O(1), 
 *	while strlen(str.c_str()) will take Θ(n) time 
 *	to find the end of the string.
 */

int main() 
{	
	system("clear");

	int user_input;
	std::cout << "Height: ";
	std::cin >> user_input;

	for (int i=0; i<strlen(str.c_str(user_input)); i++)
	{	
		if (root == NULL) 
		{ 
			btree *tree = new btree();
			for (int j=0; j<atoi(user_input); j++)
			{
				int x = (rand() % 100) + 1;
				tree = add(tree,x);
				if( height(tree) == atoi(user_input) ) break;
			}
			headA = root;
		} else 
		{
			btree *tree = new btree();
			for (int j=0; j<atoi(user_input); j++)
			{
				int x = (rand() % 100) + 1;
				tree = add(tree,x);
				if( height(tree) == atoi(user_input) ) break;
			}
			headB = root;
			MergeLists(headA, headB);
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


