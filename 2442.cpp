#include <stdio.h>

int main() {
	int N;
	int i,j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 1; j < 2 * N; j++) {
			if (N - i <= j && j <= N + i)
				printf("*");
			else if (j < N - i)
				printf(" ");
			else
				break;
		}
		printf("\n");
	}
	return 0;
}