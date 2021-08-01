#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NODE {
	struct NODE* next;
	int data;
}NODE;
void getNode(NODE** p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
	(*p)->next = NULL;
}
void push(NODE* p, int e) {
	NODE* q = NULL;
	getNode(&q);
	q->data = e;
	q->next = p->next;
	p->next = q;
}
void pop(NODE* p) {
	p->next = (p->next)->next;
}
int S(NODE* p) {
	NODE* q = p->next;
	int sum = 0;
	while (q != NULL) {
		sum += q->data;
		q = q->next;
	}
	return sum;
}
int main() {
	int k, e;
	NODE* p = NULL;
	getNode(&p);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &e);
		if (e != 0) {
			push(p, e);
		}
		else {
			pop(p);
		}
	}
	printf("%d\n", S(p));
}