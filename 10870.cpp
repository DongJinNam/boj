#include <stdio.h>

typedef long long ll;

ll dp[21];

int main() {
	int n, i, j;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 1;
	for (i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld\n", dp[n]);
	return 0;
}