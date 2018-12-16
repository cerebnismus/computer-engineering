#ifndef BST_HPP
#define BST_HPP

#include <cmath>
#include <error.hpp>
#define SIZE 10000

class BST{
	private:
		int *elemanlar;
		int IndeksDolulugu[SIZE];
		
		int Ara(const int& eleman, int suankiIndeks = 0){
			while(true){
				if(suankiIndeks == SIZE || IndeksDolulugu[suankiIndeks] == 0) return -1; // Eleman Yok
				if(elemanlar[suankiIndeks] == eleman && IndeksDolulugu[suankiIndeks] == 1){
					return suankiIndeks;
				}
				else if(eleman < elemanlar[suankiIndeks]) suankiIndeks = 2*suankiIndeks+1;
				else if(eleman > elemanlar[suankiIndeks]) suankiIndeks = 2*suankiIndeks+2;
			}
		}		
		bool ikininKatimi(int x)
		{
			while (((x % 2) == 0) && x > 1) 
				x /= 2;
			return (x == 1);
		}
		int EnKucukDeger(int i=0)
		{
			if(2*i+1 > SIZE) return i;
			else if(IndeksDolulugu[2*i+1] == 0) return i;
			else return EnKucukDeger(2*i+1);
		}
	public:
		BST(){
			elemanlar=new int[SIZE];
			Temizle();
		}
		void Ekle(const int& eleman){
			int suankiIndeks = 0;
			while(true){
				if(IndeksDolulugu[suankiIndeks] == 0){
					elemanlar[suankiIndeks]=eleman;
					IndeksDolulugu[suankiIndeks] = 1;
					break;
				}
				else if(eleman < elemanlar[suankiIndeks]) suankiIndeks = 2*suankiIndeks+1;
				else if(eleman > elemanlar[suankiIndeks]) suankiIndeks = 2*suankiIndeks+2;
				else return; // Aynı eleman var ağaca eklenmiyor
			}
		}		
		bool Varmi(const int& eleman){
			if(Ara(eleman) == -1) return false;
			return true;
		}
		int Yukseklik(int indeks=0){
			if(IndeksDolulugu[indeks] == 0) return -1;
			return 1+fmax(Yukseklik(2*indeks+1),Yukseklik(2*indeks+2));//using fmax instead of max
		}
		void Sil(const int& eleman, int ind=0){
			int i = Ara(eleman, ind);
			if(i == -1) throw Error(1);
			else{
				IndeksDolulugu[i] = 0;		
				if(IndeksDolulugu[2*i+2] == 0)
				{
					if(IndeksDolulugu[2*i+1] == 1) //Sadece sol çocuğu varsa
					{
						int k = 2*i+1; int yedek[SIZE];
						for(int iter = 0; iter < SIZE ; iter++) yedek[iter] = 0;
						yedek[0] = k; int index = 0;
						
						// BFS algoritması kullanılarak sol alt ağaçtaki düğümler silinen düğümün yerine getiriliyor.
						for(int iter = 0; iter < SIZE && yedek[iter] != 0; iter++) 
						{
							for(int x = 0; x < SIZE; x++)
							{
								if(ikininKatimi(yedek[iter]+1-x))
								{
									elemanlar[(yedek[iter]+x-1)/2] = elemanlar[yedek[iter]];
									IndeksDolulugu[(yedek[iter]+x-1)/2] = 1;
									IndeksDolulugu[yedek[iter]] = 0;
									break;
								}
							}
							if(IndeksDolulugu[2*yedek[iter] + 1] != 0)
							{
									yedek[++index] = 2*yedek[iter] + 1;
							}
							if(IndeksDolulugu[2*yedek[iter] + 2] != 0)
							{
									yedek[++index] = 2*yedek[iter] + 2;
							}
						}
					}
				}
				else
				{
					if(IndeksDolulugu[2*i+1] == 0) //Sadece sağ çocuğu varsa
					{
						int k = 2*i+2; int yedek[SIZE];
						for(int iter = 0; iter < SIZE ; iter++) yedek[iter] = 0;
						yedek[0] = k; int index = 0;
						
						// BFS algoritması kullanılarak sağ alt ağaçtaki düğümler silinen düğümün yerine getiriliyor.
						for(int iter = 0; iter < SIZE && yedek[iter] != 0; iter++){
							for(int x = 0; x < SIZE; x++){
								if(ikininKatimi((yedek[iter]+x)/2+1)){
									elemanlar[(yedek[iter]-2-x)/2] = elemanlar[yedek[iter]];
									IndeksDolulugu[(yedek[iter]-2-x)/2] = 1;
									break;
								}
							}
							IndeksDolulugu[yedek[iter]] = 0;
							if(IndeksDolulugu[2*yedek[iter] + 1] != 0)
							{
									yedek[++index] = 2*yedek[iter] + 1;
							}
							if(IndeksDolulugu[2*yedek[iter] + 2] != 0)
							{
									yedek[++index] = 2*yedek[iter] + 2;
							}
						}
					}
					else //İki çocuğu varsa
					{
						int x = EnKucukDeger(2*i+2);
						int kopyalanacak = elemanlar[x];
						IndeksDolulugu[i] = IndeksDolulugu[x];
						elemanlar[i] = elemanlar[x];
						Sil(kopyalanacak, x);
					}
				}
			}
		}
		void Inorder(int suankiIndeks=0){
		 if(suankiIndeks < SIZE && IndeksDolulugu[suankiIndeks] != 0){
				Inorder(2*suankiIndeks+1);
				std::cout<<elemanlar[suankiIndeks]<<" ";
				Inorder(2*suankiIndeks+2);
		  }
		}
		void Preorder(int suankiIndeks=0){
		 if(suankiIndeks < SIZE && IndeksDolulugu[suankiIndeks] != 0){
				std::cout<<elemanlar[suankiIndeks]<<" ";
				Preorder(2*suankiIndeks+1);
				Preorder(2*suankiIndeks+2);
		  }
		}
		void Postorder(int suankiIndeks=0){
		 if(suankiIndeks < SIZE && IndeksDolulugu[suankiIndeks] != 0){
				Postorder(2*suankiIndeks+1);
				Postorder(2*suankiIndeks+2);
				std::cout<<elemanlar[suankiIndeks]<<" ";
		  }
		}
		void Levelorder(){
			for(int i=0;i<SIZE;i++){
				if(IndeksDolulugu[i] == 1)
					std::cout<<elemanlar[i]<<" ";
			}
		}
		void Temizle(){	
			for(int i=0;i<SIZE;i++) IndeksDolulugu[i] = 0;
		}
		~BST(){
			delete [] elemanlar;
		}
};

#endif