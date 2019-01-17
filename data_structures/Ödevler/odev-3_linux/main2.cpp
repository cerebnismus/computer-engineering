/**
* @file main.cpp
* @description Implementation of Binary Search Tree
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 20.12.2018
* @author Özge Öztataroglu ozge.oztataroglu@ogr.sakarya.edu.tr
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
**/

#include <manage.hpp>
#include <implement.hpp>
#include <TreeException.hpp>
#include <BinarySearchTree.hpp>

int main(int argc, char ** argv) 
{
	system("clear"); // Terminal ekranini temizle.

/** 
 * kullanıcıdan bir sayı isteyecektir. sayının basamak uzunluğu çok fazla olabilir.
 * her basamaktaki değeri bir ağacın yüksekliği kabul edip, bu yüksekliğe gelene kadar
 * rastgele sayılardan meydana gelen ikili arama ağaçları oluşturacaktır. Oluşan bu ağaçlar 
 * yükseklik değerleri baz alınarak bir ikili arama ağacında tutulacaktır.
**/

    // Implement Statements from implement.hpp header file
	Implement i;
	i.BST_implement();
 
 	// Daha sonra menü ekrana gelmelidir.
    // Menu Statements from manage.hpp header file
	Manage m;
	m.start();

	~BinarySearchTree(); // destructor function !!!
	// delete agac;
}
