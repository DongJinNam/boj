#include <stdio.h>
#include <vector>

int dp[10001];

int main() {

	int N, sum;
	scanf("%d", &N);

	dp[1] = 1;
	sum = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = 1;

		std::vector<int> arr;
		for (int j = 2; j*j <= i; j++) {
			if (i % j == 0) arr.push_back(j);
		}
		dp[i] += arr.size();
		sum += dp[i];
	}
	printf("%d\n", sum);
	return 0;
}