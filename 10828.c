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
int pop(NODE* p) {
	NODE* q = NULL;
	getNode(&q);
	q = p;
	p = p->next;
	int e = p->data;
	(q->next) = (q->next)->next;
	return e;
}
int top(NODE* p) {
	p = p->next;
	return p->data;
}
int main() {
	int N, i, e, cnt = 0;
	char str[10];
	NODE* p = NULL;
	getNode(&p);
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%s", str);
		getchar();
		if (strcmp(str, "push") == 0) {
			scanf("%d", &e);
			push(p, e);
			cnt++;
		}
		else if (strcmp(str, "pop") == 0) {
			if (cnt == 0) printf("-1\n");
			else {
				printf("%d\n", pop(p));
				cnt--;
			}
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", cnt);
		}
		else if (strcmp(str, "empty") == 0) {
			if (cnt == 0) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(str, "top") == 0) {
			if (cnt == 0) printf("-1\n");
			else printf("%d\n", top(p));
		}
	}
}