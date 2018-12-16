#ifndef ERROR_H
#define ERROR_H

#include <cmath>
#include <string>
#include <BST.hpp>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */

class Error
{
private:
	int error;
public:
	Error(int error):error(error){}
	void Message()
	{
		switch (error)
		{
		case 1:
			std::cout<<"doesn't exist"<<std::endl;
			break;
		case 2:
			std::cout<<"out of"<<std::endl;
			break;
		case 3:
			std::cout<<"empty"<<std::endl;
			break;
		case 4:
			std::cout<<"full"<<std::endl;
			break;
		default:
			std::cout<<"other"<<std::endl;
		break;
		}
	}

};


#endif //ERROR_H