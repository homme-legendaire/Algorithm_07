#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double average(int* a, int N) {
	int sum = 0;
	double F = N;
	for (int i = 0; i < N; i++) sum += a[i];
	return (double)(sum / F);
}
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
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, sorted, m, middle);
		mergeSort(a, sorted, middle + 1, n);
		merge(a, sorted, m, middle, n);
	}
}
int popular(int* count) {
	int M = 0, cnt = 0, p = 0;
	for (int i = 0; i <= 8000; i++) {
		if (count[i] >= M) M = count[i];
	}
	for (int i = 0; i <= 8000; i++) {
		if (count[i] == M) {
			cnt++;
			p = i;
		}
		if (cnt == 2) {
			return i - 4000;
			break;
		}
	}
	if (cnt == 1) return p - 4000;
}
int main() {
	int N, * p = NULL, * sorted = NULL, count[8001] = { 0 };
	scanf("%d", &N);
	p = (int*)malloc(N * sizeof(int));
	sorted = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]); 
		count[p[i] + 4000]++;
	}
	mergeSort(p, sorted, 0, N - 1);
	printf("%.0lf\n", average(p, N));
	printf("%d\n", p[N / 2]);
	printf("%d\n", popular(count));
	printf("%d", p[N - 1] - p[0]);
}