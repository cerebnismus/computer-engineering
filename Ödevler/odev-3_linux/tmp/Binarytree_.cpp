#pragma once
#include <vector>
#include "node.h"

class Binarytree
{
	public:
	Binarytree();
	~Binarytree();

	void insert_node(int key) { insert_node_pr(key, root); }
	void delete_node(int key) { delete_node_pr(key, root); }
	Node* search_node(int key) { return search_node_pr(key, root); }
	
	int find_min() { find_min_pr(root->left); }
	int find_max() { find_max_pr(root->right); }

	int find_height(const Node* const node);
	int find_depth(const Node* const node);

	private:
	Node* create_node(int key);
	void insert_node_pr(int, Node*& node);
	void delete_node_pr(int, Node* node);
	Node* search_node_pr(int, Node* const node);
	int find_max_pr(const Node* const node);
	int find_min_pr(const Node* const node);


	Node* root { nullptr };
	std::vector<int> internalTab;
};