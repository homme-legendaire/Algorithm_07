#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int fact(int C) {
	if (C == 0) return 1;
	else if (C == 1) return C;
	else return C * fact(C - 1);
}
int main() {
	int N, K, C = 0;
	scanf("%d %d", &N, &K);
	C = fact(N) / (fact(K) * fact(N - K));
	printf("%d", C);
}