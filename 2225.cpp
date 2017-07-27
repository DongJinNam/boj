#include <stdio.h>
#include <string.h>

#define MAX 201
#define LIMIT 1000000000

long long dp[MAX][MAX];

int main() {

	int N, K;
	int i, j, k;

	scanf("%d %d", &N, &K);

	dp[0][0] = 1LL;
	// using dynamic programming
	for (i = 1; i <= K; i++) {
		for (j = 0; j <= N; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j > 0)
				dp[i][j] += dp[i][j - 1];
			dp[i][j] %= LIMIT;
		}
	}
	printf("%lld\n", dp[K][N]);
	return 0;
}