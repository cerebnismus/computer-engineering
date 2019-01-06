/* @file TreeException.hpp
* @description BST Functions
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 20.12.2018
* @author Özge Öztataroglu ozge.oztataroglu@ogr.sakarya.edu.tr
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/

#ifndef TREEEXCEPTION_HPP
#define TREEEXCEPTION_HPP

#include <cstring>
#include <string.h>
#include <cmath>
#include <exception>
#include <string>
#include <cstring>
#include <iostream>
#include <cstddef> // definition of NULL
#include <cassert> // for assert()

class TreeException : public std::exception
{
public:
   TreeException(const std::string & message ="")
      { std::cout << message.c_str() << std::endl; 
        exception();
   }
}; 

#endif // TREEEXCEPTION_HPP