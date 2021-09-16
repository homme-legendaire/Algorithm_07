#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, M, B, x[500][500], time = 0;
	scanf("%d %d %d", &N, &M, &B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &x[i][j]);
		}
	}
	int min = INT_MAX, height = 256;
	for (int a = 256; a >= 0; a--) {
		time = 0;
		int tmp = B;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int gap = x[i][j] - a;
				if (gap > 0) {
					time += (gap * 2);
					tmp += gap;
				}
				else if (gap < 0) {
					time -= gap;
					tmp += gap;
				}
			}
		}
		if (tmp >= 0) {
			if (time < min) {
				min = time;
				height = a;
			}
		}
	}
	printf("%d %d", min, height);
}