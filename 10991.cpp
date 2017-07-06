#include <stdio.h>

int main() {
	int N;
	int i,j;
	scanf("%d", &N);
	for (i = 1; i < N + 1; i++) {
		bool bSelect = true;
		for (j = 1; j < 2 * N; j++) {
			if (N - i + 1 <= j && j <= N + i - 1) {
				if (bSelect) printf("*");
				else printf(" ");
				bSelect = bSelect == true ? false : true;
			}
			else if (j < N - i + 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}