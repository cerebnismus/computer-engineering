#pragma once
#include <iostream>

using namespace std;

struct node
{
	int key;
	node *parent;
	char color;
	node *left;
	node *right;
};
class RBtree
{
	node *root;
	node *q;
	int size_;

public:
	RBtree()
	{
		q = NULL;
		root = NULL;
		size_ = 0;
	}
	bool insert(int z);
	void insertfix(node *);
	void leftrotate(node *);
	void rightrotate(node *);
	bool del(int x);
	node* successor(node *);
	void delfix(node *);
	void disp();
	int size();
	void display(node *);
	bool search(int x);
};
bool RBtree::insert(int z)
{
	int i = 0;
	node *p, *q;
	node *t = new node;
	t->key = z;
	t->left = NULL;
	t->right = NULL;
	t->color = 'k';
	p = root;
	q = NULL;
	if (root == NULL)
	{
		root = t;
		t->parent = NULL;
	}
	else
	{
		while (p != NULL)
		{
			q = p;
			if (p->key<t->key)
				p = p->right;
			else
				p = p->left;
		}
		t->parent = q;
		if (q->key<t->key)
			q->right = t;
		else
			q->left = t;
	}
	size_++;
	insertfix(t);
	return true;
}
void RBtree::insertfix(node *t)
{
	node *u;
	if (root == t)
	{
		t->color = 's';
		return;
	}
	while (t->parent != NULL&&t->parent->color == 'k')
	{
		node *g = t->parent->parent;
		if (g->left == t->parent)
		{
			if (g->right != NULL)
			{
				u = g->right;
				if (u->color == 'k')
				{
					t->parent->color = 's';
					u->color = 's';
					g->color = 'k';
					t = g;
				}
			}
			else
			{
				if (t->parent->right == t)
				{
					t = t->parent;
					leftrotate(t);
				}
				t->parent->color = 's';
				g->color = 'k';
				rightrotate(g);
			}
		}
		else
		{
			if (g->left != NULL)
			{
				u = g->left;
				if (u->color == 'k')
				{
					t->parent->color = 's';
					u->color = 's';
					g->color = 'k';
					t = g;
				}
			}
			else
			{
				if (t->parent->left == t)
				{
					t = t->parent;
					rightrotate(t);
				}
				t->parent->color = 's';
				g->color = 'k';
				leftrotate(g);
			}
		}
		root->color = 's';
	}
}

bool RBtree::del(int x)
{
	if (root == NULL)
	{
	//	cout << "\nBos Agac.";
		return false;
	}

	node *p;
	p = root;
	node *y = NULL;
	node *q = NULL;
	int found = 0;
	while (p != NULL&&found == 0)
	{
		if (p->key == x)
			found = 1;
		if (found == 0)
		{
			if (p->key<x)
				p = p->right;
			else
				p = p->left;
		}
	}
	if (found == 0)
	{
	//	cout << "\nOge Bulunamadi.";
		return false;
	}
	else
	{
		size_--;
	/*	cout << "\nSilinen oge: " << p->key;
		cout << "\nRenk: ";
		if (p->color == 's')
			cout << "Siyah\n";
		else
			cout << "Kýrmýzý\n";

		if (p->parent != NULL)
			cout << "\nEbeveyn: " << p->parent->key;
		else
			cout << "\nDugumun ebeveyni yok.  ";
		if (p->right != NULL)
			cout << "\nSag Cocuk: " << p->right->key;
		else
			cout << "\nDugumun sag cocugu yok.  ";
		if (p->left != NULL)
			cout << "\nSol Cocuk: " << p->left->key;
		else
			cout << "\nDugumun sol cocugu yok.  ";
		cout << "\n Dugum Silindi."; */
		if (p->left == NULL || p->right == NULL)
			y = p;
		else
			y = successor(p);
		if (y->left != NULL)
			q = y->left;
		else
		{
			if (y->right != NULL)
				q = y->right;
			else
				q = NULL;
		}
		if (q != NULL)
			q->parent = y->parent;
		if (y->parent == NULL)
			root = q;
		else
		{
			if (y == y->parent->left)
				y->parent->left = q;
			else
				y->parent->right = q;
		}
		if (y != p)
		{
			p->color = y->color;
			p->key = y->key;
		}
		if (y->color == 's')
			delfix(q);
	}
	return true;
}

void RBtree::delfix(node *p)
{
	node *s;
	while (p != root&&p->color == 's')
	{
		if (p->parent->left == p)
		{
			s = p->parent->right;
			if (s->color == 'k')
			{
				s->color = 's';
				p->parent->color = 'k';
				leftrotate(p->parent);
				s = p->parent->right;
			}
			if (s->right->color == 's'&&s->left->color == 's')
			{
				s->color = 'k';
				p = p->parent;
			}
			else
			{
				if (s->right->color == 's')
				{
					s->left->color = 's';
					s->color = 'k';
					rightrotate(s);
					s = p->parent->right;
				}
				s->color = p->parent->color;
				p->parent->color = 's';
				s->right->color = 's';
				leftrotate(p->parent);
				p = root;
			}
		}
		else
		{
			s = p->parent->left;
			if (s->color == 'k')
			{
				s->color = 's';
				p->parent->color = 'k';
				rightrotate(p->parent);
				s = p->parent->left;
			}
			if (s->left->color == 's'&&s->right->color == 's')
			{
				s->color = 'k';
				p = p->parent;
			}
			else
			{
				if (s->left->color == 's')
				{
					s->right->color = 's';
					s->color = 'k';
					leftrotate(s);
					s = p->parent->left;
				}
				s->color = p->parent->color;
				p->parent->color = 's';
				s->left->color = 's';
				rightrotate(p->parent);
				p = root;
			}
		}
		p->color = 's';
		root->color = 's';
	}
}

void RBtree::leftrotate(node *p)
{
	if (p->right == NULL)
		return;
	else
	{
		node *y = p->right;
		if (y->left != NULL)
		{
			p->right = y->left;
			y->left->parent = p;
		}
		else
			p->right = NULL;
		if (p->parent != NULL)
			y->parent = p->parent;
		if (p->parent == NULL)
			root = y;
		else
		{
			if (p == p->parent->left)
				p->parent->left = y;
			else
				p->parent->right = y;
		}
		y->left = p;
		p->parent = y;
	}
}
void RBtree::rightrotate(node *p)
{
	if (p->left == NULL)
		return;
	else
	{
		node *y = p->left;
		if (y->right != NULL)
		{
			p->left = y->right;
			y->right->parent = p;
		}
		else
			p->left = NULL;
		if (p->parent != NULL)
			y->parent = p->parent;
		if (p->parent == NULL)
			root = y;
		else
		{
			if (p == p->parent->left)
				p->parent->left = y;
			else
				p->parent->right = y;
		}
		y->right = p;
		p->parent = y;
	}
}

node* RBtree::successor(node *p)
{
	node *y = NULL;
	if (p->left != NULL)
	{
		y = p->left;
		while (y->right != NULL)
			y = y->right;
	}
	else
	{
		y = p->right;
		while (y->left != NULL)
			y = y->left;
	}
	return y;
}

void RBtree::disp()
{
	display(root);
}
inline int RBtree::size()
{
	
	return size_;
}
void RBtree::display(node *p)
{
	if (root == NULL)
	{
		cout << "\nBos Agac.";
		return;
	}
	if (p != NULL)
	{
		cout << "\n\t DUGUM: ";
		cout << "\n Anahtar: " << p->key;
		cout << "\n Renk: ";
		if (p->color == 's')
			cout << "Siyah";
		else
			cout << "Kýrmýzý";
		if (p->parent != NULL)
			cout << "\n Ebeveyn: " << p->parent->key;
		else
			cout << "\n Dugumun ebevyni yok.  ";
		if (p->right != NULL)
			cout << "\n Sag Cocuk: " << p->right->key;
		else
			cout << "\n Dugumun sag cocugu yok.  ";
		if (p->left != NULL)
			cout << "\n Sol Cocuk: " << p->left->key;
		else
			cout << "\n Dugumun sol cocugu yok.  ";
		cout << endl;
		if (p->left)
		{
			cout << "\n\nSol:\n";
			display(p->left);
		}
		if (p->right)
		{
			cout << "\n\nSag:\n";
			display(p->right);
		}
	}
}
bool RBtree::search(int x)
{
	if (root == NULL)
	{
		return false;
	}

	node *p = root;
	int found = 0;
	while (p != NULL&& found == 0)
	{
		if (p->key == x)
			found = 1;
		if (found == 0)
		{
			if (p->key<x)
				p = p->right;
			else
				p = p->left;
		}
	}
	if (found == 0)
		return false;
	else
	{
	/*	cout << "\n\t BULUNAN DUGUM: ";
		cout << "\n Anahtar: " << p->key;
		cout << "\n Renk: ";
		if (p->color == 's')
		//	cout << "Siyah";
		else
		//	cout << "Kýrmýzý";
		if (p->parent != NULL)
		//	cout << "\n Ebeveyn: " << p->parent->key;
		else
		//	cout << "\n Dugumde ebeveyn yok.  ";
		if (p->right != NULL)
		//	cout << "\n Sag Cocuk: " << p->right->key;
		else
			cout << "\n Dugumde sag cocuk yok.  ";
		if (p->left != NULL)
			cout << "\n Sol Cocuk: " << p->left->key;
		else
			cout << "\n Dugumde sol cocuk yok.  ";
		cout << endl;
*/
		return true;

	}
}
