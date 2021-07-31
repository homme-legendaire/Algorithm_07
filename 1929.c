#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[1000001];
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 2; i <= n; i++) {
		a[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j <= n; j += i) {
			a[j] = 0;
		}
	}
	for (int i = m; i <= n; i++) {
		if (a[i] != 0) {
			printf("%d\n", a[i]);
		}
	}
}