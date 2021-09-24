#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
int dp[50001];
int HHY(int n) {
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int min = 5;
		for (int j = 1; j <= sqrt(i); j++) {
			if (min > dp[i - j * j] + 1) {
				min = dp[i - j * j] + 1;
			}
		}
		dp[i] = min;
	}
	return dp[n];
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", HHY(n));
	return 0;
}
