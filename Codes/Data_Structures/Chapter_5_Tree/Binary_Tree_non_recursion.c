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
void LevelOrderTraversal(BinTree BT); //��� 
BinTree CreatBinTree();

void PreOrderTraversal(BinTree BT){
	BinTree T = BT;
	Stack S = CreatStack(MAXSIZE);
	while(T || ! IsEmpty(S)){
		while(T){
			Push(S, T);  //��һ������ 
			printf("%5d", T->Data);
			T = T->Left;
		}

		if(!IsEmpty(S)){
			T = Pop(S);  //�ڶ������� 
//			printf("%5d", T->Data);
			T = T->Right;
		}
	}
}

void InOrderTraversal(BinTree BT){
	BinTree T = BT;
	Stack S = CreatStack(MAXSIZE);
	while(T || ! IsEmpty(S)){   //����������û׼������û��׼���þͳ��� 
		while(T){               //����ǰ����ľ��· 
			Push(S, T);         //��ѽ�� 
			T = T->Left;        //ת������
		}
		                        //emmmǰ��û·�ˣ�զ���� 
		if(!IsEmpty(S)){        //������û����· 
			T = Pop(S);         //���滹��·���������� 
			printf("%5d", T->Data);// do something For Example �ڵ�ͼ��������� ����һ��blabla 
			T = T->Right;       //ת������ 
		}
	}
}

//emmmm��������ǵݹ�ȷʵ���� ��û����֤�Ƿ���ȷ ��ž��ǵڶ�������֮���ջ���ó������� Ȼ��Ż�ȥȥ����������
//�����Ҫ֪��ʲôʱ���������������ˣ��������������ʱ��϶���������һ��Ҷ�ӽ�㣬֮���ж��Լ��ǲ���ջ��Ԫ���Һ���
//����ǵĻ��ͳ����׳�������׳���·����ʵ�����Ѿ���ȫ��������·��������˵�����ַ������ǰ�����������·��ʵ��һ��
//��Ϊ��������ͺ�������ڵڶ����������ڵ��ֱ���׳��ˣ���û��ʵ�ֵ����������Ĺ��� 

void PostOrderTraversal(BinTree BT){
	BinTree T = BT, t;
	Stack S = CreatStack(MAXSIZE);
	while(T || ! IsEmpty(S)){
		if(!T){
			while(1){
				t = Pop(T);
				if (!(T == t->Right)){
					Push(S, T);
					break;
				}
				else{
					T = t; //���������� 
					printf("%5d", T->Data);
				}
			}
		}
		while(T){
			Push(S, T); //��һ������ 
			T = T->Left;
		}
		if(!IsEmpty(S)){
			T = Pop(S); //�ڶ������� 
			Push(S, T);
//			printf("%5d", T->Data);
			T = T->Right;
		}
	}
} 
