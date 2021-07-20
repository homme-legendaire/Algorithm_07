#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int x, y, w, h, a = 0, b = 0;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	a = w - x;
	b = h - y;
	if (a > x) a = x;
	if (b > y) b = y;

	if (a > b) printf("%d", b);
	else printf("%d", a);
	return 0;
}