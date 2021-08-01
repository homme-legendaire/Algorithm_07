#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int T;
	char str[51];
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int cnt = 0;
		scanf("%s", str);
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == '(') cnt++;
			if (str[j] == ')') cnt--;
			if (cnt < 0) break;
		}
		if (cnt == 0) printf("YES\n");
		else printf("NO\n");
	}
}