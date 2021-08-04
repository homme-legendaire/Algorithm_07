#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NODE {
	struct NODE* prev, * next;
	int data;
}NODE;
void getNODE(NODE** p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
}
void push_front(NODE** front, NODE** rear, int e) {
	NODE* p = NULL;
	getNODE(&p);
	p->prev = NULL;
	p->data = e;
	p->next = *front;
	if (*front == NULL) {
		*rear = p;
	}
	else {
		(*front)->prev = p;
	}
	*front = p;
}
void push_back(NODE** front, NODE** rear, int e) {
	NODE* p = NULL;
	getNODE(&p);
	p->prev = *rear;
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
int pop_front(NODE** front, NODE** rear) {
	int e = (*front)->data;
	*front = (*front)->next;
	if (*front == NULL) *rear = *front;
	else (*front)->prev = NULL;
	return e;
}
int pop_back(NODE** front, NODE** rear) {
	int e = (*rear)->data;
	*rear = (*rear)->prev;
	if (*rear == NULL) *front = *rear;
	else (*rear)->next = NULL;
	return e;
}
int top(NODE** front) {
	return (*front)->data;
}
int bot(NODE** rear) {
	return (*rear)->data;
}
int main() {
	int N, i, e, cnt = 0;
	char str[20];
	NODE* front = NULL, * rear = NULL;
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%s", str);
		if (strcmp(str, "push_front") == 0) {
			scanf("%d", &e);
			push_front(&front, &rear, e);
			cnt++;
		}
		else if (strcmp(str, "push_back") == 0) {
			scanf("%d", &e);
			push_back(&front, &rear, e);
			cnt++;
		}
		else if (strcmp(str, "pop_front") == 0) {
			if (cnt == 0) printf("-1\n");
			else {
				printf("%d\n", pop_front(&front, &rear));
				cnt--;
			}
		}
		else if (strcmp(str, "pop_back") == 0) {
			if (cnt == 0) printf("-1\n");
			else {
				printf("%d\n", pop_back(&front, &rear));
				cnt--;
			}
		}
		else if (strcmp(str, "size") == 0)	printf("%d\n", cnt);
		else if (strcmp(str, "empty") == 0) {
			if (cnt == 0) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(str, "front") == 0) {
			if (cnt == 0) printf("-1\n");
			else printf("%d\n", top(&front));

		}
		else if (strcmp(str, "back") == 0) {
			if (cnt == 0) printf("-1\n");
			else printf("%d\n", bot(&rear));
		}
	}
}