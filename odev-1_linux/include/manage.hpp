/******************************************************************************
/* @file manage.hpp
/* @description User interface loop
/* @course II. Ogretim B Grubu
/* @assignment Project
/* @date 15.12.2018
/* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
/******************************************************************************/

#ifndef MANAGE_HPP
#define MANAGE_HPP
#include <string>
#include <fstream>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <exception>
#include <implement.hpp>

class Manage 
{
public:
	Manage() // constructor
	{
		// code here
	}
	void start();
};

	void Manage::start()
	{
		stack st;
		implement i;
    	short choice;
    	while(true) 
		{
			/* Choose Menu (User interface loop) */
    		std::cout << "--------[ MANAGE MENU ]--------" << std::endl;
    		std::cout << "1 - Sola Hareket" << std::endl;
        	std::cout << "2 - Saga Hareket" << std::endl;
        	std::cout << "3 - Bir dugumun durumlarini yazdir" << std::endl;
        	std::cout << "4 - Tum durumlari yazdir" << std::endl;
        	std::cout << "5 - Cikis" << std::endl;
    		std::cout << "Secim: ";
    		std::cin >> choice;

    		switch(choice) 
			{
    			case 1:
   			    i.ShiftLeft();
				break;

    			case 2:
				i.ShiftRight();
    			break;

    			case 3:
    			i.OneNode();
    			break;

    			case 4:
    			i.AllNodes();
    			break;

    			case 5:
				system("clear");
				std::cout << "[ WARNING ] Program ended." << std::endl;
    			exit(0);
    			break;

    			default:
    			std::cout << "[ WARNING ] Try again." << std::endl;
    			continue;
	    	}
		}
    }

#endif // MANAGE_HPP
