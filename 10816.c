#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int* a, int* sorted, int m, int middle, int n) {
	int i = m, j = middle + 1, k = m;
	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
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
void mergeSort(int* a, int* sorted, int m, int n) {
	if (n > m) {
		int middle = (m + n) / 2;
		mergeSort(a, sorted, m, middle);
		mergeSort(a, sorted, middle + 1, n);
		merge(a, sorted, m, middle, n);
	}
}
int lower_bound(int* a, int b, int m, int n) {
	while (m < n) {
		int middle = (m + n) / 2;
		if (b <= a[middle]) n = middle;
		else m = middle + 1;
	}
	return n;
}
int upper_bound(int* a, int b, int m, int n) {
	int middle = 0;
	while (m < n) {
		middle = (m + n) / 2;
		if (b < a[middle]) n = middle;
		else m = middle + 1;
	}
	if (a[n] == b) n++;
	return n;
}
int main() {
	int N, M, * a, * sorted, b;
	scanf("%d", &N);
	a = (int*)malloc(N * sizeof(int));
	sorted = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	mergeSort(a, sorted, 0, N - 1);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &b);
		int A = lower_bound(a, b, 0, N - 1);
		int B = upper_bound(a, b, 0, N - 1);
		printf("%d ", B - A);
	}
}