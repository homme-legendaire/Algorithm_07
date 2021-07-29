#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int gcd(int N, int M) {
	if (M == 0) return N;
	else return gcd(M, N % M);
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	printf("%d\n", gcd(N, M));
	printf("%d", N * M / gcd(N, M));
}