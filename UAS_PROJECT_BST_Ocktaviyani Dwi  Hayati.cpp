//Ocktaviyani Dwi Hayati
//1910512018
//Kelas A
//Dr. Achmad Solichin, S.Kom., M.T.I
//UAS Praktikum Struktur Data dan Algoritma
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *P = NULL;

//insert bilangan
void insert (Node **tree, int val)
{
    if ((*tree)==NULL)
       {
        Node *B;
        B = new Node;
        B->data=val;
        B->left=NULL;
        B->right=NULL;
        (*tree) = B;
        (*tree) -> left = NULL;
        (*tree) -> right = NULL;
        printf("Data Bertambah!");
       }
    else if (val<(*tree)->data)
        insert(&(*tree)->left,val);
    else if (val>(*tree)->data)
        insert(&(*tree)->right,val);
    else if (val==(*tree)->data)
        printf("Data Sudah ada!");
}

///preorder
void preorder(Node * tree)
{
    if (tree)
    {
        printf("%d -> ",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }

}

//inorder
void inorder(Node * tree)
{
    if (tree)
    {
        inorder(tree->left);
        printf("%d -> ",tree->data);
        inorder(tree->right);
    }
}

//postorder
void postorder(Node * tree)
{
    if (tree)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d -> ",tree->data);
    }
}

//search bilangan
void search(Node **tree, int S)
{
    if((*tree) == NULL)
    {
        printf("TIDAK DITEMUKAN");
    }
    else if(S < (*tree)->data)
        search(&(*tree)->left,S);
    else if(S > (*tree)->data)
        search(&(*tree)->right,S);
    else if(S == (*tree)->data)
        printf("DITEMUKAN");
}

//menghapus
int height(Node *tree)
{
       if(tree == NULL)
              return -1;
       else{
              int u = height(tree->left);
        int v = height(tree->right);
        if(u > v)
          return u + 1;
        else
          return v + 1;
       }
}
void hapus (Node **tree, int H){
	Node *C;
	Node *R;
	C = (*tree);
	bool flag = false;
	while(C != NULL){
		if(C->data == H){
			flag = true;
			printf ("\nDitemukan\n");
			break;
		}
		else{
			R = C;
			if (H>C->data)
			C = C -> right;
			else
			C = C -> left;
		}
	}
	if(!flag){
		printf("Tidak Ditemukan");
		return;
	}
       if(height(P) == 0)
       {
              if( C->left== NULL && C->right == NULL)
              {
                (*tree) = NULL;
                return;
              }
       }
       else if(height(P) > 0)
       {
        	if( C->left== NULL && C->right == NULL)
              {
                if(R->left == C)
                    {
                        R->left = NULL;
                        delete C;
                    }
                    else
                    {
                    	R->right = NULL;
                        delete C;
                    }
                    return;
              }
              if((C->left == NULL && C->right != NULL)|| (C->left != NULL && C->right == NULL))
              {
                if(C->left == NULL && C->right != NULL)
                    {
                        if(R->left == C)
                        {
                        	R->left = C->right;
                            delete C;
                        }
                        else
                        {
                            R->right = C->right; 
                            delete C;
                        }
                    }
                  else
                  {
                    if(R->right == C)
                        {
                            R->left = C->left;
                            delete C;
                        }
                        else
                        {
                        R->right = C->left;
                        delete C;
                        }
                   }
                   return;
              }
              if (C->left != NULL && C->right != NULL)
              {
                Node *U;
                U = C->right;
                if((U->left == NULL) && (U->right == NULL))
                {
                    C = U;
                    delete U;
                    C->right = NULL;
                }
                    else
                    {
                    	if((C->right)->left != NULL)
                        {
                            Node* U2;
                            Node* U3;
                            U3 = C->right;
                            U2 = (C->right)->left;
                            while(U2->left != NULL)
                            {
                                U3 = U2;
                                U2 = U2->left;
                            }
                                C->data = U2->data;
                                delete U2;
                                U3->left = NULL;
                        }
                        else
                        {
                            Node* tmp;
                            tmp = C->right;
                            C->data = tmp->data;
                            C->right = tmp->right;
                            delete tmp;
                        }

                    }
                    return;
              }
       }
}


//mencari nilai terkecil
int findMin(){
	Node* C = P;
	while(C->left!=NULL){
		C=C->left;
	}
	return C->data;
}

//mencari nilai terbesar
int findMax(){
	Node* C = P;
	while(C->right!=NULL){
		C=C->right;
	}
	return C->data;
}


//menghapus seluruh bilangan
void reset(Node *tree){
	if(tree==NULL){
		reset(tree->left);
		reset(tree->right);
		delete tree;
	}
}

//menu pilihan
int main(){
	char pilihan;
	int S, H;
	while(true){
		system("cls");
		char data;
		printf("\t==BINARY SEARCH TREE==");
		printf("\nPilihan Menu");
		printf("\n(1) Insert");
		printf("\n(2) PreOrder");
		printf("\n(3) InOrder");
		printf("\n(4) PostOrder");
		printf("\n(5) Search");
		printf("\n(6) Delete");
		printf("\n(7) Nilai Terbesar");
		printf("\n(8) Nilai Terkecil");
		printf("\n(9) Reset");
		printf("\nMasukkan menu pilihan Anda: ");
		scanf("%c", &pilihan);
		fflush(stdin);
		switch(pilihan){
			//pilihan 1
			case '1':
				printf("\nMasukkan bilangan: ");
				scanf("%d", &data);
				insert (&P, data);
				_getch();
				break;
			//pilihan 2
			case '2':
				printf("\nPreOrder: ");
				if(P!=NULL)
				preorder(P);
				else
				printf("KOSONG");
				_getch();
				break;
			//pilihan 3
			case '3':
				printf("\nInOrder: ");
				if(P!=NULL)
				inorder(P);
				else
				printf("KOSONG");
				_getch();
				break;
			//pilihan 4
			case '4':
				printf("\nPostOrder: ");
				if(P!=NULL)
				postorder(P);
				else
				printf("KOSONG");
				_getch();
				break;
			//pilihan 5
			case '5':
				if(P!=NULL){
					printf("\nPreOrder: ");
					preorder(P);
					printf("\nInOrder: ");
					inorder(P);
					printf("\nPostOrder: ");
					postorder(P);
					printf("\nMasukkan bilangan yang ingin dicari: ");
					scanf("%d", &S);
					search(&P, S);
				}
				else
				printf("\nKOSONG");
				_getch();
				break;
			//pilihan 6
			case '6':
				if(P!=NULL){
					printf("\nBilangan sebelum dihapus: ");
					printf("\nPreOrder: ");
					preorder(P);
					printf("\nInOrder: ");
					inorder(P);
					printf("\nPostOrder: ");
					postorder(P);
					printf("\nMasukkan data yang ingin dihapus: ");
					scanf("%d", &H);
					hapus(&P, H);
					printf("\nBilangan setelah dihapus: ");
					printf("\nPreOrder: ");
					preorder(P);
					printf("\nInOrder: ");
					inorder(P);
					printf("\nPostOrder: ");
					postorder(P);
				}
				else
				printf("\nKOSONG");
				_getch();
				break;
			//pilihan 7
			case'7':
				cout<<"\nBilangan terbesar: "<<findMax();
              	_getch();
              	break;
			//pilihan 8
			case'8':
				cout<<"\nBilangan terkecil: "<<findMin();
              	_getch();
              	break;
			//pilihan 9
			case'9':
				P=NULL;
				printf("RESET");
				printf("\nBST telah kosong");
				_getch();
				break;
		}
	}
}
