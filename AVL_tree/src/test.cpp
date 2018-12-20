#include "AVLTree.hpp"

int main(){
	AVLTree<int> *agac = new AVLTree<int>();
	agac->Ekle(15);
	agac->Ekle(1);
	agac->Ekle(157);
	agac->Ekle(215);
	agac->Ekle(120);
	agac->Ekle(132);
	agac->Ekle(310);
	agac->Ekle(500);
	agac->Ekle(125);
	agac->Ekle(137);
	agac->Ekle(300);
	agac->Ekle(115);
	cout<<"Inorder :";
	agac->Inorder();
	cout<<endl<<"Preorder :";
	agac->Preorder();
	cout<<endl<<"Postorder :";
	agac->Postorder();
	cout<<endl<<endl;	
	cout<<endl<<"Level Order :";
	agac->Levelorder();
	cout<<endl<<endl;
	cout<<"Yukseklik:"<<agac->Yukseklik()<<endl;
	delete agac;
	return 0;
}