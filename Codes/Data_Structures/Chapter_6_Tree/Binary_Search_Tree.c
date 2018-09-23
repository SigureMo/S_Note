#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ElementType int

typedef struct _node{
	ElementType Data;
	struct _node* Left;
	struct _node* Right;
}TreeNode , Position,*BinTree; 

Position Find(ElementType X, BinTree BST);
Position FindMin(ElementType X, BinTree BST); 
Position FindMax(ElementType X, BinTree BST);
BinTree Insert(ElementType X, BinTree BST);
BinTree Delete(ElementType X, BinTree BST);

Position Find(ElementType X, BinTree BST){
	/*
	// �ݹ� 
	if(!BST) return NULL;
	if(X > BST->Data) return Find(X, BST->Right);
	else if(X < BST->Data) return Find(X, BST->Left);
	else return BST; 
	*/
	// �ǵݹ�
	while (BST){
		if (X>BST->Data) BST = BST->Right;
		else if (X < BST->Right) BST->Left;
		else return BST;
	} 
	return NULL;
}

Position FindMin(ElementType X, BinTree BST){
	/*
	// �ݹ� 
	if(!BST) return NULL;
	else if (!BST->Left) return BST;
	else return FindMin(BST->Left);
	*/
	// �ǵݹ�
	if(BST)
	    while(BST->Left) BST = BST->Left;
	return BST;
}
Position FindMax(ElementType X, BinTree BST){
	/*
	// �ݹ� 
	if(!BST) return NULL;
	else if (!BST->Right) return BST;
	else return FindMin(BST->Right);
	*/
	// �ǵݹ�
	if(BST)
	    while(BST->Right) BST = BST->Right;
	return BST;
}
BinTree Insert(ElementType X, BinTree BST){
	if(!BST){
		BST = malloc(sizeof(TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}else{
		if(X < BST->Data) BST->Left = Insert(X, BST->Left);
		else if(X > BST->Data) BST->Right = Insert(X, BST->Right);
	}
	return BST;
}

BinTree Delete(ElementType X, BinTree BST){
	// �����Ҷ�ڵ㣬ֱ��ɾ��
	// ���ֻ��һ�����ӽ�㣬ֻ��Ҫ������ӷŵ��丸�����
	// ����������Ӷ��У�����ת��Ϊ�������������ֵ��������������Сֵ ����ɾ������λ���� 
	Position Tmp;
	if (!BST) printf("Ҫɾ����Ԫ��δ�ҵ�");
	else if(X>BST->Data) BST->Left = Delete(X, BST->Left);
	else if(X<BST->Data) BST->Right = Delete(X, BST->Right);
	else 
	    if(BST->Left && BST->Right){
	        Tmp = FindMin(BST->Right);
	        BST->Data = Tmp->Data;
	        BST->Right = Delete(BST->Data, BST->Right);
		 }
		 else{
		 	Tmp = BST;
		 	if(!BST->Left) BST = BST->Right;
		 	else if(!BST->Right) BST = BST->Left;
		 	free(Tmp);
		 }
	return BST;
}
