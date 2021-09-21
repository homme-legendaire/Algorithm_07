#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct DB {
	char str[21];
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
	int N, M, k = 0;
	char STR[21];
	DB* p = NULL, * ported = NULL, * sorted = NULL, * new = NULL;
	scanf("%d %d", &N, &M);
	p = (DB*)malloc(N * sizeof(DB));
	ported = (DB*)malloc(N * sizeof(DB));
	if (N < M) new = (DB*)malloc(N * sizeof(DB));
	else new = (DB*)malloc(M * sizeof(DB));
	for (int i = 0; i < N; i++) {
		scanf("%s", p[i].str);
	}
	mergeSort(p, ported, 0, N - 1);
	for (int i = 0; i < M; i++) {
		scanf("%s", STR);
		int m = 0, n = N - 1;
		while (m <= n) {
			int middle = (m + n) / 2;
			if (strcmp(p[middle].str, STR) == 0) {
				new[k] = p[middle];
				k++;
				break;
			}
			else if (strcmp(p[middle].str, STR) < 0) {
				m = middle + 1;
			}
			else {
				n = middle - 1;
			}
		}
	}
	sorted = (DB*)malloc(k * sizeof(DB));
	mergeSort(new, sorted, 0, k - 1);
	printf("%d\n", k);
	for (int i = 0; i < k; i++) {
		printf("%s\n", new[i].str);
	}
}