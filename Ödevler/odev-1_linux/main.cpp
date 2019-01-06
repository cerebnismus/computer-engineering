/**
* @file main.cpp
* @description Driver code to test the database implementation
* @course II. Ogretim B Grubu
* @assignment DBMS Project
* @date 15.12.2018
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/

#include <istream>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

#include <manage.hpp>
#include <implement.hpp>

int main(int argc, char ** argv) 
{
	system("clear");
	Manage m;
	//implement im;

	/* Set head as NULL from implementation header file. */

	// Node:
	std::cout << "Veri Tabanı Yönetim Sistemleri - Proje" << std::endl << std::endl;
	std::cout << "--------[ MAIN FUNC ]--------" << std::endl;
	std::cout << "Database = ";

	// Check database connection:

	if (num_of_node == 0) { throw std::runtime_error("[ ERROR ] Database connection failed."); }

	std::cout << "Toplam " << num_of_node << " dugum olusturuldu." << std::endl << std::endl;

    // Menu Statement:
	m.start();
}

//Program Functions
