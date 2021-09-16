#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void add(int* S, int x) {
	if (S[x - 1] == x) return;
	else S[x - 1] = x;
}
void rem(int* S, int x) {
	if (S[x - 1] == x) S[x - 1] = 0;
}
void check(int* S, int x) {
	if (S[x - 1] == x) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}
void toggle(int* S, int x) {
	if (S[x - 1] == x) {
		S[x - 1] = 0;
	}
	else {
		S[x - 1] = x;
	}
}
void all(int* S) {
	for (int i = 0; i < 20; i++) {
		S[i] = i + 1;
	}
}
void empty(int* S) {
	for (int i = 0; i < 20; i++) {
		S[i] = 0;
	}
}
int main() {
	int S[21], x, M;
	char str[10];
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%s", str);
		if (strcmp(str, "add") == 0) {
			scanf("%d", &x);
			add(S, x);
		}
		else if (strcmp(str, "remove") == 0) {
			scanf("%d", &x);
			rem(S, x);
		}
		else if (strcmp(str, "check") == 0) {
			scanf("%d", &x);
			check(S, x);
		}
		else if (strcmp(str, "toggle") == 0) {
			scanf("%d", &x);
			toggle(S, x);
		}
		else if (strcmp(str, "all") == 0) {
			all(S);
		}
		else if (strcmp(str, "empty") == 0) {
			empty(S);
		}
	}
}