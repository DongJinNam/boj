#include <stdio.h>

long long dp[91];

int main() {
	int N;
	scanf("%d", &N);
	dp[0] = 0;
	dp[1] = 1;
	// �Ǻ���ġ DP�� Ǯ��
	for (int i = 2; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	printf("%lld\n", dp[N]);
	return 0;
}