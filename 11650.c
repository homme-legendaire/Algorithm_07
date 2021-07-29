#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE {
	int x, y;
}DOT;
void merge(DOT* a, DOT* sorted, int m, int middle, int n) {
	int i = m, j = middle + 1, k = m;
	while (i <= middle && j <= n) {
		if (a[i].x < a[j].x) {
			sorted[k] = a[i];
			i++;
		}
		else if (a[i].x == a[j].x) {
			if (a[i].y < a[j].y) {
				sorted[k] = a[i];
				i++;
			}
			else {
				sorted[k] = a[j];
				j++;
			}
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
void mergeSort(DOT* a, DOT* sorted, int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, sorted, m, middle);
		mergeSort(a, sorted, middle + 1, n);
		merge(a, sorted, m, middle, n);
	}
}
int main() {
	int N;
	DOT* a = NULL, * sorted = NULL;
	scanf("%d", &N);
	a = (DOT*)malloc(N * sizeof(DOT));
	sorted = (DOT*)malloc(N * sizeof(DOT));
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	mergeSort(a, sorted, 0, N - 1);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", a[i].x, a[i].y);
	}
}