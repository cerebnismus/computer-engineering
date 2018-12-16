/**
* @file main.cpp
* @description Driver code to test the implementation
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 12.12.2018
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/

#include <BST.hpp>
#include <error.hpp>
#include <manage.hpp>
#include <string>

int main(int argc, char ** argv) 
{
	// Set console as blank:
	system("clear");
	Manage m;
    char str[10000];
	int h;
	std::string user_input;
	int num_of_tree;
	BST *agac = new BST();

	std::cout << "Veri Yapilari - Odev III" << std::endl << std::endl;
	std::cout << "--------[ MAIN FUNC ]--------" << std::endl;

	// total node pieces is 2^h+1
	std::cout << "values: ";
	std::cin >> user_input;

	BST *sub_tree = agac;

	for(size_t i = 0; i < user_input.length(); i++)
	{
		char tmp = user_input[i];
		int level = std::atoi(&tmp);

		
		while(sub_tree->Yukseklik() < level ){
			BST *last_position = sub_tree->Ekle(random());
		}
		
		//sadinin kodları üzerinden buradaki mantığı uygula

		sub_tree = last_position;

	}
	

   	for(int i=1; i<=10000; i++){
		char c = getchar();
        if (c=='\n' || c==EOF) break;
        	str[i]=c;
			i++;
			num_of_tree = i;
	}

   	for(int i=1; i<=num_of_tree; i++){
		h = str[i];
		int tree_size = std::pow(2, h) + 1;
		std::cout << "num_of_tree: " << tree_size << std::endl;
		std::cout << "tree_size: " << tree_size << std::endl << std::endl;
		i++;
   		for(int i=1; i<=tree_size; i++){
			int v1 = rand() % 100; // v1 in the range 0 to 99
			agac->Ekle(v1);
		}
	}

	std::cout<<"Inorder :";
	agac->Inorder();
	std::cout<<std::endl<<"Preorder :";
	agac->Preorder();
	std::cout<<std::endl<<"Postorder :";
	agac->Postorder();
	std::cout<<std::endl<<"Levelorder :";
	agac->Levelorder();


    // Menu Statements:
	m.start();
	delete agac;
}
