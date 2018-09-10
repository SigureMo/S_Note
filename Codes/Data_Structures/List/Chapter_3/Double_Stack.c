#include<stdio.h>
#include<stdlib.h>

#define ElementType int
#define MAXSIZE 100

struct DStack{
    ElementType Data[MAXSIZE];
    int Top1; /* ��ջ1��ջ��ָ�� */
    int Top2; /* ��ջ2��ջ��ָ�� */
} S;
//S.Top1 = -1;      /* ��ջ1��*/
//S.Top2 = MAXSIZE; /* ��ջ2�� */

typedef struct{
	ElementType Data[MAXSIZE];
	int Top; 
} SNode, *Stack;

void Push(struct DStack *PtrS, ElementType item, int Tag); 
ElementType Pop(struct DStack *PtrS, int Tag);

int main(){
	printf("1\n");
	Node* PtrL = MakeEmpty();
	Insert(3, 1, PtrL);
	Insert(37, 1, PtrL);
	printf("%d", Find(3, PtrL));
	return 0;
}

void Push(struct DStack *PtrS, ElementType item, int Tag){
	if (PtrS->Top1 - PtrS->Top2 == 1){
		printf("��ջ��");
		return ;
	}
	if (Tag == 1){
		PtrS->Data[++(PtrS->Top1)] = item;
	}
	else{
		PtrS->Data[--(PtrS->Top2)] = item;
	}
} 

ElementType Pop(struct DStack *PtrS, int Tag){
	if (Tag == 1){
		if (PtrS->Top1 == -1){
			printf("��ջ1��");
			return NULL;
		}
		else{
			return PtrS->Data[(PtrS->Top1)--];
		}
	else{
		if (PtrS->Top2 == MAXSIZE){
			printf("��ջ2��");
			return NULL;
		}
		else{
			return PtrS->Data[(PtrS->Top2)++];
		}
	}
	}
}
