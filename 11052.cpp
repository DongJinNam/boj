#include <stdio.h>

int dp[1001]; // dp[i] : i개를 팔 때 얻을 수 있는 최대이익
int sel[1001]; // i개 팔 때의 표준 가격

int main() {
	int N;
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &sel[i]); // 입력받음

	dp[1] = sel[1];
	for (i = 2; i <= N; i++) { // dynamic programming
		dp[i] = sel[i];
		for (j = i - 1; j >= (i-1) / 2; j--) {
			dp[i] = (dp[i - j] + dp[j]) > dp[i] ? (dp[i - j] + dp[j]) : dp[i];
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}