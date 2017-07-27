#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	if (N == 1) {
		printf("*");
		return 0;
	}
	if (N % 2 == 0) {
		for (int i = 1; i < (1 << N); i++) {
			for (int j = 1; j < ((1 << N) - 1) * 2; j++) {
				if (i == 1) printf("*");
			}
			printf("\n");
		}
	}
	else {
		for (int i = 1; i < (1 << N); i++) {
			for (int j = 1; j < ((1 << N) - 1) * 2; j++) {
				if (i == (1 << N) - 1) printf("*");
			}
			printf("\n");
		}
	}

	return 0;
}