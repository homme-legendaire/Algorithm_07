#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main() {
	int T, H, W, N, i = 1, j = 1, l;
	scanf("%d", &T);
	for (l = 0; l < T; l++) {
		j = 1;
		scanf("%d %d %d", &H, &W, &N);
		while (N > 0) {
			if (N > H) {
				j++;
				N -= H;
			}
			else {
				i = N;
				break;
			}
		}
		printf("%d%02d\n", i, j);
	}
}