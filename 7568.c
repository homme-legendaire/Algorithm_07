#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, x[50], y[50], i, j, k[50];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	for (i = 0; i < N; i++) {
		k[i] = 1;
		for (j = 0; j < N; j++) {
			if (x[i] < x[j] && y[i] < y[j]) k[i]++;
		}
	}
	for (i = 0; i < N; i++) {
		printf("%d ", k[i]);
	}
}