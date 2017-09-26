#include <stdio.h>

typedef long long ll;

ll dp[1000001];

int main() {

	int n, i, j;
	scanf("%d", &n);
	dp[1] = 0;
	dp[2] = 1;
	for (i = 3; i <= n; i++) {
		dp[i] = (i - 1) * dp[i - 1] + (i - 1) * dp[i - 2];
		dp[i] %= 1000000000;
	}
	printf("%lld\n", dp[n]);
	return 0;
}