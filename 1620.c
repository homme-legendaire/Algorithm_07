#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct MEMBERS {
	char name[21];
	int rank;
}MEMBER;
void merge(MEMBER* a, MEMBER* sorted, int m, int middle, int n) {
	int i = m, j = middle + 1, k = m;
	while (i <= middle && j <= n) {
		if (strcmp(a[i].name, a[j].name) < 0) {
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
void mergeSort(MEMBER* a, MEMBER* sorted, int m, int n) {
	if (n > m) {
		int middle = (m + n) / 2;
		mergeSort(a, sorted, m, middle);
		mergeSort(a, sorted, middle + 1, n);
		merge(a, sorted, m, middle, n);
	}
}
int main() {
	int N, M, i;
	char str[21];
	MEMBER* p = NULL, * sorted = NULL, * copy = NULL;
	scanf("%d %d", &N, &M);
	getchar();
	p = (MEMBER*)malloc(N * sizeof(MEMBER));
	sorted = (MEMBER*)malloc(N * sizeof(MEMBER));
	copy = (MEMBER*)malloc(N * sizeof(MEMBER));
	for (i = 0; i < N; i++) {
		scanf("%s", p[i].name);
		p[i].rank = i + 1;
	}
	for (int t = 0; t < N; t++) {
		copy[t] = p[t];
	}
	mergeSort(p, sorted, 0, N - 1);
	for (int i = 0; i <= M; i++) {
		scanf("%s", str);
		if ('A' <= str[0] && str[0] <= 'Z') {
			int m = 0, n = N - 1;
			while (m <= n) {
				int middle = (m + n) / 2;
				if (strcmp(p[middle].name, str) == 0) {
					printf("%d\n", p[middle].rank);
					break;
				}
				else if (strcmp(p[middle].name, str) > 0) {
					n = middle - 1;
				}
				else {
					m = middle + 1;
				}
			}
		}
		else {
			int tmp = atoi(str);
			printf("%s\n", copy[tmp - 1].name);
		}
	}
}