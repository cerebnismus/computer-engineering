#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <exception>
using namespace std;
int main(int argc, char * argv[])
{
    std::ifstream myfile("sayi.txt");

    int k;
    unsigned int pieces = 0;
    std::cout << "Okunan Sayilar: [ ";
    while(myfile >> k) { std::cout << k << " "; pieces++; }
    std::cout << "] - Toplam " << pieces << " adet sayi okundu." << std::endl;

   	int tmp;
	int num_of_tmp = 0;
   	std::cout << "Okunan Sayilar: [ ";
   	while(myfile >> tmp) { std::cout << tmp << " "; num_of_tmp++; }
   	std::cout << "] - Toplam " << num_of_tmp << " adet sayi okundu." << std::endl;
	if (num_of_tmp == 0) { throw std::runtime_error("[HATA] Dosya okunamıyor. Boş yada bozuk format."); }

   	myfile.close();
}
