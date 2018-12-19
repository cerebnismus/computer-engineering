

string sayiEncode(int sayi, int uzunluk)
{
    string olusan;
    for(int i=0;i<uzunluk;i++)
    {
        if(sayi >> i & 0x01)
            olusan.insert(0, "1");
        else olusan.insert(0, "0");
    }
    std::cout<<number<<" "<<olusan.c_str()<<std::endl;
    return olusan;
}

int yaziEncode(string yazi)
{
    int olusan = 0;
    int j = 0;
    for(int i=yazi.size()-1;i>=0;i--,j++)
        if(yazi[i] == '1') olusan = olusan | 0x01 << j;
    return olusan;
}
