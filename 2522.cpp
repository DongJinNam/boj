#include <stdio.h>

int main() {
	int N;
	int i,j;
	scanf("%d", &N);
	for (i = 1; i < N + 1; i++) {
		for (j = 1; j < N + 1; j++) {
			if (j >= N + 1 - i) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	for (i = N - 1; i > 0; i--) {
		for (j = 1; j < N + 1; j++) {
			if (j >= N + 1 - i) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}