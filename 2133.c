#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int dp[100];
int DP(int x) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (dp[x] != 0) return dp[x];
	int tmp = 3 * DP(x - 2);
	for (int i = 3; i <= x; i++) {
		if (i % 2 == 0) {
			tmp += 2 * DP(x - i);
		}
	}
	return dp[x] = tmp;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", DP(n));
}