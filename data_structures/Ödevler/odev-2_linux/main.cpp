/**
* @file main.cpp
* @description Driver code to test the implementation
* @course II. Ogretim D Grubu
* @assignment Odev-II
* @date 05.12.2018
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/

#include <manage.hpp>
#include <stacker.hpp>
#include <implement.hpp>

int main(int argc, char ** argv) 
{
	system("clear");
	Manage m;
	stack mst;
	implement im;
    num_of_node = 0;

	/* Set head as NULL from implementation header file. */

	// Node:
	std::cout << "Veri Yapilari - Odev II" << std::endl << std::endl;
	std::cout << "--------[ MAIN FUNC ]--------" << std::endl;
	std::cout << "sayi.txt = ";
	std::ifstream myfile_0("sayi.txt");
	while(myfile_0 >> tmp) { std::cout << tmp << " "; num_of_node++; }
	if (num_of_node == 0) { throw std::runtime_error("[ ERROR ] Dosya okunamiyor."); }
	myfile_0.close();
	std::cout << " " << std::endl;

	// Stack:
	std::ifstream myfile_1("sayi.txt");
	while(myfile_1 >> val) { mst.push(val); }
	std::cout << "st_stack = ";
	mst.show();
	myfile_1.close(); 
	std::cout << " " << std::endl;

	// Doubly Circular Linked List:
	std::ifstream myfile_2("sayi.txt");
	while(myfile_2 >> imp) { im.InsertAtHead(imp); }
	std::cout << "DCLL = ";
	im.Print();
	myfile_2.close(); 

/*
	// Doubly Circular Linked List - Stack Implementation:
	head = NULL; 
	mst.xchange();
    for (int i = 0; i < num_of_node; i++)
    { 
		mst.exchange
		im.InsertAtHead(mst.ex);
	}
	std::cout << "S_DCLL = ";
	im.Print();
*/

	// Node:
	std::cout << "Toplam " << num_of_node << " dugum olusturuldu." << std::endl << std::endl;

    // Menu Statements:
	m.start();
}