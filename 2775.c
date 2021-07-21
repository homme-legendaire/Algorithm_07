#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, a, b, i, j, k;
	scanf("%d", &N);
	for (k = 0; k < N; k++) {
		int sum[14] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
		scanf("%d", &a);
		scanf("%d", &b);
		for (i = 0; i < a; i++) {
			for (j = 1; j < b; j++) {
				sum[j] += sum[j - 1];
			}
		}
		printf("%d\n", sum[b - 1]);
	}
	return 0;
}