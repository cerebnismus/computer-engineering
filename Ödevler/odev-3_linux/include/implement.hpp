/* @file implement.hpp
* @description Implement Statement
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 20.12.2018
* @author Özge Öztataroglu ozge.oztataroglu@ogr.sakarya.edu.tr
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/

#ifndef IMPLEMENT_HPP
#define IMPLEMENT_HPP

#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include "BinarySearchTree.hpp"
#include "TreeException.hpp"
#include "Manage.hpp"


class Implement
{
private:
	int implement;

public:
	Implement() {} // constructor !
	void BST_implement();
	Manage m;
};

void Implement::BST_implement()
{
//	BST *agac = new BST();
//	BST *sub_tree = agac;
		
	std::string user_input;
	std::cout << "Yukseklik: ";
	std::cin >> user_input;

	BinarySearchTree<int> *agac = new BinarySearchTree<int>();
	BinarySearchTree<int> *agac = agac;

	std::cout<<std::endl<<"Levelorder :";
	agac->Levelorder();
		
}

template <typename Nesne>
void max_del() 
{
	system("clear");
	BinarySearchTree::agac->AraveSil(BinarySearchTree::agac->maxDeger());
	std::cout << "[ UYARI ] Agaclardan Maksimum Deger Cikartildi." << std::endl;
	// agac->Levelorder();
	m.start();
}

template <typename Nesne>
void min_del()
{
	system("clear");
	BinarySearchTree::agac->AraveSil(BinarySearchTree::agac->minDeger());
	std::cout << "[ UYARI ] Agaclardan Minimum Deger Cikartildi." << std::endl;
	// agac->Levelorder();
	m.start();
}


#endif //IMPLEMENT_HPP