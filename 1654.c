#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long LAN(long long* L, long long K, long long N, long long start, long long end) {
	while (start <= end) {
		long long middle = (start + end) / 2, cnt = 0;
		if (middle == 0) middle++;
		for (int i = 0; i < K; i++) {
			if (L[i] >= middle) {
				cnt += L[i] / middle;
			}
		}
		if (cnt < N) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}
	}
	return end;
}
int main() {
	long long K, N, * L = NULL, max = 0;
	scanf("%lld %lld", &K, &N);
	L = (long long*)malloc(K * sizeof(long long));
	for (int i = 0; i < K; i++) {
		scanf("%lld", &L[i]);
		if (max < L[i]) {
			max = L[i];
		}
	}
	printf("%lld", LAN(L, K, N, 0, max));
}