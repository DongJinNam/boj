#include <stdio.h>
int main() {
	int K, N, M;
	int ans;
	scanf("%d %d %d", &K, &N, &M);

	ans = K*N - M;
	if (ans >= 0) printf("%d\n", ans);
	else printf("0\n");
	return 0;
}