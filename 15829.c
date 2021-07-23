#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, i, max = 0, MOD = 1234567891;
	char ch;
	long long r = 1, sum = 0;
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%c", &ch);
		sum += ((ch - 96) * r) % MOD;
		r *= 31;
		r %= MOD;
	}
	printf("%lld", sum % MOD);
}