#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, x[10], cnt = 0;
	scanf("%d", &N);
	while (N != 0) {
		x[cnt] = N % 10;
		N /= 10;
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		int tmp = 0;
		for (int j = 0; j < cnt; j++) {
			if (x[i] > x[j]) {
				tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
			}
		}
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d", x[i]);
	}
}