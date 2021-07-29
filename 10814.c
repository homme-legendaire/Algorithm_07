#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct MEMBERS{
	char name[101];
	int age, rank;
}MEMBER;
void merge(MEMBER* a, MEMBER* sorted, int m, int middle, int n) {
	int i = m, j = middle + 1, k = m;
	while (i <= middle && j <= n) {
		if (a[i].age < a[j].age) {
			sorted[k] = a[i];
			i++;
		}
		else if (a[i].age == a[j].age) {
			if (a[i].rank < a[j].rank) {
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
void mergeSort(MEMBER* a, MEMBER* sorted, int m, int n) {
	if (n > m) {
		int middle = (m + n) / 2;
		mergeSort(a, sorted, m, middle);
		mergeSort(a, sorted, middle + 1, n);
		merge(a, sorted, m, middle, n);
	}
}
int main() {
	int N, i;
	MEMBER* p = NULL, * sorted = NULL;
	scanf("%d", &N);
	p = (MEMBER*)malloc(N * sizeof(MEMBER));
	sorted = (MEMBER*)malloc(N * sizeof(MEMBER));
	for (i = 0; i < N; i++) {
		scanf("%d %s", &p[i].age, p[i].name);
		p[i].rank = i;
	}
	mergeSort(p, sorted, 0, N - 1);
	for (i = 0; i < N; i++) {
		printf("%d %s\n", p[i].age, p[i].name);
	}
}