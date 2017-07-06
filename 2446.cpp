#include <stdio.h>

int main() {
	int N;
	int i,j;
	scanf("%d", &N);
	for (i = 1; i < N + 1; i++) {
		for (j = 1; j < 2 * N; j++) {			
			if (i <= j && j <= 2 * N - i) printf("*");
			else if (j < i) printf(" ");
		}
		printf("\n");
	}
	for (i = N - 1; i > 0; i--) {
		for (j = 1; j < 2 * N; j++) {
			if (i <= j && j <= 2 * N - i) printf("*");
			else if (j < i) printf(" ");
		}
		printf("\n");
	}
	return 0;
}