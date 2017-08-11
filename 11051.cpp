#include <iostream>

using namespace std;

int dp[1001][1001];

int main() {
	std::ios::sync_with_stdio(false);
	int N, K;
	int i, j;
	int ans = 1;
	int above = 1, below = 1;
	// 이항계수 문제 2
	cin >> N >> K;
	K = (N - K) < K ? (N - K) : K;

	dp[0][1] = 1;
	for (j = 2; j <= N; j++) {
		i = 0;
		dp[i][j] = 1;
		for (i = 1; i < j; i++) {
			if (i == (j - 1)) dp[i][j] = j;
			else {
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] += dp[i][j - 1];
			}
			dp[i][j] %= 10007;
		}
	}
	cout << dp[K][N];
	return 0;
}