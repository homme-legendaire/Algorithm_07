#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE {
	char left, right;
}NODE;
NODE tree[26];
void preorder(char root) {
	if (root == '.') return;
	printf("%c", root);
	preorder(tree[root].left);
	preorder(tree[root].right);
}
void inorder(char root) {
	if (root == '.') return;
	inorder(tree[root].left);
	printf("%c", root);
	inorder(tree[root].right);
}
void postorder(char root) {
	if (root == '.') return;
	postorder(tree[root].left);
	postorder(tree[root].right);
	printf("%c", root);
}
int main() {
	int N;
	char x, y, z;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%c %c %c", &x, &y, &z);
		getchar();
		tree[x].left = y;
		tree[x].right = z;
	}
	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
}