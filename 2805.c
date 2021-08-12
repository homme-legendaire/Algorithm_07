#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long H[1000000];
long long WOOD(long long* H, long long N, long long M, long long start, long long end) {
	while (start <= end) {
		long long sum = 0, middle = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			if (H[i] > middle) {
				sum += H[i] - middle;
			}
		}
		if (sum < M) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}
	}
	return end;
}
int main() {
	long long N, M, max = 0;
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%lld", &H[i]);
		if (max < H[i]) {
			max = H[i];
		}
	}
	printf("%lld", WOOD(H, N, M, 0, max));
}