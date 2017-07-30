#include <stdio.h>

int main() {

	int N;
	int i, j, k;
	int count = 0;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {		
		int total = N - i;
		for (j = i; j <= total; j++) {
			int p1 = j;
			int p2 = total - j;
			if (p1 >= i + 2 && p2 > 0 && p2 % 2 == 0) count++;
		}
	}
	printf("%d\n", count);
	return 0;
}