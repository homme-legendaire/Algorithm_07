#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void bubble(int* a, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i] < a[j]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
void ranking(int* b, int* rank, int N) {
	for (int i = 0; i < N; i++) {
		rank[i] = 0;
		for (int j = 0; j < N; j++) {
			if (b[i] <= b[j]) {
				rank[i]++;
			}
		}
	}
}
void trim(int* rank, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (rank[i] == rank[j]) {
				rank[j]--;
			}
		}
	}
}
void nu(int* a, int* sorted, int* rank, int N) {
	for (int i = 0; i < N; i++) {
		sorted[i] = a[rank[i] - 1];
	}
}
int main() {
	int N, a[50], b[50], S = 0, rank[50], sorted[50];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	}
	bubble(a, N);
	ranking(b, rank, N);
	trim(rank, N);
	nu(a, sorted, rank, N);
	for (int i = 0; i < N; i++) {
		S += sorted[i] * b[i];
	}
	printf("%d", S);
}