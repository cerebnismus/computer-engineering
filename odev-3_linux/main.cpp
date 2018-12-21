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
        if (i == 0) {
             std::cout << "# ROOT TREE : ";
        } else {
            std::cout << "# " << i + 1 << ". TREE   : ";
        }

        for (int j = 0; j < trees_elem_list[i]; ++j) {
            int data = randomGenerator(1,500);
            tree_list[i].insert(data);
            std::cout << " [" << data << "] ";
        }

        std::cout << std::endl;
    }


   std::cout << std::endl << "### Result" << std::endl << std::endl;


    for (size_t i = 0 ; i < input_len ;i++) {
        if (i == 0) {
             std::cout << "# ROOT TREE";
        } else {
            std::cout << "# " << i + 1 << ". TREE";
        }

        std::cout  << std::endl << "# inorder  : ";
        tree_list[i].inorder_print();

        std::cout  << std::endl << "# postorder: ";
        tree_list[i].postorder_print();

        std::cout << std::endl << "# preorder : " ;
        tree_list[i].preorder_print();

        std::cout << std::endl << "-----------------------" << std::endl << std::endl;

    }


    for (size_t i = 0 ; i < input_len ;i++) {
        tree_list[i].destroy_tree();
    }
}
