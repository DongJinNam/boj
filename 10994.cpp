#include <stdio.h>

int main() {
	// *********
	// *        *
	// * ***** *
	// * *    * *
	// * * * * *
	// 위와 같은 별찍기.
	int N, i, j;
	scanf("%d", &N);
	if (N == 1) {
		printf("*");
		return 0;
	}	
	for (i = (N - 1) << 1; i > 0; i--) {
		for (j = 1; j <= ((N - 1) << 2) + 1; j++) {
			if (j == 1 || j == ((N - 1) << 2) + 1) printf("*");
			else {
				if (i % 2 == 0) {
					if (((N - 1) << 1) + 1 - i  <= j && j <= ((N - 1) << 1) + 1 + i) printf("*");
					else if (j % 2 == 1) printf("*");
					else printf(" ");
				}
				else {
					if (j % 2 == 1 && (j < ((N- 1) << 1) + 1 - i || j > ((N - 1) << 1) + 1 + i)) printf("*");
					else printf(" ");
				}
			}
		}
		printf("\n");
	}
	for (j = 1; j <= ((N - 1) << 2) + 1; j++) {
		if (j % 2 == 1) printf("*");
		else printf(" ");
	}
	printf("\n");
	for (i = 1; i <= (N - 1) << 1; i++) {
		for (j = 1; j <= ((N - 1) << 2) + 1; j++) {
			if (j == 1 || j == ((N - 1) << 2) + 1) printf("*");
			else {
				if (i % 2 == 0) {
					if (((N - 1) << 1) + 1 - i <= j && j <= ((N - 1) << 1) + 1 + i) printf("*");
					else if (j % 2 == 1) printf("*");
					else printf(" ");
				}
				else {
					if (j % 2 == 1 && (j < ((N - 1) << 1) + 1 - i || j >((N - 1) << 1) + 1 + i)) printf("*");
					else printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}