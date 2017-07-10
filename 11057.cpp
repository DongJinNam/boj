#include <stdio.h>

#define MAX 10007 // 나눌 나머지

unsigned long long dp[1001][10]; // 행 : 자리수가 N일 때, 열 : 마지막 자리수. dp[N][M] N자리수를 가지고 마지막자리수가 M인 오르막수의 개수
unsigned long long sum[1001][10]; // dp[N][M] N자리수를 가지고 마지막 자리가 0 ~ M까지 오르막수 개수 총합

int main() {
	int size;
	int i, j, k;
	unsigned long long result = 0;
	scanf("%d", &size);
	sum[1][0] = 1;
	dp[1][0] = 1;
	for (i = 1; i < 10; i++) {
		dp[1][i] = 1; // 한자리수 일 때는 모두 1로 초기화 (0 제외)		
		sum[1][i] += (sum[1][i - 1] + dp[1][i]);
	}
	for (i = 2; i <= size; i++) {
		sum[i][0] += (sum[i - 1][0] % MAX);
		dp[i][0] = (dp[i - 1][0] % MAX);
		for (j = 1; j < 10; j++) {
			dp[i][j] = (sum[i - 1][j] % MAX);
			sum[i][j] = ((sum[i][j - 1] + dp[i][j]) % MAX);
		}
	}
	printf("%llu\n", sum[size][9]);
	return 0;
}