#include <stdio.h>

unsigned long long dp[1001];

int main() {
	int N;
	int i, j, k;
	scanf("%d", &N);
	dp[1] = 1;
	dp[2] = 2;
	// (a+b) % c = a % c + b % c;
	for (i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}
	printf("%llu\n", dp[N]);
	return 0;
}