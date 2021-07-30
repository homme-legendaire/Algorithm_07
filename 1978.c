#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void source(int N, int* count) {
	int i, cnt = 0;
	for (i = 1; i <= N; i++) {
		if (N % i == 0) cnt++;
	}
	if (cnt == 2) (*count)++;
}
int main() {
	int N, i, x[100], cnt = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &x[i]);
	for (i = 0; i < N; i++) source(x[i], &cnt);
	printf("%d", cnt);
}