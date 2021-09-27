#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int dp[41];
int DP(int x) {
	if (x == 0) return 1;
	if (x == 1) return 1;
	if (dp[x] != 0) return dp[x];
	return dp[x] = DP(x - 1) + DP(x - 2);
}
int main() {
	int n, a[41];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			printf("1 0\n");
		}
		else if (a[i] == 1) {
			printf("0 %d\n", DP(0));
		}
		else {
			printf("%d %d\n", DP(a[i] - 2), DP(a[i] - 1));
		}
	}
}