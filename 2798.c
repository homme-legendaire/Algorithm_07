#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, M, * x = NULL, i, j, k, sum = 0, king = 0;
	scanf("%d %d", &N, &M);
	x = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) scanf("%d", (x + i));
	for (i = 0; i < N; i++) {
		sum = 0;
		for (j = i + 1; j < N; j++) {
			for (k = j + 1; k < N; k++) {
				sum = x[i] + x[j] + x[k];
				if (M >= sum) {
					if (sum > king) {
						king = sum;
					}
				}
			}
		}
	}
	printf("%d", king);
	return 0;
}