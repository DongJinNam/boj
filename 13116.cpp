#include <stdio.h>

int main() {
	int tc, A, B;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &A, &B);
		while (A != B) {
			if (A < B) B /= 2;
			else A /= 2;
		}
		printf("%d\n", A * 10);
	}
	return 0;
}