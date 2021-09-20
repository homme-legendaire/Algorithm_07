#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, cnt = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int tmp = i;
		while (tmp % 5 == 0 && tmp != 0) {
			cnt++;
			tmp /= 5;
		}
	}
	printf("%d", cnt);
}