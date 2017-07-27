#include <stdio.h>

const int limit = 1000000;
const int len = limit / 10 * 15;

long long dp[len];

int main() {
	long long N;
	scanf("%lld", &N);
	dp[0] = 0;
	dp[1] = 1;
	// 피보나치 DP로 풀기 (다만 N이 10^18 제곱까지 간다)
	// 피사노 주기
	// 규칙성 찾기. 0~15 간격으로 피보나치 값을 3으로 나눈 나머지를 구할 때 패턴이 반복된다.
	for (int i = 2; i < len; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= limit;
	}
	printf("%lld\n", dp[N % len]);
	return 0;
}