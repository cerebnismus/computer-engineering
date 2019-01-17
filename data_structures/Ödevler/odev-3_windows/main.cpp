/**
* @file main.cpp
* @description Implementation of Binary Search Tree
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 20.12.2018
* @author Özge Öztataroglu ozge.oztataroglu@ogr.sakarya.edu.tr
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
**/

#include <string>

#include <binary_search_tree.hpp>
#include <random_data.hpp>



int main(int argc, char ** argv) {

    std::string input_data;
    std::cout << "input_data: " ;
    std::cin >> input_data;

    size_t input_len = input_data.length();

    int *trees_elem_list = new int[input_len];

    for (size_t i = 0; i < input_len; ++i) {
        trees_elem_list[i] = input_data[i] - '0';
    }

    std::cout << std::endl << "Number of Trees: " << input_len << std::endl << std::endl;
    for (size_t i = 0; i < input_len; ++i) {
            std::cout << i + 1 << ". tree depth : " << trees_elem_list[i] << std::endl;
    }

    std::cout << std::endl << "### Initializing..." << std::endl << std::endl;

    BinarySearchTree *tree_list = new BinarySearchTree[input_len];

    BinarySearchTree *tree = &tree_list[0];


    for (size_t i = 0 ; i < input_len ;i++) {

        BinarySearchTree *current_tree = &(tree_list[i]);

        if (i == 0) {
             std::cout << "# ROOT TREE : ";
        } else {
            current_tree->set_root(tree_list[i - 1].last_elem());
            std::cout << "# " << i + 1 << ". TREE   : ";
        }

        while (current_tree->depth() < trees_elem_list[i]) {
            int data = randomGenerator(1,500);
            current_tree->insert(data);
            std::cout << " [" << data << "] ";
        }


        std::cout << std::endl;
    }


   std::cout << std::endl << "### Result" << std::endl << std::endl;


    for (size_t i = 0 ; i < input_len ;i++) {
        if (i == 0) {
             std::cout << "# ROOT TREE";
        } else {
            std::cout << "# " << i + 1 << ". LEVEL TREE";
        }

        std::cout  << std::endl << "# inorder  : ";
        tree_list[i].inorder_print();

        std::cout  << std::endl << "# postorder: ";
        tree_list[i].postorder_print();

        std::cout << std::endl << "# preorder : " ;
        tree_list[i].preorder_print();

        std::cout << std::endl << "# levelorder : " ;
        tree_list[i].levelorder_print();


        std::cout << std::endl << "# min : " << tree_list[i].min();
        std::cout << std::endl << "# max : " << tree_list[i].max();

        std::cout << std::endl << "-----------------------" << std::endl << std::endl;

    }

    // MENU
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
    			case 1:  /*  
                    for (size_t i = 0 ; i < input_len ;i++) {
                        if (i == 0) {
                            tree_list[i].max() = nullptr;
                            std::cout << "# ROOT TREE";
                        } else {
                            tree_list[i].max() = nullptr;
                            std::cout << "# " << i + 1 << ". LEVEL TREE";
                        }
                        std::cout << std::endl << "# levelorder : " ;
                        tree_list[i].levelorder_print();
                    }		*/		
                    break;

    			case 2: /*
                    for (size_t i = 0 ; i < input_len ;i++) {
                        if (i == 0) {
                            tree_list[i].max() = nullptr;
                            std::cout << "# ROOT TREE";
                        } else {
                            tree_list[i].max() = nullptr;
                            std::cout << "# " << i + 1 << ". LEVEL TREE";
                        }
                        std::cout << std::endl << "# levelorder : " ;
                        tree_list[i].levelorder_print();
                    }	    */			
                    break;

    			case 3:
                // tree_list[i].levelorder_print();
    			break;

    			case 4:
				system("cls");
				std::cout << "[ UYARI ] Program sonlandirildi." << std::endl;
    			exit(0);
    			break;

    			default:
    			std::cout << "[ UYARI ] Tekrar deneyin." << std::endl;
    			continue;
	    	}
		}
    tree->destroy_tree();
}
