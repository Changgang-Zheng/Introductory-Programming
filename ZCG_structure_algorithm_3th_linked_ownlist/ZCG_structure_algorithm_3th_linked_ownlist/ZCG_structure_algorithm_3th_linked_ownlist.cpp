#include "stdio.h"
#include <stdlib.h>
#include "string.h"

typedef int ElemType;

struct Node {
	ElemType data;
	struct Node *next;
};

typedef struct Node LNode;
typedef struct Node *LinkedList;

//��ʼ������*�Ľڵ�
void LinkedListInitial(LinkedList L){
	L = NULL;
}

void LinkedListInit2(LinkedList L){
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		printf("����ռ�ʧ�ܣ�");
		exit(0);
	}
	L-> next = NULL;
}
int LLinkedListLength(LinkedList L) {
	LNode *p;
	p = L-> next;
	int j = 0;
	while (p != NULL) {
		j++;
		p = p->next;
	}
	return j;
}

LinkedList inkedListGet() {
}