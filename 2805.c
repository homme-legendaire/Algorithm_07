#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void heap(int* heap, int num) {
	for (int i = 1; i < num; i++) {
		int c = i;
		while (c != 0) {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			c = root;
		}
	}
	for (int i = num - 1; i >= 0; i--) {
		int tmp = heap[0];
		heap[0] = heap[i];
		heap[i] = tmp;
		int root = 0;
		int c = 1;
		while (c < i) {
			c = 2 * root + 1;
			if (heap[c] < heap[c + 1] && c < i - 1) {
				c++;
			}
			if (heap[root] < heap[c] && c < i) {
				int tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			root = c;
		}
	}
}
int Wood(int* H, int N, int M, int start, int end) {
	while (start <= end) {
		int sum = 0, middle = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			if (H[i] > middle) {
				sum += H[i] - middle;
			}
		}
		if (sum < M) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}
	}
	return end;
}
int main() {
	int N, M, * H = NULL;
	scanf("%d %d", &N, &M);
	H = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &H[i]);
	}
	heap(H, N);
	printf("%d", Wood(H, N, M, H[0], H[N - 1]));
}