#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int N, i = 666, cnt = 0, count = 0;
	scanf("%d", &N);
	while (count < N) {
		int j = i;
		while (j != 0) {
			if (j % 10 == 6) {
				cnt++;
				if (cnt == 3) {
					count++;
					break;
				}
			}
			else cnt = 0;
			j /= 10;
		}
		i++;
	}
	printf("%d\n", i - 1);
}