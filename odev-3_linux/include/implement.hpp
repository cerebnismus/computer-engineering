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
#include <BST.hpp>

class Implement
{
private:
	int implement;
public:
	Implement() {} // constructor
	void BST_implement();
};

	void Implement::BST_implement()
	{ // total node pieces is must be 2^h+1
	
		BST *agac = new BST();
		BST *sub_tree = agac;
		
		std::string user_input;
		std::cout << "values: ";
		std::cin >> user_input;

		std::cout<<"Inorder :";
		agac->Inorder();
		std::cout<<std::endl<<"Preorder :";
		agac->Preorder();
		std::cout<<std::endl<<"Postorder :";
		agac->Postorder();
		std::cout<<std::endl<<"Levelorder :";
		agac->Levelorder();
	}


#endif //IMPLEMENT_HPP