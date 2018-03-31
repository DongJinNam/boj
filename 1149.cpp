#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000001

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n;

	cin >> n;

	std::vector<std::vector<int>> dp(n, std::vector<int>(3, MAX));
	std::vector<std::vector<int>> paintArr(n, std::vector<int>(3, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> paintArr[i][j];
		}
	}

	dp[0][0] = paintArr[0][0];
	dp[0][1] = paintArr[0][1];
	dp[0][2] = paintArr[0][2];

	// dynamic programming
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int ans1 = dp[i - 1][(j + 1) % 3] + paintArr[i][j];
			int ans2 = dp[i - 1][(j + 2) % 3] + paintArr[i][j];
			int ans3 = ans1 < ans2 ? ans1 : ans2;
			dp[i][j] = ans3 < dp[i][j] ? ans3 : dp[i][j];
		}
	}

	int min = MAX;
	for (int i = 0; i < 3; i++) {
		min = dp[n - 1][i] < min ? dp[n - 1][i] : min;
	}
	cout << min << "\n";
	return 0;
}