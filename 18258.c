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
void push(NODE** front, NODE** rear, int e) {
	NODE* p = NULL;
	getNode(&p);
	p->data = e;
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
int frog(NODE** front) {
	return (*front)->data;
}
int back(NODE** rear) {
	return (*rear)->data;
}
int main() {
	int N, i, e, cnt = 0;
	char str[10];
	NODE* front = NULL, * rear = NULL;
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%s", str);
		getchar();
		if (strcmp(str, "push") == 0) {
			scanf("%d", &e);
			push(&front, &rear, e);
			cnt++;
		}
		else if (strcmp(str, "pop") == 0) {
			if (cnt == 0) printf("-1\n");
			else {
				printf("%d\n", pop(&front, &rear));
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
		else if (strcmp(str, "front") == 0) {
			if (cnt == 0) printf("-1\n");
			else printf("%d\n", frog(&front));
		}
		else if (strcmp(str, "back") == 0) {
			if (cnt == 0) printf("-1\n");
			else printf("%d\n", back(&rear));
		}
	}
}