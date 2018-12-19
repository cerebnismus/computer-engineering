/**
* @file main.cpp
* @description Implementation of Binary Search Tree
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 20.12.2018
* @author Özge Öztataroglu ozge.oztataroglu@ogr.sakarya.edu.tr
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/

#include <BST.hpp>
#include <implement.hpp>
#include <manage.hpp>
#include <string>

int main(int argc, char ** argv) 
{
	system("clear");
	std::cout << "Veri Yapilari - Odev III" << std::endl << std::endl;
	std::cout << "--------[ MAIN FUNC ]--------" << std::endl;

    // Implement Statements:
	Implement i;
	i.BST_implement();

    // Menu Statements:
	Manage m;
	m.start();

	// delete agac;
}
