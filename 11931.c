#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int x[1000000], sorted[1000000];
void merge(int* x, int* sorted, int m, int middle, int n) {
	int i = m, j = middle + 1, k = m;
	while (i <= middle && j <= n) {
		if (x[i] < x[j]) {
			sorted[k] = x[j];
			j++;
		}
		else {
			sorted[k] = x[i];
			i++;
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = x[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = x[t];
			k++;
		}
	}
	for (int t = m; t <= n; t++) {
		x[t] = sorted[t];
	}
}
void mergeSort(int* x, int* sorted, int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(x, sorted, m, middle);
		mergeSort(x, sorted, middle + 1, n);
		merge(x, sorted, m, middle, n);
	}
}
int main() {
	int N, i, tmp = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &x[i]);
	}
	mergeSort(x, sorted, 0, N - 1);
	for (i = 0; i < N; i++) {
		printf("%d\n", x[i]);
	}
}