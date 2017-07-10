#include <stdio.h>

#define MAX 1000000000

unsigned long long dp[101][10]; // 행 : 자리수가 N일 때, 열 : 마지막 자리수. dp[N][M] N자리수를 가지고 마지막자리수가 M인 계단수의 개수

int main() {
	int size;
	int i, j;
	unsigned long long result = 0;
	scanf("%d", &size);
	dp[1][0] = 0;
	for (i = 1; i < 10; i++)
		dp[1][i] = 1; // 한자리수 일 때는 모두 1로 초기화 (0 제외)
	for (i = 2; i <= size; i++) {
		for (j = 0; j < 10; j++) {
			if (j > 0)
				dp[i][j] += (dp[i - 1][j - 1] % MAX);
			if (j < 9)
				dp[i][j] += (dp[i - 1][j + 1] % MAX);
		}
	}	
	for (i = 0; i < 10; i++)
		result += dp[size][i];
	result %= MAX;
	printf("%llu\n", result);
	return 0;
}