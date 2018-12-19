/**
* @file manage.hpp
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

class Manage 
{
public:
	Manage() {} // constructor
	void start();
};

	void Manage::start()
	{
    	short choice;
    	while(true) 
		{
			/* Choose Menu */
    		std::cout << "--------[ MANAGE MENU ]--------" << std::endl;
    		std::cout << "1 - Agaclardan Maksimum Degeri Cikar" << std::endl;
        	std::cout << "2 - Ağaçlardan Minimum Değeri Cikar" << std::endl;
        	std::cout << "3 - Tum Agaclari Level Order Yazdir" << std::endl;
        	std::cout << "4 - Cikis" << std::endl;
    		std::cout << "Secim: ";
    		std::cin >> choice;

    		switch(choice) 
			{
    			case 1:
   			    
				//i.ShiftLeft();
				break;

    			case 2:
				
				//i.ShiftRight();
    			break;

    			case 3:
    			
				//i.OneNode();
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
