#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void merge(char** str, char** sorted, int m, int middle, int n) {
	int i = m, j = middle + 1, k = m;
	while (i <= middle && j <= n) {
		if (strlen(str[i]) < strlen(str[j])) {
			strcpy(sorted[k], str[i]);
			i++;
		}
		else if (strlen(str[i]) > strlen(str[j])) {
			strcpy(sorted[k], str[j]);
			j++;
		}
		else {
			if (strcmp(str[i], str[j]) < 0) {
				strcpy(sorted[k], str[i]);
				i++;
			}
			else {
				strcpy(sorted[k], str[j]);
				j++;
			}
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			strcpy(sorted[k], str[t]);
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			strcpy(sorted[k], str[t]);
			k++;
		}
	}
	for (int t = m; t <= n; t++) {
		strcpy(str[t], sorted[t]);
	}
}
void mergeSort(char** str, char** sorted, int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(str, sorted, m, middle);
		mergeSort(str, sorted, middle + 1, n);
		merge(str, sorted, m, middle, n);
	}
}
int main() {
	int N, i;
	char** str = NULL, ** sorted = NULL;
	scanf("%d", &N);
	getchar();
	str = (char**)malloc(N * sizeof(char*));
	sorted = (char**)malloc(N * sizeof(char*));
	for (i = 0; i < N; i++) {
		*(str + i) = (char*)malloc(51 * sizeof(char));
		*(sorted + i) = (char*)malloc(51 * sizeof(char));
	}
	for (i = 0; i < N; i++) scanf("%s", str[i]);
	mergeSort(str, sorted, 0, N - 1);
	for (i = 0; i < N; i++) {
		if (i == 0) printf("%s\n", str[i]);
		else if (strcmp(str[i], str[i - 1]) != 0) printf("%s\n", str[i]);
	}
}