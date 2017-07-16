#include <stdio.h>

#define MAX 100001

int dp[MAX];

int main() { // 제곱합 구하기 문제(dp)
	int N;
	int i, j;

	scanf("%d", &N);
	for (i = 1; i*i <= N; i++) 
		dp[i*i] = 1;	
	for (i = 2; i <= N; i++) {
		if (dp[i] == 0) dp[i] = dp[i - 1] + 1;
		for (j = 1; j*j <= i; j++) {
			dp[i] = dp[i - j*j] + 1 < dp[i] ? dp[i - j*j] + 1 : dp[i];
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}