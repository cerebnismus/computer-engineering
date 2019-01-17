#include "huffman.hpp"

int main()
{
    Huffman *huffman = new Huffman("dene.txt");
    huffman->Kodla();
    cout<<*huffman;
    delete huffman;
}

/*
Makefile
hepsi: derle calistir
derle:
    g++ -I ./include/ -c ./lib/Dugum.o -c ./src/Dugum.cpp
    g++ -I ./include/ -c ./lib/Huffman.o -c ./src/huffman.cpp
    g++ -I ./include/ -c ./bin/Test -c ./main.cpp
*/