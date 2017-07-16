#include <stdio.h>

int main() {
	int N;
	int i, j;
	scanf("%d", &N);

	if (N == 1) printf("*\n");
	else {
		for (i = 0; i < (N << 1); i++) {
			for (j = 0; j < N; j++) {
				if (i % 2 == 0) {
					if (j % 2 == 0) printf("*");
					else printf(" ");
				}
				else {
					if (j % 2 == 0) printf(" ");
					else printf("*");
				}
			}
			printf("\n");
		}
	}
	return 0;
}