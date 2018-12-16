/**
* @file number.cpp
* @description yonetim islemlerinin saglanmasi
* @course II. Ogretim D Grubu
* @assignment Odev-I
* @date 31.10.2018
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <number.hpp>
#include <manage.hpp>
#include <implement0.hpp>

class Number 
{
public:
Number::Number(std::string filename)
{
    // Stack Constructor
}

void Number::print_list()
{	
	std::ifstream myfile(filename);
	unsigned int tmp;
	unsigned int num_of_tmp = 0;
  	std::cout << "Okunan Sayilar: [ ";
 	while(myfile >> tmp) { std::cout << tmp << " "; num_of_tmp++; }
	if (num_of_tmp == 0) { throw std::runtime_error("HATA ] Dosya okunamiyor. Bos yada bozuk format."); }
 	std::cout << "] - Toplam " << num_of_tmp << " adet sayi okundu." << std::endl;
    myfile.close();
}

void Number::shift_left()
{


}

void Number::shift_right()
{


}

void Number::one_node()
{


}

void Number::all_node()
{


}

};