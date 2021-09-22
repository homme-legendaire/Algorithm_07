#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct DB {
	char str[21], ps[21];
}DB;
void merge(DB* a, DB* sorted, int m, int middle, int n) {
	int i = m, j = middle + 1, k = m;
	while (i <= middle && j <= n) {
		if (strcmp(a[i].str, a[j].str) < 0) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}
void mergeSort(DB* a, DB* sorted, int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, sorted, m, middle);
		mergeSort(a, sorted, middle + 1, n);
		merge(a, sorted, m, middle, n);
	}
}
int main() {
	int N, M;
	char STR[21];
	DB* a = NULL, * sorted = NULL;
	scanf("%d %d", &N, &M);
	a = (DB*)malloc(N * sizeof(DB));
	sorted = (DB*)malloc(N * sizeof(DB));
	for (int i = 0; i < N; i++) {
		scanf("%s %s", a[i].str, a[i].ps);
	}
	mergeSort(a, sorted, 0, N - 1);
	for (int i = 0; i < M; i++) {
		scanf("%s", STR);
		int m = 0, n = N - 1;
		while (m <= n) {
			int middle = (m + n) / 2;
			if (strcmp(a[middle].str, STR) == 0) {
				printf("%s\n", a[middle].ps);
				break;
			}
			else if (strcmp(a[middle].str, STR) < 0) {
				m = middle + 1;
			}
			else {
				n = middle - 1;
			}
		}
	}
}