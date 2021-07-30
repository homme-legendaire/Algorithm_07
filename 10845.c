#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE {
	struct NODE* next;
	int data;
}NODE;
void getNode(NODE** p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
}
void push(NODE** front, NODE** rear, int i) {
	NODE* p = NULL;
	getNode(&p);
	p->data = i;
	p->next = NULL;
	if (*rear == NULL) {
		*front = p;
	}
	else {
		(*rear)->next = p;
	}
	*rear = p;
}
int pop(NODE** front, NODE** rear) {
	int e = (*front)->data;
	*front = (*front)->next;
	if (*front == NULL) *rear = *front;
	return e;
}
int main() {
	int N, i, e;
	scanf("%d", &N);
	NODE* front = NULL, * rear = NULL;
	for (i = 1; i <= N; i++) {
		push(&front, &rear, i);
	}
	while (N != 1) {
		pop(&front, &rear);
		N--;
		e = pop(&front, &rear);
		push(&front, &rear, e);
	}
	printf("%d", pop(&front, &rear));
}