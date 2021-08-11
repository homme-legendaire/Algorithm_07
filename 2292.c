#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, cnt = 0, ans = 1;
	scanf("%d", &N);
	for (int i = 1; cnt * 6 + 1 < N; i++) {
		cnt += i;
		ans++;
	}
	printf("%d", ans);
}