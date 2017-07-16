#include <stdio.h>

int main() {
	int N;
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 1; j < (N << 1); j++) {
			if (N - i == j || N + i == j) printf("*");
			if (j < N - i) printf(" ");
			if (N - i < j && j < N + i) printf(" ");
		}
		printf("\n");
	}
	return 0;
}