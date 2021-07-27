#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, M, i, j, cnt1 = 0, cnt2 = 0, cnt = 1, min = 64, I = 0, J = 0;
	char str[50][50], A[8][8], B[8][8];
	scanf("%d %d", &N, &M);
	getchar();
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%c", &str[i][j]);
		}
		getchar();
	}
	for (i = 0; i < 8; i += 2) {
		for (j = 0; j < 8; j++) {
			if (cnt % 2 != 0) {
				A[i][j] = 'W';
				B[i][j] = 'B';
			}
			else {
				A[i][j] = 'B';
				B[i][j] = 'W';
			}cnt++;
		}
	}
	for (i = 1; i < 8; i += 2) {
		for (j = 0; j < 8; j++) {
			if (cnt % 2 != 0) {
				A[i][j] = 'B';
				B[i][j] = 'W';
			}
			else {
				A[i][j] = 'W';
				B[i][j] = 'B';
			}cnt++;
		}
	}
	while (I <= N - 8) {
		cnt1 = 0;
		cnt2 = 0;
		for (i = I; i < I + 8; i++) {
			for (j = J; j < J + 8; j++) {
				if (str[i][j] != A[i - I][j - J]) cnt1++;
				if (str[i][j] != B[i - I][j - J]) cnt2++;
			}
		}
		if (cnt1 < cnt2) cnt = cnt1;
		else cnt = cnt2;
		if (min > cnt) min = cnt;
		J++;
		if (J > M - 8) {
			J = 0;
			I++;
		}
	}
	printf("%d", min);
}