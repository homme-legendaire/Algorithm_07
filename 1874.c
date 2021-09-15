#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, * a = NULL, * x = NULL;
	char* result = NULL;
	scanf("%d", &N);
	a = (int*)malloc(N * sizeof(int));
	x = (int*)malloc(N * sizeof(int));
	result = (char*)malloc(2 * N * sizeof(char));
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int cnt = -1, num = 1, i = 0, j = 0;
	while (1) {
		if (cnt == -1 || x[cnt] < a[i]) {
			cnt++;
			x[cnt] = num;
			result[j] = '+';
			num++;
			j++;
			}
		else if (x[cnt] == a[i]) {
			cnt--;
			result[j] = '-';
			j++;
			i++;
		}
		else {
			printf("NO\n");
			return 0;
		}
		if (j == N * 2) break;
	}
	for (int i = 0; i < j; i++) {
		printf("%c\n", result[i]);
	}
}