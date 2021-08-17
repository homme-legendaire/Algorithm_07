#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int t, N, M, x[100];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int cnt = 1, front = 0, max = 0;
		scanf("%d %d", &N, &M);
		for (int j = 0; j < N; j++) {
			scanf("%d", &x[j]);
		}
		while (1) {
			for (int k = 0; k < N; k++) {
				if (max < x[k]) {
					max = x[k];
				}
			}
			while (x[front] != max) {
				front = (front + 1) % N;
			}
			if (front == M) {
				break;
			}
			x[front] = 0;
			max = 0;
			cnt++;
		}
		printf("%d\n", cnt);
	}
}