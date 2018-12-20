/* @file manage.hpp
* @description Menu Statement
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 05.12.2018
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/

#ifndef MANAGE_HPP
#define MANAGE_HPP

#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream> // Read & write data library.
#include <iomanip> // setw etc.
#include <exception> // throw.
#include <iostream> // standart input/output library.
#include <implement.hpp>
#include <bst.hpp>
#include <TreeException.hpp>

class Manage 
{
public:
	Manage() {} // constructor
	Implement i;
	void start();
};

	void Manage::start()
	{
    	short choice;
    	while(true) 
		{
			/* Choose Menu */
    		std::cout << "--------[ MENU ]--------" << std::endl;
    		std::cout << "1 - Agaclardan Maksimum Degeri Cikar" << std::endl;
        	std::cout << "2 - Agaclardan Minimum Degeri Cikar" << std::endl;
        	std::cout << "3 - Tum Agaclari Levelorder Yazdir" << std::endl;
        	std::cout << "4 - Cikis" << std::endl;
    		std::cout << "Secim: ";
    		std::cin >> choice;

    		switch(choice) 
			{
    			case 1:
   			    
				i.agac->max_del();
				break;

    			case 2:
				
				i.agac->min_del();
    			break;

    			case 3:
    			
				i.agac->Levelorder();
    			break;

    			case 4:
				system("clear");
				std::cout << "[ WARNING ] Program sonlandirildi." << std::endl;
    			exit(0);
    			break;

    			default:
    			std::cout << "[ WARNING ] Tekrar deneyin." << std::endl;
    			continue;
	    	}
		}
    }

#endif // MANAGE_HPP
