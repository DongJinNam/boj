#include <stdio.h>

unsigned long long dp[91];

int main() {
	int N;
	int i, j, k;
	scanf("%d", &N);
	dp[1] = 1;
	dp[2] = 1;
	for (i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%llu\n", dp[N]);
	return 0;
}