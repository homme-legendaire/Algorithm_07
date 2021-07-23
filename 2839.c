#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int N, cnt = 0, i = 0;
	scanf("%d", &N);
	while (N != 0) {
		if (i > 2000) break;
		else {
			if (N % 5 == 0) {
				cnt = N / 5;
				N %= 5;
			}
			else if (N % 5 == 1) {
				N -= 3;
				cnt++;
			}
			else if (N % 5 == 2) {
				N -= 3;
				cnt++;
			}
			else if (N % 5 == 3) {
				if (N > 5) N -= 5;
				else N -= 3;
				cnt++;
			}
			else {
				N -= 3;
				cnt++;
			}
			i++;
		}
	}
	if (i > 2000) printf("-1");
	else printf("%d", cnt);
}