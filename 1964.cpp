#include <stdio.h>
#include <vector>

int main() {
	long long N;
	scanf("%lld", &N);

	std::vector<int> dp(N+1); // memory 초과 주의

	if (N <= 1) printf("5\n");
	else {
		dp[1] = 5;		
		long long start = 4;
		long long term;
		for (long long i = 2; i <= N; i++) {			
			term = start + 3 * (i - 1);
			dp[i] += (dp[i - 1] + term);
			dp[i] %= 45678;
		}
		printf("%d\n", dp[N]);
	}
	return 0;
}