#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <fstream>
#include <cstring>
#include <dugum.hpp>

class Huffman{
    private:
    Dugum *root;
    string girdi;
    int harfler;
    // ASCII 0-255
    Dugum* AgacOlustur(int frek[]);
    void KodOlustur(Dugum*,string);
    // özyinelemeli fonsiyon
    int MinDugumIndeks(Dugum* dugumler[]);
    // içinde dügüm adresi tutan dizi parametresi
    void DosyaOku(string);
    void inorder(Dugum*);
    void SilDugum(Dugum*);

    public:
    Huffman(string);
    void Kodla();
    friend ostream& operator<<(ostream&,Huffman&);
    ~Huffman();
};

#endif // HUFFMAN_HPP