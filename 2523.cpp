#include <stdio.h>

int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i < 2 * n; i++) {
		if (i <= n) {
			for (j = 1; j <= i; j++)
				printf("*");
		}
		else {
			for (j = 1; j <= 2 * n - i; j++)
				printf("*");
		}
		printf("\n");
	}
	return 0;
}