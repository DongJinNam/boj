#include <stdio.h>

using namespace std;

typedef long long ll;

ll dp[33334];

// 걷다보니 신천역 삼 (자리 개수가 주어지면 0,1,2로 만들 수 있는 3의 배수 개수 구하기) (Large)
int main() {
	int i, j;
	int N;
	scanf("%d", &N);
	dp[1] = 0;
	dp[2] = 2;
	for (i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] * 3;
		dp[i] %= 1000000009;
	}
	printf("%lld\n", dp[N]);
	return 0;
}