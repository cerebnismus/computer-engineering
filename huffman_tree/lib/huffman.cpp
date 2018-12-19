#include "huffman.hpp"

Dugum* Huffman::AgacOlustur(int frek[])
{
    Dugum* dugumler[harfler];
    
    for(int i=0;i<harfler;i++)
    {
        if(frek[i] > 0) { dugumler[i] = new Dugum((char)i,frek[i]); }
        else { dugumler[i] = NULL; }
    }
    while(true) 
    { 
        int ilkIndeks = MinDugumIndeks(dugumler); 
        Dugum *min1 = dugumler[ilkIndeks];
        dugumler[ilkIndeks] = NULL;
        int ikinciIndeks = MinDugumIndeks(dugumler);
        if(ikinciIndeks == -1) return min1;
        Dugum *min2 = dugumler[ikinciIndeks];
        dugumler[ikinciIndeks] = NULL;
        dugumler[ilkIndeks] = new Dugum(0,min1->frekans+min2->frekans,min1,min2);    
    }
}

void Huffman::KodOlustur(Dugum *altDugum,string kod)
{
    if(altDugum->Yaprakmi())
    {
        KodOlustur(altDugum->sol,kod+'0');
        KodOlustur(altDugum->sag,kod+'1');
    }
    else
    {
        altDugum->kod = kod; 
        //postorder önce çocukları dolaşan recursive
    }
}

int Huffman::MinDugumIndeks(Dugum* dugumler[])
{
    Dugum *min;
    int minIndeks=-1;

    for(int i=0;i<harfler;i++)
        if(dugumler[i] != NULL)
        {
            min = dugumler[i];
            minIndeks = i;
            break;
        }
    for(int i=0;i<harfler;i++)
    {
        if(dugumler[i] == NULL) continue;
        if(*min > *dugumler[i])
        {
            min = dugumler[i];
            minIndeks = i;
        }
    }
return minIndeks;
}

void Huffman::DosyaOku(string)
{
    string satir;
    ifstream dosya(dosyaYolu.c_str());
    while(getline(dosya,satir))
    {
        girdi += satir;
        girdi += "\n";
    }
    dosya.close();
}

void Huffman::inorder(Dugum *altDugum)
{
    if(altDugum != NULL)
    {
        inorder(altDugum->sol);
        if(altDugum->Yaprakmi()) cout<<altDugum->karakter<<":"<<altDugum->kod<<endl;
        // if(altDugum->Yaprakmi()) cout<<altDugum->karakter<<":"<<altDugum->frekans<<endl;
        inorder(altDugum->sag);
    }
}

void Huffman::SilDugum(Dugum *altDugum)
{
    if(altDugum == NULL) return;
    SilDugum(altDugum->sol);
    SilDugum(altDugum->sag);
    delete altDugum;
    altDugum = NULL;
}

Huffman::Huffman(string dosyaYolu)
{
    root=NULL;
    harfler=256;
    girdi="";
    DosyaOku(dosyaYolu);
}

void Huffman::Kodla()
{
    char karakterler[girdi.size()];
    strcpy(karakterler,girdi.c_str());
    int frek[harfler];
    for(int i=0;i<harfler;i++) frek[i]=0;
    for(int i=0;i<girdi.size();i++) frek[karakterler[i]]++;
    root = AgacOlustur(frek);
    KodOlustur(root,"");
}

ostream& operator<<(ostream &ekran,Huffman &agac)
{
    ekran<<"Huffman Agaci ve Dugumleri"<<endl;
    agac.inorder(agac.root);
    return ekran;
}

Huffman::~Huffman()
{
    SilDugum(root);
}

};
