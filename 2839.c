#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int A, B, V, up = 0, cnt = 0;
	scanf("%d %d %d", &A, &B, &V);
	if ((V - B) % (A - B) == 0) cnt = (V - B) / (A - B);
	else cnt = (V - B) / (A - B) + 1;
	printf("%d", cnt);
}