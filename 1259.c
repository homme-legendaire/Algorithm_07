#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Finland(int N) {
	int x[5], cnt = 0, i, j = 0, C = 0;
	while (N != 0) {
		x[cnt] = N % 10;
		N /= 10;
		cnt++;
	}
	j = cnt - 1;
	for (i = 0; i < cnt; i++) {
		if (x[i] == x[j]) C++;
		j--;
	}
	if (C == cnt) printf("yes\n");
	else printf("no\n");
}
int main() {
	int N;
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;
		else {
			Finland(N);
		}
	}
}