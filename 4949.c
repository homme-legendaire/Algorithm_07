#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NODE {
	struct NODE* next;
	char data;
}NODE;
void getNode(NODE** p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
	(*p)->next = NULL;
}
void push(NODE* p, char e) {
	NODE* q = NULL;
	getNode(&q);
	q->data = e;
	q->next = p->next;
	p->next = q;
}
void pop(NODE* p) {
	p->next = (p->next)->next;
}
char top(NODE* p) {
	p = p->next;
	return p->data;
}
int main() {
	char str[101];
	NODE* p = NULL;
	getNode(&p);
	while (1) {
		int cnt = 0, wrong = 0;
		gets(str);
		if (str[0] == '.') break;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == '(') {
				push(p, '(');
				cnt++;
			}
			else if (str[i] == '[') {
				push(p, '[');
				cnt++;
			}
			else if (str[i] == ')') {
				if (cnt == 0) {
					wrong = 1;
					break;
				}
				if (top(p) == '(') {
					cnt--;
					pop(p);
				}
				else if (top(p) != '(') {
					wrong = 1;
					break;
				}
			}
			else if (str[i] == ']') {
				if (cnt == 0) {
					wrong = 1;
					break;
				}
				if (top(p) == '[') {
					cnt--;
					pop(p);
				}
				else if (top(p) != '[') {
					wrong = 1;
					break;
				}
			}
		}
		if (cnt == 0 && wrong == 0) printf("yes\n");
		else printf("no\n");
	}
}