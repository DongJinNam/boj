#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001][3];

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	int i, j;
	int ans;
	cin >> N;
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	for (i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][0] %= 9901;
		dp[i][1] %= 9901;
		dp[i][2] %= 9901;
	}
	ans = (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
	cout << ans;
	return 0;
}