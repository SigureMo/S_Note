#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ElementType int

typedef struct _node{
	ElementType Data;
	struct _node* Left;
	struct _node* Right;
}TreeNode , Position,*BinTree; 

bool IsEmpty(BinTree BT);
//void Traversal(BinTree BT);
void PreOrderTraversal(BinTree BT);   //���� 
void InOrderTraversal(BinTree BT);    //���� 
void PostOrderTraversal(BinTree BT);  //���� 
void LevelOrderTraversal(BinTree BT); //���� 
BinTree CreatBinTree();

//·����ʵһ���� ֻ�������ʣ�print��ʱ����һ�� 

void PreOrderTraversal(BinTree BT){
	if (BT){
		printf("%d", BT->Data);  //ֻ����һ�в�һ�� 
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Left);
	}
}

void InOrderTraversal(BinTree BT){
	if (BT){
		InOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		InOrderTraversal(BT->Left);
	}
}

void PostOrderTraversal(BinTree BT){
	if (BT){
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Left);
		printf("%d", BT->Data);
	}
} 

void LevelOrderTraversal(BinTree BT){
	Queue Q;
	BinTree T;
	if (!BT) return;
	Q = CreatQueue(MAXSIZE);
	AddQ(Q, BT);
	while (!IsEmptyQ(Q)){
		T = DeleteQ(Q);
		printf("%d\n", T->Data);
		if(T->Left) AddQ(Q, T->Left);
		if(T->Right) AddQ(Q, T->Right);
	}
} 
