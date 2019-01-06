/*******************************************************************************
/* @file implement.hpp
/* @description Postgresql Database Implementation
/* @course II. Ogretim B Grubu
/* @assignment Project
/* @date 15.12.2018
/* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
/******************************************************************************/

#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>
using namespace std;

class Dugum{
    public:
    char karakter;
    int frekans;
    string kod;
    Dugum *sol;
    Dugum *sag;

    Dugum(char kr, int frek,Dugum *sl=NULL,Dugum *sg=NULL);
    bool Yaprakmi()const;
    bool operator==(Dugum&);
    bool operator!=(Dugum&);
    bool operator>(Dugum&);
};

#endif // DUGUM_HPP