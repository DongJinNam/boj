#include <stdio.h>

int main() {
	int N;
	int i,j;
	scanf("%d", &N);
	for (i = 1; i < N + 1; i++) {
		for (j = 1; j < 2 * N; j++) {
			if (i == 1 || i == N) {
				if (N - i + 1 <= j && j <= N + i - 1) printf("*");				
				else if (j < N - i + 1) printf(" ");
			}
			else {
				if (N - i + 1 == j || j == N + i - 1) printf("*");
				if (j < N - i + 1 || (j > N - i + 1 && j < N + i - 1)) printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}