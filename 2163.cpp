#include <iostream>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	std::vector<std::vector<int>> dp(301, std::vector<int>(301, 0));
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dp[i][1] = i - 1;
	}
	for (int i = 1; i <= m; i++) {
		dp[1][i] = i - 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (i % 2 == 0) {
				dp[i][j] = 1 + 2 * dp[i / 2][j];
			}
			else if (j % 2 == 0) {
				dp[i][j] = 1 + 2 * dp[i][j / 2];
			}
			else {
				dp[i][j] = 1 + dp[i / 2][j] + dp[i - (i / 2)][j];
			}
		}
	}
	cout << dp[n][m] << "\n";
	return 0;
}