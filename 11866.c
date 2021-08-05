#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int x[2000];
    int n, k;
    int a = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        x[i] = i;
    }
    printf("<");
    while (n > 0) {
        a = (a + k) % n;
        if (a == 0) a = n;
        if (n == 1) {
            printf("%d>", x[1]);
        }
        else {
            printf("%d, ", x[a]);
            for (int i = a; i < n; i++) {
                x[i] = x[i + 1];
            }
            a--;
        }
        n--;
    }
}