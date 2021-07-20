#pragma warning (disable:4996)
#include <stdio.h>
int main() {
	int a, b, c, A, B, C;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) break;
		A = a * a;
		B = b * b;
		C = c * c;
		if (A > B && A > C) {
			if (A == B + C) printf("right\n");
			else printf("wrong\n");
		}
		else if (B > A && B > C) {
			if (B == A + C) printf("right\n");
			else printf("wrong\n");
		}
		else if (C > A && C > B) {
			if (C == B + A) printf("right\n");
			else printf("wrong\n");
		}
	}
	return 0;
}