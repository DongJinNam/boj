#include <stdio.h>

int dp[31];

int main() {
	// 타일 채우기
	int N;
	int i, j;
	scanf("%d", &N);
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	for (i = 4; i <= N; i+=2) {
		dp[i] = 3 * dp[i - 2];
		for (j = 4; j <= i; j+=2) {
			dp[i] += 2 * dp[i - j];
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}