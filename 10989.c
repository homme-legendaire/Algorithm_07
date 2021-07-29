#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, i, a, count[10001] = { 0 };
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &a);
		count[a]++;
	}
	for (i = 0; i < 10000; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
}