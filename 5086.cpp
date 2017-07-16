#include <stdio.h>

int main() {
	int N, M;	
	while (1) {
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) break;
		if (N < M) {
			// 배수
			if (M % N == 0) printf("factor\n");
			else printf("neither\n");
		}
		else {
			// 약수
			if (N % M == 0) printf("multiple\n");
			else printf("neither\n");
		}
	}
	return 0;
}