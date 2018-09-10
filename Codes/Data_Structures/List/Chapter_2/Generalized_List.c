#include<stdio.h>
#include<stdlib.h>

#define ElementType int
#define MAXSIZE 100

typedef struct _node{
	int Tag;           //���Ա�Ǹý����������һ��������ǵ�Ԫ�أ�0->��Ԫ��,1->����� 
	union{             //�ӱ�ָ����SubLIst�뵥Ԫ��������Data���ã������ô洢�ռ� 
		ElementType Data;
		struct _node *SubList;
	};
	struct _node *Next; 
} Node, *List;

int Length(List PtrL); 
List FindKth(int K, List PtrL);
List Find(ElementType X, List PtrL);
List Insert(ElementType X, int i, List PtrL);
List Delete(int i, List PtrL);

int main(){
	printf("1\n");
	List PtrL;
	return 0;
}

