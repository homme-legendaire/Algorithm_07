#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, M = 0, P = 0, i, j = 0, k = 0;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		M = 0;
		P = i;
		j = i;
		while (P != 0) {
			M += P;
			P = j % 10;
			j /= 10;
		}
		if (M == N) {
			k = i;
			break;
		}
	}
	if (k != 0) printf("%d", k);
	else printf("0");
	return 0;
}