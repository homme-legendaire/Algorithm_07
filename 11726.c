#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int dp[1001];
int DP(int x) {
	if (x == 0) return 1;
	if (x == 1) return 2;
	if (dp[x] != 0) return dp[x];
	return dp[x] = (DP(x - 1) + DP(x - 2)) % 10007;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", DP(n - 1));
}