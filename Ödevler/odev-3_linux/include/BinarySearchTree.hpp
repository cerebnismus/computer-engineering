/* @file BinarySearchTree.hpp
* @description BST Functions
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 20.12.2018
* @author Özge Öztataroglu ozge.oztataroglu@ogr.sakarya.edu.tr
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <string>
#include <cstring>
#include <string.h>
#include <iostream>
#include <cmath>
#include "TreeException.hpp"
#include "ElemanYok.hpp"
/*
struct node* newNode(int data)  
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data  = data; 
  node->sol  = NULL; 
  node->right = NULL; 
    
  return(node); 
}

template <typename Nesne>
struct node* mergeTrees(struct node *root1, struct node *root2, int m, int n) 
{ 
    // Store inorder traversal of first tree in an array arr1[] 
    Dugum<Nesne> *arr1 = new int[m]; 
    Dugum<Nesne> i = 0; 
    storeInorder(root1, arr1, &i); 
  
    // Store inorder traversal of second tree in another array arr2[] 
    Dugum<Nesne> *arr2 = new int[n]; 
    Dugum<Nesne> j = 0; 
    storeInorder(root2, arr2, &j); 
  
    // Merge the two sorted array into one 
    Dugum<Nesne> *mergedArr = merge(arr1, arr2, m, n); 
  
    // Construct a tree from the merged array and return root of the tree 
    return sortedArrayToBST (mergedArr, 0, m+n-1); 
}

struct node* sortedArrayToBST(int arr[], int start, int end) 
{ 
    if (start > end) 
      return NULL; 
  
    int mid = (start + end)/2; 
    struct node *root = newNode(arr[mid]); 

    root->left =  sortedArrayToBST(arr, start, mid-1); 
    root->right = sortedArrayToBST(arr, mid+1, end); 
  
    return root; 
}
*/
template <typename Nesne>
struct Dugum{
	Nesne veri;
	Dugum<Nesne> *sol;
	Dugum<Nesne> *sag;
	Dugum(const Nesne& vr,Dugum<Nesne> *sl=NULL,Dugum<Nesne> *sg=NULL){
		veri=vr;
		sol=sl;
		sag=sg;
	}
};

template <typename Nesne>
class BinarySearchTree{
	private:
		Dugum<Nesne> *root;
		
		void AraveEkle(Dugum<Nesne> *&alt_Dugum, const Nesne &yeni){
			if(alt_Dugum == NULL) alt_Dugum = new Dugum<Nesne>(yeni);
			else if(yeni < alt_Dugum->veri)
				AraveEkle(alt_Dugum->sol,yeni);
			else if(yeni > alt_Dugum->veri)
				AraveEkle(alt_Dugum->sag,yeni);
			else return; // Ayn� eleman var.
		}
		bool AraveSil(Dugum<Nesne> *&alt_Dugum,const Nesne &yeni)
		{			
			if(alt_Dugum == NULL) return false; //Eleman yok
			if(alt_Dugum->veri == yeni)
				return DugumSil(alt_Dugum);
			else if(yeni < alt_Dugum->veri)
				return AraveSil(alt_Dugum->sol,yeni);
			else
				return AraveSil(alt_Dugum->sag,yeni);
		}
		bool DugumSil(Dugum<Nesne> *&alt_Dugum)
		{			
			Dugum<Nesne> *silinecekDugum = alt_Dugum;
			
			if(alt_Dugum->sag == NULL) alt_Dugum = alt_Dugum->sol;
			else if(alt_Dugum->sol == NULL)alt_Dugum = alt_Dugum->sag;
			else{
				silinecekDugum = alt_Dugum->sol;
				Dugum<Nesne> *ebeveynDugum = alt_Dugum;
				while(silinecekDugum->sag != NULL){
					ebeveynDugum=silinecekDugum;
					silinecekDugum=silinecekDugum->sag;
				}
				alt_Dugum->veri = silinecekDugum->veri;
				if(ebeveynDugum == alt_Dugum) alt_Dugum->sol = silinecekDugum->sol;
				else ebeveynDugum->sag = silinecekDugum->sol;
			}
			delete silinecekDugum;
			return true;
		}
		void Inorder(Dugum<Nesne> *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Inorder(alt_Dugum->sol);
				cout<<alt_Dugum->veri<<" ";
				Inorder(alt_Dugum->sag);
			}
		}
		void Preorder(Dugum<Nesne> *alt_Dugum) const{
			if(alt_Dugum != NULL){
				cout<<alt_Dugum->veri<<" ";
				Preorder(alt_Dugum->sol);
				Preorder(alt_Dugum->sag);
			}
		}
		void Postorder(Dugum<Nesne> *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Postorder(alt_Dugum->sol);
				Postorder(alt_Dugum->sag);				
				cout<<alt_Dugum->veri<<" ";
			}
		}	
		void Levelorder(Dugum<Nesne> *alt_Dugum,int seviye)const{
			if(alt_Dugum == NULL) return;
			if(seviye == 0) cout<<alt_Dugum->veri<<" ";
			else{
				Levelorder(alt_Dugum->sol,seviye-1);
				Levelorder(alt_Dugum->sag,seviye-1);
			}
		}
		int Yukseklik(Dugum<Nesne> *alt_Dugum)const{
			if(alt_Dugum == NULL) return -1;
			return 1+max(Yukseklik(alt_Dugum->sol),Yukseklik(alt_Dugum->sag));
		}
		bool Ara(Dugum<Nesne> *alt_Dugum,const Nesne &aranan){
			if(alt_Dugum == NULL) return false;
			if(alt_Dugum->veri == aranan) return true;
			if(aranan < alt_Dugum->veri) return Ara(alt_Dugum->sol,aranan);
			if(aranan > alt_Dugum->veri) return Ara(alt_Dugum->sag,aranan);
		}
		public:
			BinarySearchTree() { root = NULL; }

			int maxDeger(Dugum<Nesne> *alt_Dugum)
			{
    			if (alt_Dugum == nullptr) throw TreeException("TreeException: Empty tree");
				return maxDegerNonNull(alt_Dugum, alt_Dugum->veri);
			}

			int maxDegerNonNull(Dugum<Nesne>* alt_Dugum, int suankiEnBuyuk)
			{
    			if (alt_Dugum == NULL) { return suankiEnBuyuk; }
				suankiEnBuyuk = suankiEnBuyuk > alt_Dugum->veri ? suankiEnBuyuk : alt_Dugum->veri;

    			int solMax  = maxDegerNonNull(alt_Dugum->sol,  suankiEnBuyuk);
	    		int sagMax = maxDegerNonNull(alt_Dugum->sag, suankiEnBuyuk);

    			return solMax > sagMax ? solMax : sagMax;
			}

			int minDeger(Dugum<Nesne> *alt_Dugum) 
			{
    			if (root == NULL) throw TreeException("TreeException: Dugum yok");
    			if (alt_Dugum == NULL) throw TreeException("TreeException: sol alt dugum yok");
  				while (alt_Dugum->sol != NULL) { alt_Dugum = alt_Dugum->sol; } return(alt_Dugum->veri); 
			}
			bool Bosmu() const{
				return root == NULL;
			}
			void Ekle(const Nesne &yeni)
			{
				AraveEkle(root,yeni);
			}
			void Sil(const Nesne &veri)
			{
				if(AraveSil(root,veri) == false) throw TreeException("TreeException: Veri yok");
			}
			void Inorder() const{
				Inorder(root);
			}
			void Preorder() const{
				Preorder(root);
			}
			void Postorder() const{
				Postorder(root);
			}
			void Levelorder()const{
				int h = Yukseklik();
				for(int level=0;level<=h;level++)
					Levelorder(root,level);
			}
			bool Arama(const Nesne &aranan){
				return Ara(root,aranan);
			}
			void Temizle(){
				while(!Bosmu()) DugumSil(root);
			}
			int Yukseklik()const{
				return Yukseklik(root);
			}
			~BinarySearchTree(){
				Temizle();
			}		
};

#endif // BINARY_SEARCH_TREE_HPP