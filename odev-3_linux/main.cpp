/**
* @file main.cpp
* @description Driver code to test the implementation
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 12.12.2018
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
